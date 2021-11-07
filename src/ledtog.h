#ifndef __LEDTOG_H__
#define __LEDTOG_H__
/*
 *  ledtog.h
 *      Deals qith toggle led
 */

//  init_toggle_led(): init added led for toggle action

void init_toggle_led( void );

//  change_action_led(): action routine on toggle topic, toggles added led

void change_action_led( char *msg );

#endif



