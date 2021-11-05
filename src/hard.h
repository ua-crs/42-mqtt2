/*
 *  hard.h
 *      Hardware connecto to
 */

/*
 *  verify_changes():
 *      Test each hardware to verify if are new to publish
 */

void verify_changes(void);

/*
 *  do_subscriptions():
 *      Subscribes to topics
 */

void do_subscriptions(void);

/*
 *  init_hardware():
 *      Initializes all non basic hardware
 */

void init_hardware( void );

//  set_hard_error(): accumulates error in non basic hardware

void set_hard_error(void);

//  reset_hard_error(): reset errors in non basic hardware

void reset_hard_error(void);

//  in_hard_error(): tests if in error for non basic hardware

int in_hard_error(void);


