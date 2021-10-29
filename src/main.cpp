/*
 *  Project 41-mqtt2 - main.cpp
 */

#include <Arduino.h>

#include "wifi_ruts.h"
#include "hard.h"   //  Hardware dependent code
#include "mqtt.h"
#include "base_hard.h"
#include "interval.h"

static unsigned long previous_millis;


void
visualize_changes(void)
{
    if( !in_hard_error() )
    {
        click_base_led();
        delay(100);
        click_base_led();
    }
 }

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
