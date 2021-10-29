/*
 *  interval.cpp
 */

#include <Arduino.h>

#include "interval.h"

unsigned long interval = INTERVAL;


void
change_action_interval(char *msg)
{
    interval = atol(msg) * 1000;
    Serial.printf("%s: msg = %s, interval = %lu\n\r", __FUNCTION__, msg, interval);
}



