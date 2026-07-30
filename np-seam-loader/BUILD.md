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
- [Build Environment](#build-environment)
  - [Docker Image Variants](#docker-image-variants)
  - [Option 1: Online Installation (Dockerfile.online.public)](#option-1-online-installation-dockerfileonlinepublic)
  - [Option 2: Offline Installation (Dockerfile.local.public)](#option-2-offline-installation-dockerfilelocalpublic)
  - [Docker Container Build Instructions](#docker-container-build-instructions)
- [How to Build](#how-to-build-1)
  - [Make targets](#make-targets)
- [Environment dependencies](#environment-dependencies)
- [Troubleshooting](#troubleshooting)
- [Binary file date](#binary-file-date)

# Build Environment

This repo contains Dockerfiles for your convenience.
SW prerequisites can be found in the Dockerfiles (prerequisites can also be installed manually).
Please note that the NP-SEAMLDR module isn't part of the docker image and the user must build it according to the [instructions below](#how-to-build-1).
The docker image is identical across all NP-SEAMLDR versions; there is no need to rebuild it unless the toolchain itself changes.

## Docker Image Variants

Two Dockerfile variants are provided. Both produce an equivalent image; they
differ only in the method used to install Visual Studio 2019 Build Tools.

| Dockerfile | Visual Studio installation method | Network access required during `docker build` |
|---|---|---|
| `Dockerfile.online.public` | Bootstrapper downloads packages from Microsoft at build time | Required |
| `Dockerfile.local.public` | Pre-downloaded offline layout, added via `COPY` | Not required for the Visual Studio step |

Both images are based on `mcr.microsoft.com/dotnet/framework/runtime:4.8-windowsservercore-ltsc2022`
and require **Windows containers mode** in Docker Desktop (this is a Windows
Server Core based image — it will not run in Linux-container mode).

### Image Contents

| Component | Installation method |
|---|---|
| Visual Studio 2019 Build Tools (ManagedDesktopBuildTools, VCTools, MSBuildTools, AzureBuildTools, NativeDesktop workloads; VC.Tools.x86.x64, VC.140 components) | Bootstrapper (online variant) or offline layout (local variant) |
| Python 3 | Chocolatey |
| Git | Chocolatey |
| Make | Chocolatey |
| pip, setuptools (pinned `>=65.5.1`) | pip |

Default installation path: `C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional`

- Compiler: `...\2019\Professional\VC\Tools\MSVC\<version>\bin\Hostx64\x64\cl.exe`
- Build environment script: `...\2019\Professional\VC\Auxiliary\Build\vcvars64.bat`

## Option 1: Online Installation (`Dockerfile.online.public`)

The Visual Studio bootstrapper (`vs_professional.exe`) downloads all required
packages from Microsoft's servers during the image build. This is the
simplest option and requires no preparatory steps, but build duration and
reliability depend on network conditions, and it may fail with exit code
`5003` if Microsoft's download endpoints are unreachable or a proxy
interferes with the download (see [Troubleshooting](#troubleshooting)).

```powershell
docker build -m 8GB -f Dockerfile.online.public -t tdx-loader-docker .
```

### Building Behind a Corporate Proxy

```powershell
docker build -m 8GB `
    --build-arg HTTP_PROXY=http://your-proxy:port `
    --build-arg HTTPS_PROXY=http://your-proxy:port `
    --build-arg NO_PROXY="localhost,127.0.0.1" `
    -f Dockerfile.online.public -t tdx-loader-docker .
```

`HTTP_PROXY`, `HTTPS_PROXY`, and `NO_PROXY` are Docker's predefined proxy
build arguments and require no additional Dockerfile configuration. They are
injected automatically as environment variables into every `RUN` instruction,
which is sufficient for PowerShell-based tools (`Invoke-WebRequest`, `choco`,
`pip`, `git`).

Native Win32 installers, including `vs_professional.exe`, use the WinHTTP/
WinINET proxy configuration rather than environment variables. The Dockerfile
therefore also applies the supplied proxy values to the system-wide WinHTTP
configuration via `netsh winhttp`. This step has no effect if no proxy
build arguments are supplied.

## Option 2: Offline Installation (`Dockerfile.local.public`)

Recommended when the build host has no outbound internet access, when
network reliability during `docker build` is a concern, or when fully
reproducible builds are required. Visual Studio packages are downloaded once
into an offline layout directory, which is then copied into the image with
no network calls required during the build.

### Step 1: Create the Offline Layout

Run the following on a host with standard internet access. Do not run this
inside a container.

```powershell
# Download the bootstrapper. Add -Proxy http://your-proxy:port if required.
Invoke-WebRequest -Uri https://aka.ms/vs/16/release/vs_professional.exe `
    -OutFile C:\vs_professional.exe

# Create the offline layout. This downloads several gigabytes and may take
# 15-30 minutes or more.
C:\vs_professional.exe --layout C:\vs_layout `
    --add Microsoft.VisualStudio.Workload.ManagedDesktopBuildTools `
    --add Microsoft.VisualStudio.Workload.VCTools `
    --add Microsoft.VisualStudio.Workload.MSBuildTools `
    --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 `
    --add Microsoft.VisualStudio.Workload.AzureBuildTools `
    --add Microsoft.VisualStudio.Workload.NativeDesktop `
    --add Microsoft.VisualStudio.Component.VC.140 `
    --lang en-US --quiet --wait
```

> **Note:** `Microsoft.VisualStudio.Component.Windows10SDK.18362` has been
> observed to be rejected by current bootstrapper catalogs with the error
> "package is not recognized." If a Windows 10 SDK is required, specify a
> currently supported version, for example
> `Microsoft.VisualStudio.Component.Windows10SDK.19041`.

Confirm the layout completed successfully:

```powershell
Get-Content "$env:TEMP\dd_setup_*.log" -Tail 5 | Select-String "Completed 'Layout' operation"
```

### Step 2: Position the Layout

Place the resulting `vs_layout\` directory in the same directory as
`Dockerfile.local.public`, as it is required as part of the Docker build
context. If building on a different machine than the one used to create the
layout, transfer the directory accordingly (network share, archive transfer,
removable media) along with the Dockerfile.

### Step 3: Build

```powershell
docker build -m 8GB -f Dockerfile.local.public -t tdx-loader-docker .
```

### Building Behind a Corporate Proxy

A proxy is only required for the Chocolatey/Python/Git installation step; the
Visual Studio installation itself performs no network access.

```powershell
docker build -m 8GB `
    --build-arg HTTP_PROXY=http://your-proxy:port `
    --build-arg HTTPS_PROXY=http://your-proxy:port `
    --build-arg NO_PROXY="localhost,127.0.0.1" `
    -f Dockerfile.local.public -t tdx-loader-docker .
```

### Considerations

- No network dependency for the Visual Studio installation step; unaffected
  by Microsoft server availability, CRL checks, or proxy behavior during
  `docker build`.
- Produces fully reproducible builds, since the same layout yields the same
  installation every time.
- Requires a one-time layout creation step of several gigabytes prior to the
  first build.
- The layout must be recreated manually to pick up newer Visual Studio
  package versions.

## Docker Container Build Instructions

1. CD into the folder that already contains the cloned tdx loader including the compiled P-SEAMLDR bins [here](../p-seam-loader/BUILD.md)

2. Build the Docker image using one of the two Dockerfile variants described above (located inside the relevant repo NP-SEAMLDR folder):

    ```cd np-seam-loader```

    ```docker build -m 8GB -f Dockerfile.online.public -t tdx-loader-docker .```

    or, for the offline/local variant (after preparing `vs_layout\` as described in [Option 2](#option-2-offline-installation-dockerfilelocalpublic)):

    ```docker build -m 8GB -f Dockerfile.local.public -t tdx-loader-docker .```

3. Run the Docker container from the locally created docker image:

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
make -f ..\project.mak npseamldr release rev=20251106
```

Add cpu=srf if the build is for SRF.    
	
The ACM binary will be built in the output folder, according to the build type, for example:  output\ENG_TR_O1
The ACM binaries are the 3 .bin files, each for each signature type: debug, NPW and production.

4) Clean everything:
 
```
make -f ..\project.mak npseamldr CLEANALL
```

## Environment dependencies

## Troubleshooting

### Docker Desktop: "The virtual machine could not be started because a required feature is not installed."

The Hyper-V/WSL2 backend required by Docker Desktop is not configured.
Enable the required Windows features and restart:

```powershell
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Hyper-V-All -All -NoRestart
Enable-WindowsOptionalFeature -Online -FeatureName VirtualMachinePlatform -All -NoRestart
Enable-WindowsOptionalFeature -Online -FeatureName Containers -All -NoRestart
Restart-Computer
```

Windows containers specifically require Hyper-V; a WSL2-only configuration
is not sufficient.

### Visual Studio installer exits with code 5003

The cause differs depending on which Dockerfile is in use.

**Online variant:** the container cannot reach Microsoft's download
endpoints. Verify connectivity from within the container:

```powershell
docker run --rm <base-image> powershell -c "Invoke-WebRequest https://aka.ms -UseBasicParsing -Proxy $env:HTTP_PROXY"
```

If this fails, verify the proxy build arguments and confirm the container can
route to the specified proxy.

**Offline/local variant:** inspect `dd_bootstrapper_*.log` and
`dd_setup_*_errors.log`, printed to build output on failure. An error of the
form `Certificate is invalid: ...vs_installer.opc` / `InvalidCertificate`
indicates the installer attempted an online CRL/OCSP revocation check, which
timed out (commonly observed behind SSL-inspecting proxies without direct
internet access). This Dockerfile addresses the issue by pre-extracting
`vs_installer.opc` into the Visual Studio Installer directory, which causes
the bootstrapper to skip its self-update verification. If this error still
occurs, verify that `vs_layout\` was transferred completely and without
corruption.

### `setuptools>=65.5.1` produces unexpected results or a stray file named `65.5.1`

This occurs when `>` is left unquoted in a `RUN` instruction, since both
`cmd` and PowerShell interpret an unquoted `>` as output redirection. Both
Dockerfiles quote the version specifier (`"setuptools>=65.5.1"`) to prevent
this.

### `Expand-Archive : .opc is not a supported archive file format`

`Expand-Archive` requires a literal `.zip` file extension. Both Dockerfiles
use `[System.IO.Compression.ZipFile]::ExtractToDirectory()` instead, which
operates independently of file extension.

### No Visual Studio directory present after a build reports success

Insufficient error handling around the Visual Studio installer (for example,
`|| IF "%ERRORLEVEL%"=="3010" EXIT 0`) can mask genuine installation
failures. Both Dockerfiles instead invoke the installer via PowerShell's
`Start-Process -Wait -PassThru`, inspect the actual exit code, and verify the
presence of `vcvars64.bat` after installation, failing the build immediately
if Visual Studio did not install correctly.

## Binary file date
