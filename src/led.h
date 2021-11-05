#ifndef __LED_H__
#define __LED_H__

/*
 *  led.h
 *      led management
 *      for base and added hardware
 */

//  init_led(): init led hardware for gpio number

void init_led(int gpio_led);


/*
 *  set_led():
 *      sets, clears or toggle led connected to gpio number
 *      according to msg.
 *      If msg == NULL, changes led state
 *      else if msg is "0", clears led, else lit led
 */

void set_led(int gpio_led, const char *msg);


#endif

