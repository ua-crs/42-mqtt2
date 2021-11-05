/*
 *  mqtt_def.h
 *      MQTT definitions
 */

#if MQTT == 0       //  Local broker

const char *mqttServer =    MQUITTO_IP;
const int mqttPort =        MQUITTO_PORT;
const char *mqttUser =      MQUITTO_USER;
const char *mqttPassword =  MQUITTO_PASS;


#elif MQTT == 1     // Remote broker

const char *mqttServer =    SERVER_NAME;
const int mqttPort =        SERVER_PORT;
const char *mqttUser =      SERVER_USER;
const char *mqttPassword =  SERVER_PASS;

#endif


