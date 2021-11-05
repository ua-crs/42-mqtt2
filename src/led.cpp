/*
 *  led.cpp
 *      led management
 */

//  System includes

#include <Arduino.h>

//  Project includes

#include "led.h"

//  init_led(): init led hardware for gpio number

void
init_led(int gpio_led)
{
    pinMode(gpio_led,OUTPUT);
    digitalWrite(gpio_led,LOW);
}

/*
 *  set_led():
 *      sets, clears or toggle led connected to gpio number
 *      according to msg.
 *      If msg == NULL, changes led state
 *      else if msg is "0", clears led, else lit led
 */

void
set_led(int gpio_led, const char *msg)
{
    if( msg == NULL )
        digitalWrite(gpio_led, !digitalRead(gpio_led));
    else
        digitalWrite(gpio_led, atoi(msg)!=0 );
}


