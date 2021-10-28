/*
 *  hard.cpp
 *      Hardware connect to
 */

#include <Arduino.h>

#include "hard.h"
#include "mqtt.h"
#include "led.h"
#include "hard_def.h"

static int hard_error;

void
verify_changes(void)
{
    for( int i=0 ; changes[i] != NULL; ++i )
        (*changes[i])();
}

void
do_subscriptions(void)
{
    for( int i=0; topics[i].topic != NULL; ++i )
        do_subscribe(topics[i].topic);
}

void
init_hardware( void )
{
    for( int i = 0; hinit[i] != NULL; ++i )
        (*hinit[i])();
}

void
set_hard_error(void)
{
    hard_error++;
}

void
reset_hard_error(void)
{
    hard_error = 0;
}

int
in_hard_error(void)
{
    return hard_error != 0;
}


