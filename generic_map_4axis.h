/*
  generic_map_4axis.h - driver code for RP2040 ARM processors

  Part of grblHAL

  Copyright (c) 2021-2024 Terje Io
  Copyright (c) 2021 Volksolive

  grblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grblHAL. If not, see <http://www.gnu.org/licenses/>.
*/

#if TRINAMIC_ENABLE
#error Trinamic plugin not supported!
#endif

// disable spindle, not needed for OpenPNP
#undef DRIVER_SPINDLE_ENABLE
#undef DRIVER_SPINDLE_DIR_ENABLE
#undef DRIVER_SPINDLE_PWM_ENABLE

// disable spindle, not needed for OpenPNP
#undef DRIVER_SPINDLE_ENABLE
#undef DRIVER_SPINDLE_DIR_ENABLE
#undef DRIVER_SPINDLE_PWM_ENABLE

// Define step pulse output pins.
#define STEP_PORT               GPIO_PIO  // N_AXIS pin PIO SM
#define STEP_PINS_BASE          2         // N_AXIS number of consecutive pins are used by PIO

// Define step direction output pins.
#define DIRECTION_PORT          GPIO_OUTPUT
#define X_DIRECTION_PIN         6
#define Y_DIRECTION_PIN         7
#define Z_DIRECTION_PIN         8
//#define A_DIRECTION_PIN        9
#define DIRECTION_OUTMODE       GPIO_SHIFT6

// Define stepper driver enable/disable output pin.
#define ENABLE_PORT             GPIO_OUTPUT
#define STEPPERS_ENABLE_PIN     10

// Define homing/hard limit switch input pins.
#define X_LIMIT_PIN             11
#define Y_LIMIT_PIN             12
#define Z_LIMIT_PIN             13
//#define A_LIMIT_PIN            14
#define LIMIT_INMODE            GPIO_MAP

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE
#define M3_STEP_PIN             (STEP_PINS_BASE + 3)
#define M3_DIRECTION_PIN        (Z_DIRECTION_PIN + 1)
#define M3_LIMIT_PIN            (Z_LIMIT_PIN + 1)
#endif


// Define user-control controls (cycle start, reset, feed hold) input pins.
#define RESET_PIN               15      // EStop
//#define FEED_HOLD_PIN           19
//#define CYCLE_START_PIN         20

// Define flood and mist coolant enable output pins.
// #define COOLANT_PORT            GPIO_OUTPUT
// #define COOLANT_FLOOD_PIN       16
// #define COOLANT_MIST_PIN        17

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN         AUXINPUT1_PIN
#elif MOTOR_FAULT_ENABLE
#define MOTOR_FAULT_PIN         AUXINPUT1_PIN
#endif

// Define probe switch input pin.
//#define PROBE_PIN               22

#if I2C_STROBE_ENABLE
#define I2C_STROBE_PIN          28
#endif

// aux inputs
#define AUXINPUT0_PIN           16
#define AUXINPUT1_PIN           17
#define AUXINPUT2_PIN           18
#define AUXINPUT3_PIN           19
#define AUXINPUT4_PIN           20

// aux outputs
#define AUXOUTPUT0_PORT         GPIO_OUTPUT
#define AUXOUTPUT0_PIN          21
#define AUXOUTPUT1_PORT         GPIO_OUTPUT
#define AUXOUTPUT1_PIN          22
#define AUXOUTPUT2_PORT         GPIO_OUTPUT
#define AUXOUTPUT2_PIN          26
#define AUXOUTPUT3_PORT         GPIO_OUTPUT
#define AUXOUTPUT3_PIN          27
#define AUXOUTPUT4_PORT         GPIO_OUTPUT
#define AUXOUTPUT4_PIN          28

