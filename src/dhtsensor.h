#ifndef __DHTSENSOR_H__
#define __DHTSENSOR_H__
/*
 *  dhtsensor.h
 *      deals with sensor DHTxx
 */

//  init_dhtsensor(): inits DHTxx sensor

void init_dhtsensor(void);

//  read_dhtsensor(): reads and publish in MQTT temperature and humidity

void read_dhtsensor(void);

#endif

