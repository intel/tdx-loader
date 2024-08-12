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

# How to Build
List the steps to build the binary and requirements from build environment

- [Software Requirements](#software-requirements)
- [Make targets](#make-targets)
- [Environment dependencies](#environment-dependencies)
- [Binary file date](#binary-file-date)


# Build Environment

This repo contains a docker file for your convenience.  
SW prerequisites could be found in the [Dockerfile](Dockerfile) (prerequisites could be installed also manually).  
Please note that the NP-SEAMLDR module isn't part of the docker image and the user must build it according to the [instructions below](#how-to-build).  
The docker image is identical across all NP-SEAMLDR versions, there is no need to rebuild it.

## Docker Container Build Instructions:

1. CD into the folder that already contains the cloned tdx loader including the compiled P-SEAMLDR bins [here](../p-seam-loader/BUILD.md)

2. Build the Docker image from the [Dockerfile](Dockerfile) (located inside the relevant repo NP-SEAMLDR folder): 
```cd np-seam-loader```
```docker build -m 8GB . -t tdx-loader-docker```

3. Run the Docker container from the local created docker image: 
```docker run -ti --rm -v "%CD%":c:\tdx-loader -w c:\tdx-loader tdx-loader-docker cmd```

# How to Build
## Make targets
Note: the binary generation contains the date of the created binary. Therefore, the build date must be provided to the make target in order to get the same binary as the production one.

1) Build P-SEAM-Loader as described [here](../p-seam-loader/BUILD.md) with the production SEAM-Loader build date. The P-SEAM-Loader build instructions describe how to extract its build date.
2) Copy the pseamldr.so and pseamldr.so.consts from the P-SEAMLDR which in the case of Docker containers,
        from: <tdx-loader repo location>/p-seam-loader/bin/release dir 
        to: <tdx-loader repo location>\np-seam-loader\seamldr_src\Projects\Server\Emr\Seamldr

3) Open a command prompt in the above project's folder and the Build the project, using the build date in YYYYMMDD format: 

```
make -f ..\project.mak npseamldr release <rev=yyyymmdd>
```
	
The ACM binary will be built in the output folder:  output\ENG_TR_O1
The ACM binaries are the 3 .bin files, each for each signature type: debug, NPW and production.

4) Clean everything:
 
```
make -f ..\project.mak npseamldr CLEANALL
```
