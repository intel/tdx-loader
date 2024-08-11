# TDX loader

Secure Arbitration Mode (SEAM) is an extension to Virtual Machines Extension (VMX) architecture to define a new VMX root mode called SEAM root.
This SEAM root mode is used to host a CPU-attested module to create virtual machine (VM) guests called Trust Domains (TD).

Software that executes in SEAM root mode, defined by SEAM range registers (SEAMRR).
The SEAM range is partitioned into two sub-ranges: MODULE_RANGE and P_SEAMLDR_RANGE.

The NP-SEAMLDR ACM helps with the initialization of the SEAM range, establishes the P-SEAMLDR range, sets up the SEAM transfer VMCS structure for transfers to the Intel P-SEAMLDR module, and loads the embedded Intel P-SEAMLDR module's image into the P_SEAMLDR_RANGE

The TDX module, which provides functions to build and manage TDs, is loaded to and runs from MODULE_RANGE.
The persistent SEAM loader (P-SEAMLDR), which provides function to load and update the TDX module, runs from P_SEAMLDR_RANGE.

P-SEAMLDR is a special SEAM module, loaded into P_SEAMLDR_RANGE by NP-SEAMLDR, and invoked by VMM using the SEAMCALL instruction.
It is designed to follow the steps below to load or update an Intel TDX module into the MODULE_RANGE:

    1. Verify input parameters, including the Intel TDX module's signature structure.
    2. Load the Intel TDX module image into the MODULE_RANGE, measure it and verify the measurement matches with the signature structure.
    3. Set up all the relevant regions and SEAM transfer VMCSs for all logical processors.
    4. Record the Intel TDX module identity into CPU measurement registers and update its load status.
    5. Return to VMM using the SEAMRET instruction.

For more details, refer - https://www.intel.com/content/www/us/en/developer/tools/trust-domain-extensions/documentation.html "Intel TDX Loader Interface Specification"

# How to Build

The final build product is the NP-SEAMLDR ACM. It is built with P-SEAMLDR binary embedded into it. 
Which means that P-SEAMLDR needs to be built first, and then used (pseamldr.so and pseamldr.so.consts files) as an input to build the NP-SEAMLDR.

Follow the [build instructions](p-seam-loader/BUILD.md) of the P-SEAMLDR.
And then follow the [build instructions](np-seam-loader/BUILD.md) of the NP-SEAMLDR.
