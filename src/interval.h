#ifndef __INTERVAL_H__
#define __INTERVAL_H__

/*
 *  interval.h
 *      deals with interval of testing hardware changes
 */

extern unsigned long interval;

//  action routine for changing interval after receiving a publication

void change_action_interval(char *msg);

#endif


