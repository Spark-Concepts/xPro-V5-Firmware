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

### Pre-Compiled Firmware

Pre-Compiled [xPro-V5 firmware](https://github.com/Spark-Concepts/xPro-V5/wiki/Checking_firmware_and_upgrading#precompiled-firmware) has been fully tested and verified

The mose ***up-to-date*** precompiled xPro-V5 firmware can be found here: https://github.com/Spark-Concepts/xPro-V5/tree/main/Firmware

### Compiling Firmware

Important compiling instructions are [in the wiki](https://github.com/bdring/Grbl_Esp32/wiki/Compiling-with-Arduino-IDE#compiling-firmware)

The code should be compiled using the latest Arduino IDE. [Follow instructions here](https://github.com/espressif/arduino-esp32) on how to setup ESP32 in the IDE. The choice was made to use the Arduino IDE over the ESP-IDF to make the code a little more accessible to novices trying to compile the code.

For basic instructions on using Grbl use the [gnea/grbl wiki](https://github.com/gnea/grbl/wiki). That is the Arduino version of Grbl.

### Credits

The CNC xPRO V5 firmware is based on the awesome work of BDring porting the original GRBL to an ESP32 platform.  The original [Grbl](https://github.com/gnea/grbl) is an awesome project by Sungeon (Sonny) Jeon. The core engine design is virtually unchanged.

The Wifi and WebUI is based on [this project.](https://github.com/luc-github/ESP3D-WEBUI)  

