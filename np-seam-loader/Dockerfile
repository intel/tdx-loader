# escape=`
FROM mcr.microsoft.com/dotnet/framework/runtime:4.8-windowsservercore-ltsc2019 AS base

# Install chocolatey, python3, git and make
ADD https://community.chocolatey.org/api/v2/package/chocolatey/2.3.0 chocolatey.2.3.0.nupkg
ADD https://community.chocolatey.org/install.ps1 install.ps1
RUN powershell -command `
    Set-ExecutionPolicy Bypass -Scope Process -Force; `
    [Net.WebRequest]::DefaultWebProxy.Credentials = [Net.CredentialCache]::DefaultCredentials; `
    .\Install.ps1 -ChocolateyDownloadUrl chocolatey.2.3.0.nupkg; `
    Remove-Item chocolatey.2.3.0.nupkg; `
    Remove-Item install.ps1 `
    && SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin" `
    && choco install python3 --version=3.9.6 -y `
    && py -m pip install --upgrade pip `
    && py -m pip uninstall --yes setuptools `
    && py -m pip install setuptools>=65.5.1 `
    && choco install git -y `
    && choco install make -y

# Restore the default Windows shell for correct batch processing.
SHELL ["cmd", "/S", "/C"]

# Install Visual Studio 2019 + 2015 build tools
Add https://aka.ms/vs/16/release/vs_professional.exe C:\vs_professional.exe
RUN start /w vs_professional.exe --quiet --wait --norestart --nocache `
        --add Microsoft.VisualStudio.Workload.ManagedDesktopBuildTools `
        --add Microsoft.VisualStudio.Workload.VCTools `
        --add Microsoft.VisualStudio.Workload.MSBuildTools `
        --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 `
        --add Microsoft.VisualStudio.Component.Windows10SDK.18362 `
        --add Microsoft.VisualStudio.Workload.AzureBuildTools `
        --add Microsoft.VisualStudio.Workload.NativeDesktop `
        --add Microsoft.VisualStudio.Component.VC.140 `
        --remove Microsoft.VisualStudio.Component.Windows10SDK.10240 `
        --remove Microsoft.VisualStudio.Component.Windows10SDK.10586 `
        --remove Microsoft.VisualStudio.Component.Windows10SDK.14393 `
        --remove Microsoft.VisualStudio.Component.Windows81SDK `
        || IF "%ERRORLEVEL%"=="3010" EXIT 0 `
    `
    # Cleanup
    && del /q vs_professional.exe
