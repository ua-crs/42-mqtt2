/*
 *  hard_def.h
 *      Hardware initial definitiones
 */

#include "mqtt.h"
#include "led.h"
#include "dhtsensor.h"
#include "interval.h"


// Table of routines to verify hardware changes

void (* const changes[])(void) =
{
    read_dhtsensor,
    NULL
};

//  Table of topics to subscribe and actions

const subsc_t topics[] =
{
    { "austral/dash1/toggle", change_action_led }, 
    { "austral/dash2/toggle", change_action_led }, 
//    { "austral/dash1/interval", change_action_interval }, 
    { "austral/dash2/interval", change_action_interval }, 
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
