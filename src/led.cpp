/*
 *  led.cpp
 *      led management
 */

#include <Arduino.h>

#include "led.h"

void
init_led(int gpio_led)
{
    pinMode(gpio_led,OUTPUT);
    digitalWrite(gpio_led,LOW);
}

void
init_all_leds( void )
{
    pinMode(LED_TOGGLE,OUTPUT);
    digitalWrite(LED_TOGGLE,LOW);
}

void
set_led(int gpio_led, const char *msg)
{
    if( msg == NULL )
        digitalWrite(gpio_led, !digitalRead(gpio_led));
    else
        digitalWrite(gpio_led, atoi(msg)!=0 );
}


void
change_action_led( char *msg )
{
    set_led(LED_TOGGLE, NULL );
}


