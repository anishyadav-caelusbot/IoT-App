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

## Server Setup Instructions

This server handles and stores data from the C++ emulator using Node.js with the Express framework. It provides REST API endpoints to start/stop the emulator, retrieve its status, and fetch the latest data.

### Setup Instructions

1. **Setup Node.js and npm**
   - Ensure Node.js and npm are installed on your system.

2. **Install Required Packages**
   - Run the following command to install the necessary packages:
     ```bash
     npm install express body-parser cors
     ```

3. **Run the Server**
   - Start the server using the following command:
     ```bash
     node server.js
     ```

4. **Test the Server**
   - Use tools like Postman or curl to test the API endpoints.

## Frontend

To create a simple front-end interface using Flutter, we'll build an application that interacts with the Node.js server you previously set up. This app will allow users to start and stop the emulator, display the current status, and show the latest temperature and humidity readings.

### Example Usage

1. **Start the Emulator:**
   - Click the "Start Emulator" button to start the emulator on the server.

2. **Stop the Emulator:**
   - Click the "Stop Emulator" button to stop the emulator on the server.

3. **Refresh Data:**
   - Click the "Refresh Data" button to fetch and display the latest temperature and humidity readings.

4. **View Current Status:**
   - The current status of the emulator (Running or Stopped) will be displayed at the top of the screen.

### Step 1: Set Up Flutter Environment

- Follow the official Flutter installation guide to set up Flutter on your machine.
- Confirm the installation with:
  ```bash
  flutter doctor
