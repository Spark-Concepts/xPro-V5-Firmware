# xPro-V5 Firmware (Source Code)

## xPro-V5 Hardware GPIO Pin Mapping
| I/O | xPro-V5 Function | Comments |
| :---------------: | :---------------: | :---------------: |
| AXIS | - | - |
| GPIO_NUM_12 |  X-Axis - Step |  |
| GPIO_NUM_14 |  X-Axis - Direction |  |
| GPIO_NUM_35 |  X-Axis Limit |  |
| GPIO_NUM_27 |  Y-Axis - Step |  |
| GPIO_NUM_26 |  Y-Axis - Direction |  |
| GPIO_NUM_34 |  Y-Axis Limit |  |
| GPIO_NUM_33 |  A-Axis - Step |  |
| GPIO_NUM_32 |  A-Axis - Direction |  |
| GPIO_NUM_36 |  A-Axis Limit | _Default: **"A-Axis Limit"** defined as GPIO_NUM_34 for XYYZ machine config_|
| GPIO_NUM_15 |  Z-Axis - Step |  |
| GPIO_NUM_02 |  Z-Axis - Direction |  |
| GPIO_NUM_39 |  Z-Axis Limit |  |
| Outputs | - | - |
| GPIO_NUM_25 |  Spindle PWM or VFD RS 485 TX | _Default: **Spindle PWM**_ |
| GPIO_NUM_04 |  Spindle Enable or VFD RS 485 RX | _Default: **Spindle Enable**_ |
| GPIO_NUM_21 |  Mist |  |
| Inputs | - | - |
| GPIO_NUM_22 |  Probe |  |
| GPIO_NUM_16 |  Door |  |
| GPIO_NUM_13 |  Macro 1 | _Default: **Undefined**_ |
| GPIO_NUM_00 |  Macro 2 | _Default: **Undefined**_; Also used for the bootloader (Pulled High on Startup) |
| USB SERIAL | - | - |
| GPIO_NUM_01 |  UART TX |  |
| GPIO_NUM_03 |  UART RX |  |
| SPI Bus | - | - |
| GPIO_NUM_19 |  MISO |  |
| GPIO_NUM_23 |  MOSI |  |
| GPIO_NUM_18 |  SCK |  |
| GPIO_NUM_05 |  µSD SPI - Card Select |  |
| GPIO_NUM_17 |  TCM Stepper SPI - Card Select |  |

<img src="https://github.com/Spark-Concepts/xPro-V5/blob/main/images/xProV5-GPIO_PinMap.jpg" width="600">

### Project Overview

Grbl_ESP32 started as a port of [Grbl](https://github.com/gnea/grbl) to the ESP32. The power of the ESP32 has allowed this firmware to grow far beyond the limitations of 8-bit AVR controllers. Here are some of the current features

- **Motors**
  - Control up to 6 coordinated axes (XYZABC)
  - Each axis can have 1 or 2 motors each for a total of 12 motors
  - Dual motors axes can optionally auto square using a home switch and independent control for each motor.
  - Motor drivers can be dynamically assigned to axes, so a 4 motor XYZA controller could be converted to a XYYZ (dual motor Y axis) without any hardware changes.
  - Step rates up to 120,000 per/second.
  - Trinamic (SPI controlled) stepper motors are supported including StealthChop, CoolStep and StallGuard modes. Sensorless homing can be used.
  - Unipolar stepper motor can be directly driven
  - RC hobby servos can be used as coordinated motors with acceleration and speed control. 
- **Peripherals**
  - Limit/Homing Switches with debouncing
  - User input buttons (hold, resume, reset)
  - Coolant control (Mist, Flood)
  - Z Probe (any axis)
  - Safety Door (open door safely retracts and stops spindle, can be resumed)
  - Additional I/O via shift register and I/O expanders supported (on dev branches)
- **Job Control**
  - Instant feed hold and resume
  - Feed rate override
  - Spindle speed override
- **Spindles**
  - PWM
  - RS485 Modus
  - DAC (analog voltage) 0-10V
  - Relay Based
  - RC type Brushless DC motors using low cost BESCs
  - Laser PWM with power/speed compensation
  - Easy to create custom spindles
- **Connectivity**
  - USB/Serial
  - Bluetooth/Serial Creates a virtual serial port on your phone or PC. Standard serial port applications can use Bluetooth.
  - WIFI
    - Creates its own access point or connects to yours.
    - Built in web server. The server has full featured CNC control app that will run on your phone or PC in a browser. No app required.
    - Telnet sending of gcode
    - Push notifications (like...job done, get a text/email)
    - OTA (over the air) firmware upgrades.
- SD card. Gcode can be loaded and run via WIFI.
- **Compatibility** 
  - Grbl_ESP32 is fully backward compatible with Grbl and can use all gcode senders.
- **Customizable**
  - Easy to map pins to any functions.  
  - Custom machines can be designed without touching the main code.   
  - Custom initialization
    - Kinematics
    - Custom homing
    - Tool changer sequences
    - Button macros (run gcode sequence, etc.)
    - Custom end of Job sequence
    - RTOS Real time operating system allows background monitoring and  control without affecting motion control performance
  
- Fast boot
  
  - It boots in about 2 seconds (unlike Raspberry Pi, Beagle Bone). Does not need to be formally shut down. Just kill the power

### Test Drive It

Grbl_ESP32 has a test drive mode. If you just compile it and load it onto an ESP32, it will create a virtual machine without any pins mapped. This allows you to safely test drive it without any attached hardware. Everything is functional including the WIFI and web user interface. Things like homing, that require feedback from actual switches cannot be done.

### Using It

Important compiling instructions are [in the wiki](https://github.com/bdring/Grbl_Esp32/wiki/Compiling-the-firmware)

The code should be compiled using the latest Arduino IDE. [Follow instructions here](https://github.com/espressif/arduino-esp32) on how to setup ESP32 in the IDE. The choice was made to use the Arduino IDE over the ESP-IDF to make the code a little more accessible to novices trying to compile the code.

I use the ESP32 Dev Module version of the ESP32. I suggest starting with that if you don't have hardware yet.

For basic instructions on using Grbl use the [gnea/grbl wiki](https://github.com/gnea/grbl/wiki). That is the Arduino version of Grbl, so keep that in mind regarding hardware setup. If you have questions ask via the GitHub issue system for this project.

### Roadmap

The roadmap is now [on the wiki](https://github.com/bdring/Grbl_Esp32/wiki/Development-Roadmap).

### Credits

The original [Grbl](https://github.com/gnea/grbl) is an awesome project by Sungeon (Sonny) Jeon. I have known him for many years and he is always very helpful. I have used Grbl on many projects. I only ported because of the limitation of the processors it was designed for. The core engine design is virtually unchanged.

The Wifi and WebUI is based on [this project.](https://github.com/luc-github/ESP3D-WEBUI)  

### Contribute

<img src="https://discord.com/assets/e05ead6e6ebc08df9291738d0aa6986d.png" width="8%"> There is a Discord server for the development this project. Ask for an invite

### FAQ

Start asking questions...I'll put the frequent ones here.

### <a name="donation"></a>Donation

This project requires a lot of work and often expensive items for testing. Please consider a safe, secure and highly appreciated donation via the PayPal link below or via the Github sponsor link at the top of the page.

[![](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=TKNJ9Z775VXB2)
