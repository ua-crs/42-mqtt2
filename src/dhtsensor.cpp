/*
 *  dhtsensor.cpp
 *      deals with sensor DHTxx
 *      Requiere las siguientes bibliotecas:
 *      - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
 *      - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
 */

//  System includes

#include <Adafruit_Sensor.h>
#include <DHT.h>

//  project includes

#include "dhtsensor.h"
#include "mqtt.h"
#include "hard.h"

// Objects

DHT dht(DHTPIN, DHTTYPE); // Inicializacion sensor DHT

/*
 *  Public functions
 */

//  init_dhtsensor(): inits DHTxx sensor

void
init_dhtsensor(void)
{
    dht.begin();
}

//  read_dhtsensor(): reads and publish in MQTT temperature and humidity


void
read_dhtsensor(void)
{
    float h,t;
    char buff[20];

    h = dht.readHumidity();
    t = dht.readTemperature();

    if (isnan(h) || isnan(t)) //    verify if sensor read failed
    {
        Serial.println("Error reading dht sensor");
        set_hard_error();
    }
    else
    {
        sprintf(buff,"%5.1f",t);
        do_publish("temp",buff);

        sprintf(buff,"%5.1f",h);
        do_publish("hum",buff);
    }
}




