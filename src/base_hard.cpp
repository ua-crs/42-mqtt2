/*
 *  base_hard.cpp
 */

#include <Arduino.h>

#include "led.h"

#include "base_hard.h"

static int board_number;

static const unsigned char bnum[NUM_BOARDS] =
{
    BNUM_B0, BNUM_B1
};


void
init_board_number(void)
{
    int count;

    for( count = 0; count < NUM_BOARDS; ++count )
        pinMode(bnum[count], INPUT_PULLUP);

    for( count = 0; count < NUM_BOARDS; ++count )
        bitWrite(board_number, count, digitalRead( bnum[count] ));
}

void
init_base_hard(void)
{
    init_led(LED_BUILT);
    dim_base_led();
    init_board_number();
    Serial.printf("Board number = %u\n\r", get_board_number());
}

void
lit_base_led(void)
{
    set_led(LED_BUILT,"1");
}

void
dim_base_led(void)
{
    set_led(LED_BUILT,"0");
}

void
click_base_led(void)
{
    set_led(LED_BUILT,NULL);
}

int
get_board_number(void)
{
    return board_number;
}







