#ifndef INC_LED_DRIVER_H_
#define INC_LED_DRIVER_H_

#include <stdint.h>

// Configures all the LEDs and turns them all on. Very basic, so should never
// crash. Used to indicate hard errors like failed oscillator init.
extern void led_driver_panic(void);

// Initializes the LED driver. Defaults to pattern 0. Patterns are defined in
// the .c file.
extern void led_driver_init(void);

// Default "chaser" sequence: 1 sec of each LED
#define PATTERN_DEFAULT_CHASER    0
// LEDs go back and forth quickly
#define PATTERN_BACK_AND_FORTH    1
// Just red flashes
#define PATTERN_JUST_RED    2

// Set the LED pattern
extern void led_driver_set_mode(uint8_t mode);

// Get the current LED pattern
extern uint8_t led_driver_get_mode(void);

// Set some LEDs to states in pattern and not flash
extern void led_driver_set_fixed(uint8_t pattern, uint8_t mask);
extern uint8_t led_driver_get_fixed_pattern();
extern uint8_t led_driver_get_fixed_mask();

#endif  // INC_LED_DRIVER_H_
