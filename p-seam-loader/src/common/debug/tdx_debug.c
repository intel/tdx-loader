// Copyright (C) 2023 Intel Corporation                                          
//                                                                               
// Permission is hereby granted, free of charge, to any person obtaining a copy  
// of this software and associated documentation files (the "Software"),         
// to deal in the Software without restriction, including without limitation     
// the rights to use, copy, modify, merge, publish, distribute, sublicense,      
// and/or sell copies of the Software, and to permit persons to whom             
// the Software is furnished to do so, subject to the following conditions:      
//                                                                               
// The above copyright notice and this permission notice shall be included       
// in all copies or substantial portions of the Software.                        
//                                                                               
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS       
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL      
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES             
// OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE            
// OR OTHER DEALINGS IN THE SOFTWARE.                                            
//                                                                               
// SPDX-License-Identifier: MIT
/**
 * @file tdx_debug.c
 * @brief Debug facilities
 */

#include "tdx_debug.h"
#include "accessors/data_accessors.h"
#include "memory_handlers/keyhole_manager.h"
#include "helpers/helpers.h"

#ifdef DEBUGFEATURE_TDX_DBG_TRACE
void init_debug_control(void)
{
    tdx_outport80(0xFC00);

    debug_control_t* debug_data = &(get_pseamldr_data()->debug_control);

    debug_data->print_target = TARGET_SERIAL_PORT;

    init_com_port(debug_data);

    debug_data->trace_buffer = get_pseamldr_data()->trace_buffer;
    debug_data->buffer_writer_pos = 0;
    debug_data->buffer_reader_pos = 0;
    debug_data->emergency_buffer = 0;
    debug_data->msg_num = 0;
    debug_data->print_severity = 0;

    debug_data->initialized = true;

    tdx_outport80(0xFC02);
}

_STATIC_INLINE_ uint32_t dump_message_to_vmm_memory(char* msg_buf_ptr, uint64_t hpa, uint32_t len)
{
    uint32_t vmm_buf_pos = 0;
    char* vmm_buf_ptr = map_pa((void*)hpa, TDX_RANGE_RW);

    for (uint32_t i = 0; msg_buf_ptr[i] != 0 && i < len; i++)
    {
        if ((hpa + vmm_buf_pos) % PAGE_SIZE_IN_BYTES == 0)
        {
            free_la(vmm_buf_ptr);
            vmm_buf_ptr = map_pa((void*)(hpa + vmm_buf_pos), TDX_RANGE_RW);
        }

        vmm_buf_ptr[i] = msg_buf_ptr[i];
        vmm_buf_pos++;
    }

    free_la(vmm_buf_ptr);

    return vmm_buf_pos;
}

static inline uint32_t count_messages(debug_control_t* p_ctl)
{
    uint32_t reader_pos = p_ctl->buffer_reader_pos;
    uint32_t writer_pos = p_ctl->buffer_writer_pos;

    uint32_t count = 0;

    while (reader_pos != writer_pos)
    {
        reader_pos++;
        count++;

        if (reader_pos >= TRACE_BUFFER_SIZE)
        {
            reader_pos = 0;
        }
    }

    return count;
}

static inline uint32_t get_advanced_reader_pos(uint32_t current_pos, uint32_t advance_num)
{
    uint32_t reader_pos = current_pos;

    for (uint32_t i = 0; i < advance_num; i++)
    {
        reader_pos++;

        if (reader_pos >= TRACE_BUFFER_SIZE)
        {
            reader_pos = 0;
        }
    }

    return reader_pos;
}

uint32_t dump_print_buffer_to_vmm_memory(uint64_t hpa, uint32_t num_of_messages_from_the_end)
{
    debug_control_t* p_ctl = &(get_pseamldr_data()->debug_control);

    uint32_t vmm_buf_pos = 0;
    uint32_t message_count = count_messages(p_ctl);

    uint32_t reader_pos = p_ctl->buffer_reader_pos;

    if ((num_of_messages_from_the_end != 0) && (message_count > num_of_messages_from_the_end))
    {
        // Advance the reader position to (message_count - num_of_messages_from_the_end)
        // To read the last num_of_messages_from_the_end number of messages
        reader_pos = get_advanced_reader_pos(reader_pos, message_count - num_of_messages_from_the_end);
    }

    while (reader_pos != p_ctl->buffer_writer_pos)
    {
        char* msg_buf_ptr = p_ctl->trace_buffer[reader_pos].message;

        vmm_buf_pos += dump_message_to_vmm_memory(msg_buf_ptr, hpa + vmm_buf_pos, MAX_PRINT_LENGTH);

        reader_pos = get_advanced_reader_pos(reader_pos, 1);
    }

    return vmm_buf_pos;
}

uint64_t td_debug_config(uint64_t leaf, uint64_t payload, uint64_t second_payload)
{
    debug_control_t* p_ctl = &(get_pseamldr_data()->debug_control);
    uint64_t retval = 0;

    if (!p_ctl->initialized)
    {
        init_debug_control();
    }

    if (leaf == 0) // Set debug print target
    {
        p_ctl->print_target = (print_target_e)payload;

        if (p_ctl->print_target == TARGET_EXTERNAL_BUFFER)
        {
            p_ctl->trace_buffer = (debug_message_t*)second_payload;
        }
        else if (p_ctl->print_target == TARGET_TRACE_BUFFER)
        {
            p_ctl->trace_buffer = get_pseamldr_data()->trace_buffer;
        }

        // Reset all counters
        p_ctl->buffer_writer_pos = 0;
        p_ctl->buffer_reader_pos = 0;
        p_ctl->msg_num = 0;
    }
    else if (leaf == 1) // Dump internal buffer to given VMM buffer
    {
        retval = dump_print_buffer_to_vmm_memory(payload, (uint32_t)second_payload);
    }
    else if (leaf == 2) // Set an emergency buffer to be filled with the trace dump on ud2
    {
        p_ctl->emergency_buffer = payload;
    }
    else if (leaf == 3)
    {
        p_ctl->print_severity = payload;
    }

    return retval;
}

static void print_to_buffer(debug_control_t* p_ctl, char* print_buf, uint32_t print_len)
{
    debug_message_t* debug_message = &p_ctl->trace_buffer[p_ctl->buffer_writer_pos];

    if (p_ctl->print_target == TARGET_EXTERNAL_BUFFER)
    {
        debug_message = map_pa(debug_message, true);
    }

    // Copying the message
    for (uint32_t i = 0; print_buf[i] != 0 && i < print_len; ++i)
    {
        debug_message->message[i] = print_buf[i];
    }

    // Filling with NULLs till the end
    for (uint32_t i = print_len; i < MAX_PRINT_LENGTH; i++)
    {
        debug_message->message[i] = '\0';
    }

    // Last character will be newline for easier reading of the buffer
    debug_message->message[MAX_PRINT_LENGTH - 1] = '\n';

    if (p_ctl->print_target == TARGET_EXTERNAL_BUFFER)
    {
        free_la(debug_message);
    }

    p_ctl->buffer_writer_pos++;

    if (p_ctl->buffer_writer_pos >= TRACE_BUFFER_SIZE)
    {
        p_ctl->buffer_writer_pos = 0;
    }

    if (p_ctl->buffer_reader_pos == p_ctl->buffer_writer_pos)
    {
        p_ctl->buffer_reader_pos++;
        if (p_ctl->buffer_writer_pos >= TRACE_BUFFER_SIZE)
        {
            p_ctl->buffer_reader_pos = 0;
        }
    }
}

static void print_to_serial(debug_control_t* p_ctl, char* print_buf, uint32_t print_len)
{
    log_to_com_port(print_buf,
                    print_len,
                    p_ctl->com_port_addr);
}

static void common_printf(const char* format, va_list args)
{
    uint64_t thread_id;
    uint32_t msg_id = 0;
    uint32_t print_len = 0;
    char print_buf[MAX_PRINT_LENGTH];

    debug_control_t* p_ctl = &(get_pseamldr_data()->debug_control);

    thread_id = get_current_lpid();
    msg_id = get_pseamldr_data()->local_dbg_msg_num++;

    // Put a message header (message num and thread num)
    print_len = (uint32_t)debug_sprintf_s(print_buf, sizeof(print_buf), "[%d][T%d]:", msg_id, thread_id);
    print_len += (uint32_t)(_sprintf_s(print_buf + print_len, sizeof(print_buf) - print_len, format, args));

    if ((p_ctl->print_target == TARGET_TRACE_BUFFER) || (p_ctl->print_target == TARGET_EXTERNAL_BUFFER))
    {
        print_to_buffer(p_ctl, print_buf, print_len);
    }
    else    // serial port
    {
        print_to_serial(p_ctl, print_buf, print_len);
    }
}

void tdx_print(uint64_t severity, const char* format, ... )
{
    debug_control_t* p_ctl = &(get_pseamldr_data()->debug_control);
    // The reason why we call init_debug_control here and not in some module init API (Like TDSYSINIT)
    // is because the API will go through the dispatcher first, and there we will have some prints.
    // The assumption is that the first call to module init API will be done on a single thread only,
    // so no race on initialization will occur.
    if (!p_ctl->initialized)
    {
        init_debug_control();
    }

    if (severity < p_ctl->print_severity)
    {
        return;
    }

    va_list args;

    va_start(args, format);
    common_printf(format, args);
    va_end(args);
}


#endif

