/*
 *  mqtt.cpp
 *      Module to deal with MQTT communications
 */

//  System includes

#include <Arduino.h>

//  Library related includes

#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <PubSubClient.h>

//  Project includes

#include "mqtt.h"
#include "hard.h"
#include "mqtt_def.h"
#include "base_hard.h"

//  Objects 

WiFiClient espClient;
PubSubClient client(espClient);

//  static variables

static char client_name[20];

/*
 *  Private functions
 */

//  callback(): asynchronous function called when news from a subscribed topic

static void
callback(char *topic, byte *payload, unsigned int length)
{
    payload[length] = 0;
    Serial.printf("For topic: \"%s\", message \"%s\"\n\r", topic, payload );
    for( int i = 0; topics[i].topic != NULL; ++i )
        if( strstr( topic, topics[i].topic ) != NULL )
        {
            (*topics[i].action)( (char *)payload );
            break;
        }
    Serial.println("-----------------------");
}

//  do_connect(): called to connect or reconnect to MQTT broker

static void
do_connect(void)
{
    dim_base_led();
    while (!client.connected())
    {
        Serial.println("Connecting to MQTT...");

        if (client.connect( client_name, mqttUser, mqttPassword))
            Serial.printf( "client %s connected\n\r", client_name );
        else
        {
            Serial.print("MQTT connection: failed with state ");
            Serial.println(client.state());
            delay(DELAY_CONNECT);
        }
    }
    do_subscriptions();
    Serial.printf( "Connected to %s\n\r", mqttServer );
    lit_base_led();
}


/*
 *  Public functions
 */

//  init_mqtt: connection to an MQTT server

void
init_mqtt(void)
{
    sprintf(client_name,"%s%u",MQTT_NAME,get_board_number());
    Serial.printf("client name = %s\n\r", client_name);
    client.setServer(mqttServer, mqttPort);
    client.setCallback(callback);
    do_connect();
}


//  do_subscribe: subscription to a topic

void
do_subscribe( const char *ptopic )
{
    client.subscribe( ptopic );
}

//  mqtt_comms: manage communications with MQTT server

void
mqtt_comms(void)
{
    if( !client.connected() )
        do_connect();
    client.loop();
}

//  do_publish: publish message as MAIN_TOPIC/SUB_TOPIC+BoardNumber/*ptopic

void
do_publish( const char *ptopic, const char *message )
{
    char topic[50];

    sprintf( topic, "%s/%s%u/%s", MAIN_TOPIC, SUB_TOPIC, get_board_number(), ptopic );
    client.publish( topic, message );
    Serial.printf( "%s: %s %s\n\r", __FUNCTION__, topic, message );
}



