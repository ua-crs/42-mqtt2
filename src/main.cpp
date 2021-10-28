/*
 *  Project 41-mqtt2 - main.cpp
 */

#include <Arduino.h>

#include "wifi_ruts.h"
#include "hard.h"   //  Hardware dependent code
#include "mqtt.h"
#include "base_hard.h"

void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    Serial.println("Serial initted");

    connect_wifi(MY_SSID, MY_PASS);

    init_base_hard();
    init_hardware();
    init_mqtt();
#if 0
    Serial.printf("Board number = %u\n\r", get_board_number());
    Serial.printf("bit %u = %u, bit %u = %u\n\r",
        BNUM_B0, digitalRead(BNUM_B0),
        BNUM_B1, digitalRead(BNUM_B1) );
#endif
}

void
loop(void)
{   
    unsigned long current_millis;
    unsigned long previous_millis = millis();

    current_millis = millis();
    if( current_millis - previous_millis > INTERVAL )
    {
        previous_millis = current_millis;
        verify_changes();
    }
    mqtt_comms();
}
