/*
 *  base_hard.h
 *      deals with base hardware
 */

#define NUM_BIT_BOARDS  2

//  init_base_hard(): inits basic hardware

void init_base_hard(void);

//  lit_base_led: lit builtin led

void lit_base_led(void);

//  dim_base_led: dims builtin led

void dim_base_led(void);

//  click_base_led: toggles builtin led

void click_base_led(void);

//  reads board number [0..3]

int get_board_number(void);


