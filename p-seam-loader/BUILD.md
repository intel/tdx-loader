<!--******************************************************************************
* Copyright (C) 2023 Intel Corporation                                        
*                                                                             
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"),       
* to deal in the Software without restriction, including without limitation   
* the rights to use, copy, modify, merge, publish, distribute, sublicense,    
* and/or sell copies of the Software, and to permit persons to whom           
* the Software is furnished to do so, subject to the following conditions:    
*                                                                             
* The above copyright notice and this permission notice shall be included     
* in all copies or substantial portions of the Software.                      
*                                                                             
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS     
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL    
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES           
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,    
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE          
* OR OTHER DEALINGS IN THE SOFTWARE.                                          
*                                                                             
* SPDX-License-Identifier: MIT
******************************************************************************/-->

- [Build Environment](#build-environment)
- [Docker Container Build Instructions](#docker-container-build-instructions)
- [How to Build](#how-to-build)
- [Environment Dependencies](#environment-dependencies)
- [Make Targets](#make-targets)

# Build Environment

This repo contains a docker file for your convenience.  
SW prerequisites could be found in the [Dockerfile](Dockerfile) (prerequisites could be installed also manually).  
Please note that the P-SEAMLDR module isn't part of the docker image and the user must build it according to the [instructions below](#how-to-build).  
The docker image is identical across all P-SEAMLDR versions, there is no need to rebuild it.

## Docker Container Build Instructions:

1. Clone/download the desired TDX loader version ([Releases](https://github.com/intel/tdx-loader/releases)).  
2. Build the Docker image from the P-SEAMLDR [Dockerfile](Dockerfile) (located inside the relevant repo P-SEAMLDR folder):
```docker build . -t tdx-loader-docker```

3. Run the Docker container from the local created docker image:  
```docker run -ti --rm --net=host -v "$PWD":$HOME/tdx-loader -w $HOME/tdx-loader tdx-loader-docker bash```  
NOTE: In order to run on Windows, replace the mount line with: -v "%CD%":$HOME/tdx-loader

# How to Build

P-SEAMLDR project root is located in p-seam-loader folder, and should be built from there.

## Environment dependencies

-	[IPP 2021.4](https://github.com/intel/ipp-crypto/releases/tag/ippcp_2021.4)

1) IPP can be automatically built by the P-SEAM-Loader makefile.
	-	IPP sources needs to be placed under ./libs/ipp/ipp-crypto-ippcp_2021.4 folder.
	-	Tools that are required to build IPP crypto lib described in the following [link](https://github.com/intel/ipp-crypto/blob/ipp-crypto_2021_4/BUILD.md)

2) It can also be built separately with the following flags:
```bash
	CC=clang CXX=clang++ cmake CMakeLists.txt -B_build -DARCH=intel64 -DMERGED_BLD:BOOL=off -DPLATFORM_LIST="y8"
	cd _build
	make ippcp_s_y8
```

3) For more details about IPP targets and IPP library file placement refer src_defs.mk

## Make targets
The binary generation contains the date and the build num of the created binary. 

The date and the build num can be extracted by calling seamldr.info (SEAMCALL leaf 0x8000000000000000) on production SEAM-Loader, and taking the values of "build_date" and "build_num" fields in SEAMLDRINFO_STRUCT.

1) In order to reproduce the exact binary, it is required to include the origin date, and the build number:

```bash
make RELEASE=1 PSEAMLDR_BUILD_DATE=20240130 PSEAMLDR_BUILD_NUM=212
```

Build output files (pseamldr.so and pseamldr.so.consts) for NP-SEAM-Loader build will be produced in ./bin/release folder.
	
2) Clean everything:
 
```bash
make clean
```

3) Clean everything including the IPP:

```bash
make cleanall
```
