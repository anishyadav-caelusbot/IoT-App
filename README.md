# IoT-App
This application will simulate temperature and humidity data, send it to a specified server every 5 seconds, and allow you to start, stop, and check the status of the Senor through a simple Flutter App.

# Emulator

This application will simulate temperature and humidity data, send it to a specified server every 5 seconds, and allow you to start, stop, and check the status of the emulation through a simple console interface.

## Overview
Here's a step-by-step guide to create an emulator application in C++ that simulates an IoT device, sending temperature and humidity data to a server every 5 seconds with start, stop, and status functionalities. Following these steps, you should be able to build and run a C++ application using libcurl in VS Code on Windows.

## Setup Environment and Include Necessary Libraries

### 1. Installing MinGW-w64 Toolchain
- Download from [VS Code MinGW-w64 guide](https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites).

### 2. Install MSYS2
- Download the latest installer from the MSYS2 page or use this [direct link](https://www.msys2.org/).
- Select New and add the MinGW-w64 destination folder (e.g., `C:\msys64\ucrt64\bin`).

### 3. Install libcurl
- **a.** Download the precompiled binaries from the [official curl website](https://curl.se/windows/).
- **b.** Extract the zip file to a desired location, e.g., `C:\curl`.

### 4. Set Up Environment Variables
- **a.** Add the directory containing the libcurl binaries to your system's `PATH` environment variable (e.g., `C:\curl\bin`).

### 5. Configure Visual Studio Code (VS Code)
- **a.** Open VS Code.
- **b.** Install the C/C++ extension for VS Code from the Extensions Marketplace if you haven't already.

### 6. Configure VS Code to Use libcurl
- **a.** Create a `tasks.json` file in the `.vscode` folder to define build tasks.
- **b.** Create a `launch.json` file in the `.vscode` folder to configure the debugger.
- **c.** In `launch.json`, add `"miDebuggerPath": "C:\\msys64\\ucrt64\\bin\\gdb.exe"`.

### 7. Build
- **a.** Press `Ctrl+Shift+B` to build your project. The `tasks.json` file will ensure that the project is compiled with the correct include and library paths for libcurl.
- **b.** Press `F5` to start debugging the project.

### 8. Run the Application
```bash
./main.exe

