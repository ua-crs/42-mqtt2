/*
 *  hard.cpp
 *      Hardware connect to
 */

//  System includes

#include <Arduino.h>

//  Project includes

#include "hard.h"
#include "mqtt.h"
#include "led.h"
#include "hard_def.h"

//  Static variables

static int hard_error;

//  Public functions

/*
 *  verify_changes():
 *      Test each hardware to verify if are new to publish
 */

void
verify_changes(void)
{
    for( int i=0 ; changes[i] != NULL; ++i )
        (*changes[i])();
}

/*
 *  do_subscriptions():
 *      Subscribes to topics
 */

void
do_subscriptions(void)
{
    for( int i=0; topics[i].topic != NULL; ++i )
        do_subscribe(topics[i].topic);
}

/*
 *  init_hardware():
 *      Initializes all non basic hardware
 */

void
init_hardware( void )
{
    for( int i = 0; hinit[i] != NULL; ++i )
        (*hinit[i])();
}

//  set_hard_error(): accumulates error in non basic hardware

void
set_hard_error(void)
{
    hard_error++;
}

//  reset_hard_error(): reset errors in non basic hardware

void
reset_hard_error(void)
{
    hard_error = 0;
}

//  in_hard_error(): tests if in error for non basic hardware

int
in_hard_error(void)
{
    return hard_error != 0;
}


