/*
 *  interval.cpp
 */

// System includes

#include <Arduino.h>

//  Project includes

#include "interval.h"

//  external public variables

unsigned long interval = INTERVAL;

//  action routine for changing interval after receiving a publication

void
change_action_interval(char *msg)
{
    interval = atol(msg) * 1000;
    Serial.printf("%s: msg = %s, interval = %lu\n\r", __FUNCTION__, msg, interval);
}



