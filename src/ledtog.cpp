/*
 *  ledtog.cpp
 *      Deals qith toggle led
 */
//  System includes

#include <Arduino.h>

//  Project includes

#include "led.h"
#include "ledtog.h"

//  Public functions

//  init_toggle_led(): init added led for toggle action

void
init_toggle_led( void )
{
    pinMode(LED_TOGGLE,OUTPUT);
    digitalWrite(LED_TOGGLE,LOW);
}

//  change_action_led(): action routine on toggle topic, toggles added led

void
change_action_led( char *msg )
{
    set_led(LED_TOGGLE, NULL );
}





