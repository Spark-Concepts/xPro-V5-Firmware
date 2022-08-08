#pragma once
// clang-format off

/*
    CNC_XPRO_V5_XYYZ.h
    Part of Grbl_ESP32

    Pin assignments for a 3-axis with Y ganged using Triaminic drivers
    in daisy-chained SPI mode.
    https://github.com/bdring/4_Axis_SPI_CNC

    2019    - Bart Dring
    2020    - Mitch Bradley
    2020    - Spark Concepts 

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/


//Name your machine configuration - this can be viewed real-time using the $i command
#define MACHINE_NAME "CNC_xPRO_V5_XYYZ_NC"


//Define the number of Axis being used (not the number of motors needed - ex. XYYZ machine is still 3 axis) 
#ifdef N_AXIS
        #undef N_AXIS
#endif
#define N_AXIS 3 
#define MAX_AXIS 3

/***************************DO NOT CHANGE*******************/
#define TRINAMIC_DAISY_CHAIN
#define TRINAMIC_RUN_MODE           TrinamicMode :: CoolStep
#define TRINAMIC_HOMING_MODE        TrinamicMode :: CoolStep
#define USE_TRINAMIC_ENABLE
/**********************************************************/

/**************************MOTOR SETUP*********************
You can change the motor definition to add or remove motors from an axis but DO NOT change the values (5160, 0.05f, GPIOs etc). 
These correspond to the specific hardware on the controller.  */

/* Example Motor Configuration for an A axis on the Y2/A port
// A motor connects to the 3rd driver, and the Y2/A port on the case
#define A_TRINAMIC_DRIVER       5160
#define a_RSENSE                0.05f
#define A_STEP_PIN              GPIO_NUM_33
#define A_DIRECTION_PIN         GPIO_NUM_32
#define A_CS_PIN                X_CS_PIN
*/

// X motor connects to the 1st driver, and the X port on the case 
#define X_TRINAMIC_DRIVER       5160        
#define X_RSENSE                0.05f 
#define X_STEP_PIN              GPIO_NUM_12
#define X_DIRECTION_PIN         GPIO_NUM_14
#define X_CS_PIN                GPIO_NUM_17  

// Y motor connects to the 2nd driver, and the Y port on the case
#define Y_TRINAMIC_DRIVER       5160        
#define Y_RSENSE                0.05f
#define Y_STEP_PIN              GPIO_NUM_27
#define Y_DIRECTION_PIN         GPIO_NUM_26
#define Y_CS_PIN                X_CS_PIN  

// Y2 motor connects to the 3rd driver, and the Y2/A port on the case
#define Y2_TRINAMIC_DRIVER       5160        
#define Y2_RSENSE                0.05f
#define Y2_STEP_PIN              GPIO_NUM_33  
#define Y2_DIRECTION_PIN         GPIO_NUM_32  
#define Y2_CS_PIN                X_CS_PIN 


// Z Axis motor connects to the 4th driver, and the Z port on the case
#define Z_TRINAMIC_DRIVER       5160        
#define Z_RSENSE                0.05f
#define Z_STEP_PIN              GPIO_NUM_15 
#define Z_DIRECTION_PIN         GPIO_NUM_2 
#define Z_CS_PIN                X_CS_PIN  


// Coolant output terminal is a switched ground output (low side switch)
// Defaulted to Mist coolant: Turn on with M7 and off with M9
#define COOLANT_MIST_PIN        GPIO_NUM_21

//Option:  Flood coolant - comment out the mist coolant line, and uncomment the below line
//#define COOLANT_FLOOD_PIN		GPIO_NUM_21

/*********** Spindle VFD and Laser Setup ******************/

#define SPINDLE_TYPE          SpindleType::NONE
#define LASER_OUTPUT_PIN      GPIO_NUM_25
#define LASER_ENABLE_PIN      GPIO_NUM_4

#define SPINDLE_OUTPUT_PIN      GPIO_NUM_25
#define SPINDLE_ENABLE_PIN      GPIO_NUM_4


#define VFD_RS485_TXD_PIN		GPIO_NUM_4
#define VFD_RS485_RXD_PIN		GPIO_NUM_25
#define DEFAULT_SPINDLE_RPM_MAX     24000
//#define SPINDLE_ENABLE_PIN_HIGH  1  // flag to catch constant on _enable_pin for BM3D lasers 

/********************************************/


/***********   Input Pins  ******************/
#define PROBE_PIN               GPIO_NUM_22
#define X_LIMIT_PIN             GPIO_NUM_35
//#define Y2_LIMIT_PIN            GPIO_NUM_36
#define Y_LIMIT_PIN             GPIO_NUM_34
#define Z_LIMIT_PIN             GPIO_NUM_39
#define MACRO_BUTTON_1_PIN      GPIO_NUM_13
#define MACRO_BUTTON_2_PIN      GPIO_NUM_0
#define CONTROL_SAFETY_DOOR_PIN GPIO_NUM_16
/********************************************/



// Default configuration - assuming screw TR8*8 screw driven machine in XYYZ config
//steps per mm - use 200 for TR8*8 screws, and 26.667 for belts
#define DEFAULT_X_STEPS_PER_MM 200.0
#define DEFAULT_Y_STEPS_PER_MM 200.0
#define DEFAULT_Z_STEPS_PER_MM 200.0
#define DEFAULT_A_STEPS_PER_MM 200.0

//max speed
#    define DEFAULT_X_MAX_RATE 2500.0
#    define DEFAULT_Y_MAX_RATE 2500.0
#    define DEFAULT_Z_MAX_RATE 2500.0

#    define DEFAULT_X_ACCELERATION 50.0
#    define DEFAULT_Y_ACCELERATION 50.0
#    define DEFAULT_Z_ACCELERATION 50.0

//default motor run current
// this setting = (max motor current * 0.707)*0.9
#    define DEFAULT_X_CURRENT 1.8
#    define DEFAULT_Y_CURRENT 1.8
#    define DEFAULT_Z_CURRENT 1.8
#    define DEFAULT_A_CURRENT 1.8

//default motor hold current
//this setting should be roughly 5-50% of the run current
#    define DEFAULT_X_HOLD_CURRENT 0.25
#    define DEFAULT_Y_HOLD_CURRENT 0.25
#    define DEFAULT_Z_HOLD_CURRENT 0.25
#    define DEFAULT_A_HOLD_CURRENT 0.25

//micro steps
#    define DEFAULT_X_MICROSTEPS 8
#    define DEFAULT_Y_MICROSTEPS 8
#    define DEFAULT_Z_MICROSTEPS 8

//homing
// Home Z axis to clear workspace, then home X and Y at same time
#    define DEFAULT_HOMING_CYCLE_0 bit(Z_AXIS)
#    define DEFAULT_HOMING_CYCLE_1 (bit(X_AXIS) | bit(Y_AXIS))
#    define DEFAULT_HOMING_PULLOFF 2.5

//Stepper settings
#    define DEFAULT_STEP_PULSE_MICROSECONDS 4
#    define DEFAULT_STEPPER_IDLE_LOCK_TIME 255

//switches and probes - 1 =  NO switches, 0 = NC switches
#    define DEFAULT_INVERT_PROBE_PIN 1
#    define DEFAULT_INVERT_LIMIT_PINS 1

//Control Safety Door Switch
#ifdef INVERT_CONTROL_PIN_MASK
#undef INVERT_CONTROL_PIN_MASK
#endif
// For NC Door switch INVERT_CONTROL_PIN_MASK = B00001110
// For NO Door switch INVERT_CONTROL_PIN_MASK = B00001111
// Macro3 | Macro2 | Macro 1| Macr0 |Cycle Start | Feed Hold | Reset | Safety Door
// 1 for NO switch, 0 for NC switch
#	  define INVERT_CONTROL_PIN_MASK B01111110