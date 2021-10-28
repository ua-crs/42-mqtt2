#ifndef __LED_H__
#define __LED_H__

/*
 *  led.h
 *      led management
 */

void init_led(int gpio_led);

void init_all_leds(void);

void set_led(int gpio_led, const char *msg);

void change_action_led( char *msg );

#endif

