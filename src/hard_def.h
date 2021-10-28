/*
 *  hard_def.h
 *      Hardware initial definitiones
 */

#include "mqtt.h"
#include "led.h"
#include "dhtsensor.h"


// Table of routines to verify hardware changes

void (* const changes[])(void) =
{
    read_dhtsensor,
    NULL
};

//  Table of topics to subscribe and actions

const subsc_t topics[] =
{
    { "austral/+/toggle", change_action_led }, 
    NULL
};

//  Table to hardware initializations

void (* const hinit[])(void)
{
    init_all_leds,
    init_dhtsensor,
    NULL
};

//const char *main_topic = "austral";
