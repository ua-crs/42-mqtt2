/*
 *  wifi_ruts.cpp
 *      Routines for WiFi management
 */

#include <Arduino.h>
#include <stdint.h>

#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

#include "wifi_ruts.h"

/*
 *  Private functions
 */

//  wifi_connect: disable brownout detector when connecting wifi

void
wifi_connect(void)
{
    //save WatchDog register
    uint32_t brown_reg_temp;

    brown_reg_temp = READ_PERI_REG(RTC_CNTL_BROWN_OUT_REG);
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector
    WiFi.mode(WIFI_MODE_STA); // turn on WiFi
    delay(1000);
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, brown_reg_temp); //enable brownout detector
}

void
connect_wifi( const char *ssid, const char *pass )
{
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    wifi_connect();
    WiFi.begin(ssid, pass);

//    while(1);
    while( WiFi.status() != WL_CONNECTED )
    {
        Serial.print(".");
        delay(500);
    }

    Serial.println();
    Serial.println("______________");
    Serial.print( "Baud Rate = " );
    Serial.println( SERIAL_BAUD );
    Serial.print( "Conectado a ");
    Serial.println( MY_SSID );
    Serial.print( "MAC = ");
    Serial.println( WiFi.macAddress() );
    Serial.print( "local IP = " );
    Serial.println( WiFi.localIP() );
    Serial.println("______________");
}
