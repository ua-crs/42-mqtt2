/*
 *  dhtsensor.cpp
 *      Requiere las siguientes bibliotecas:
 *      - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
 *      - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
 */

#include <Adafruit_Sensor.h>
#include <DHT.h>

#include "dhtsensor.h"
#include "mqtt.h"
#include "hard.h"

// Objects

DHT dht(DHTPIN, DHTTYPE); // Inicializacion sensor DHT

/*
 *  Public functions
 */

void
init_dhtsensor(void)
{
    dht.begin();
}

void
read_dhtsensor(void)
{
    float h,t;
    char buff[20];

    h = dht.readHumidity();
    t = dht.readTemperature();

    if (isnan(h) || isnan(t)) //    verificar si cualquiera de las lecturas fracasaron
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




