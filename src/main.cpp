/*
 *  Project 42-mqtt2 - main.cpp
 */

// System includes

#include <Arduino.h>

// Project includes

#include "wifi_ruts.h"
#include "hard.h"
#include "mqtt.h"
#include "base_hard.h"
#include "interval.h"

// Static variables

static unsigned long previous_millis;

// Static functions

/*
 *  visualize changes:
 *      blinks main led when an input chage is detectes
 */

static void
visualize_changes(void)
{
    if( !in_hard_error() )
    {
        click_base_led();
        delay(100);
        click_base_led();
    }
}

/*
 *  Public functions
 */

//  Arduino setup()

void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    Serial.println("Serial initted");

    connect_wifi(MY_SSID, MY_PASS);

    init_base_hard();
    init_hardware();
    init_mqtt();
}

//  Arduino loop

void
loop(void)
{   
    unsigned long current_millis;

    current_millis = millis();
    if( current_millis - previous_millis > interval )
    {
        previous_millis = current_millis;
        verify_changes();
        visualize_changes();
    }
    mqtt_comms();
}
