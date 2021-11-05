/*
 *  hard_def.h
 *      Hardware initial definitiones
 */

#include "mqtt.h"
#include "ledtog.h"
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
    { "austral/dash2/interval", change_action_interval }, 
    NULL
};

//  Table to hardware initializations

void (* const hinit[])(void)
{
    init_toggle_led,
    init_dhtsensor,
    NULL
};

