/*
 *  base_hard.cpp
 *      deals with base hardware
 */

//  System includes

#include <Arduino.h>

// Project includes

#include "led.h"
#include "base_hard.h"

//  Static variables

static int board_number;

static const unsigned char bnum[NUM_BIT_BOARDS] =
{
    BNUM_B0, BNUM_B1
};

//  Static functions

//  init_board_number: inits and reads bits for detecting board number [0..3]

static void
init_board_number(void)
{
    int count;

    for( count = 0; count < NUM_BIT_BOARDS; ++count )
        pinMode(bnum[count], INPUT_PULLUP);

    for( count = 0; count < NUM_BIT_BOARDS; ++count )
        bitWrite(board_number, count, digitalRead( bnum[count] ));
}

//  Public functions

//  init_base_hard(): inits basic hardware

void
init_base_hard(void)
{
    init_led(LED_BUILT);
    dim_base_led();
    init_board_number();
    Serial.printf("Board number = %u\n\r", get_board_number());
}

//  lit_base_led: lit builtin led

void
lit_base_led(void)
{
    set_led(LED_BUILT,"1");
}

//  dim_base_led: dims builtin led

void
dim_base_led(void)
{
    set_led(LED_BUILT,"0");
}

//  click_base_led: toggles builtin led

void
click_base_led(void)
{
    set_led(LED_BUILT,NULL);
}

//  reads board number [0..3]

int
get_board_number(void)
{
    return board_number;
}







