# How to Build
List the steps to build the binary and requirements from build environment

- [Software Requirements](#software-requirements)
- [Make targets](#make-targets)
- [Environment dependencies](#environment-dependencies)
- [Binary file date](#binary-file-date)


## Software Requirements
-   Visual Studio 2015 build tools at C:\Program Files (x86)\Microsoft Visual Studio 14.0
-	Python 3
-   GNU  make


## Make targets
Note: the binary generation contains the date of the created binary. Therefore, the build date must be provided to the make target in order to get the same binary as the production one.

1) Build P-SEAM-Loader as described [here](../p-seam-loader/BUILD.md) with the production SEAM-Loader build date. The P-SEAM-Loader build instructions describe how to extract its build date.
2) Copy P-SEAM-Loader binaries - pseamldr.so and pseamldr.so.consts in the project's folder: Projects\Server\Emr\Seamldr
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

## Environment dependencies




