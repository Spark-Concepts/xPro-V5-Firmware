# xPro-V5 Firmware (Source Code)

## xPro-V5 Hardware GPIO Pin Mapping
<table>
  <thead>
    <tr>
      <th colspan="3">Steppers</td>
    </tr>
    <tr>
      <td>GPIO_NUM_12</td>
      <th rowspan="2">X-Axis</th>
      <td>Step</td>
    </tr>
    <tr>
      <td>GPIO_NUM_14</td>
      <td>Direction</td>
    </tr>
    <tr>
      <td>GPIO_NUM_27</td>
      <th rowspan="2">Y-Axis</th>
      <td>Step</td>
    </tr>
    <tr>
      <td>GPIO_NUM_26</td>
      <td>Direction</td>
    </tr>
    <tr>
      <td>GPIO_NUM_33</td>
      <th rowspan="2">A-Axis</th>
      <td>Step</td>
    </tr>
    <tr>
      <td>GPIO_NUM_32</td>
      <td>Direction</td>
    </tr>
</tbody>
  
<table>
  <thead>
    <tr>
      <th colspan="3">Outputs</td>
    </tr>
    <tr>
      <td>GPIO_NUM_25</td>
      <th>Spindle PWM or VFD RS 485 TX</th>
      <td>Default: Spindle PWM</td>
    </tr>
    <tr>
      <td>GPIO_NUM_04</td>
      <th>Spindle Enable or VFD RS 485 RX</th>
      <td>Default: Spindle Enable</td>
    </tr>
    <tr>
      <td>GPIO_NUM_21</td>
      <th>Coolant Mist</th>
      <td></td>
    </tr>
</tbody>
    
<table>
  <thead>
    <tr>
      <th colspan="3">Inputs</td>
    </tr>
    <tr>
      <td>GPIO_NUM_35</td>
      <th>X-Axis Limit</th>
      <td></td>
    </tr>
    <tr>
      <td>GPIO_NUM_34</td>
      <th>Y-Axis Limit</th>
      <td></td>
    </tr>
    <tr>
      <td>GPIO_NUM_36</td>
      <th>A-Axis Limit</th>
      <td>Default: "A-Axis Limit" defined as GPIO_NUM_34 for XYYZ machine config</td>
    </tr>
    <tr>
      <td>GPIO_NUM_39</td>
      <th>Z-Axis Limit</th>
      <td></td>
    </tr>
    <tr>
      <td>GPIO_NUM_22</td>
      <th>Probe</th>
      <td></td>
    </tr>
    <tr>
      <td>GPIO_NUM_16</td>
      <th>Door</th>
      <td></td>
    </tr>
    <tr>
      <td>GPIO_NUM_13</td>
      <th>Macro 1</th>
      <td>Default: Undefined</td>
    </tr>
    <tr>
      <td>GPIO_NUM_00</td>
      <th>Macro 2</th>
      <td>Default: Undefined; GPIO also used for the bootloader (Pulled High on Startup)</td>
    </tr>
</tbody>
  
<table>
  <thead>
    <tr>
      <th colspan="2">USB Serial</td>
    </tr>
    <tr>
      <td>GPIO_NUM_01</td>
      <th>UART TX</th>
    </tr>
    <tr>
      <td>GPIO_NUM_03</td>
      <th>UART RX</th>
    </tr>
</tbody>

<table>
  <thead>
    <tr>
      <th colspan="2">SPI Bus</td>
    </tr>
    <tr>
      <td>GPIO_NUM_19</td>
      <th>MISO</th>
    </tr>
    <tr>
      <td>GPIO_NUM_23</td>
      <th>MOSI</th>
    </tr>
    <tr>
      <td>GPIO_NUM_18</td>
      <th>SCK</th>
    </tr>
    <tr>
      <td>GPIO_NUM_05</td>
      <th>µSD Reader SPI Card Select</td>
    </tr>
    <tr>
      <td>GPIO_NUM_17</td>
      <th>TMC5160 Stepper SPI Card Select</td>
    </tr>
</tbody>
<table>

### Pre-Compiled Firmware

Pre-Compiled [xPro-V5 firmware](https://github.com/Spark-Concepts/xPro-V5/wiki/Checking_firmware_and_upgrading#precompiled-firmware) has been fully tested and verified

The most ***up-to-date*** precompiled xPro-V5 firmware can be found here: https://github.com/Spark-Concepts/xPro-V5/tree/main/Firmware

### Compiling Firmware

Important compiling instructions are [in the wiki](https://github.com/bdring/Grbl_Esp32/wiki/Compiling-with-Arduino-IDE#compiling-firmware)

The code should be compiled using the latest Arduino IDE. [Follow instructions here](https://github.com/espressif/arduino-esp32) on how to setup ESP32 in the IDE. The choice was made to use the Arduino IDE over the ESP-IDF to make the code a little more accessible to novices trying to compile the code.

For basic instructions on using Grbl use the [gnea/grbl wiki](https://github.com/gnea/grbl/wiki). That is the Arduino version of Grbl.

### Credits

The CNC xPRO V5 firmware is based on the awesome work of BDring [porting](https://github.com/bdring/Grbl_Esp32/blob/main/README.md) the original GRBL to an ESP32 platform.  The original [Grbl](https://github.com/gnea/grbl) is an awesome project by Sungeon (Sonny) Jeon. The core engine design is virtually unchanged.

The Wifi and WebUI is based on [this project.](https://github.com/luc-github/ESP3D-WEBUI)  

