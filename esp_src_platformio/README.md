# ESP ReadMe

## Board Design
> Information about board design will come soon

## Build Environment Setup
***Ubuntu/Debian 64-bit is preferred.*** This way, the environment is set constant with little variation between the group. A virtual machine is also acceptable with Ubuntu installed by using VMWare Workstation Player.

> Note: for MacOS users, VMWare is not available. Use VirtualBox as an option.

To get started, there are some things that should be taken care of before the build environment is created. Type the following code to get started with creating the build environment:

```bash
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install python3
```

After those commands, copy and paste this code in the terminal and run it as well.
```bash
sudo apt-get install git autoconf build-essential gperf bison flex texinfo libtool libncurses5-dev wget gawk libc6-dev-amd64 python-serial libexpat-dev
```

To setup the Python tools for PlatformIO, install the following libraries:
```bash
pip install pyserial
pip install virtualenv
```

Lastly, install whatever IDE you find comfortable. Look this up yourself, or follow the instruction for VS Code on Linux

- Install VS Code for Linux [https://code.visualstudio.com/docs/?dv=linux64_deb](here)
- Download the Following extensions for VS Code:
    - C/C++
    - Python
    - GitLens (optional if you're familiar with Git)
    - PlatformIO 

## ESP8266/ESP32 Build Environment

> New build environment details coming soon

The following libraries are required:
- Adafruit Unified Sensor
- DHT sensor library
- Adafruit seesaw library
- painlessMesh (and it's dependencies)

To build the code, make sure platformIO is a callable command in terminal. If platformIO command is not found, follow the instructions listed [here (follow method 1 with regards to Bash).](http://docs.platformio.org/en/latest/installation.html#method-1) 

While you can build all the environments with the tools in VS code, if you want to focus on just one environment, utilize the platformIO CLI tool. Within the directory for the esp_src_platformio, you can call on the following commands to either build or upload your code to the boards.

```bash
### In order to build the code for a specific environment
platformio run -e <specific environment>

### In order to build and upload code to the board
platformio run -e <specific environment> -t upload

# Examples
platformio run -e head_node
platformio run -e root_node
platformio run -e head_node -e root_node 
platformio run -e posting_data -t upload
```
More details on how "`platformio run`" works can be found [here.](http://docs.platformio.org/en/latest/userguide/cmd_run.html#platformio-run)
