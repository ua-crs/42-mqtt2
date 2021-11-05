/*
 *  mqtt.h
 *      Module to deal with MQTT communications
 */

#ifndef __MQTT_H__
#define __MQTT_H__

//  subsc_t: memory structure for subscribed topics

typedef struct
{
    const char *topic;
    void (*action)( char *message );
} subsc_t;

//  topics: external public array of topic_t structures subscribed
extern const subsc_t topics[];

//  init_mqtt: connection to an MQTT server
void init_mqtt(void);

//  do_subscribe: subscription to a topic
void do_subscribe( const char *ptopic );

//  mqtt_comms: manage communications with MQTT server
void mqtt_comms(void);

//  do_publish: publish message as MAIN_TOPIC/SUB_TOPIC+BoardNumber/*ptopic

void do_publish( const char *ptopic, const char *message );

#endif


