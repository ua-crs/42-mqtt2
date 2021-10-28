/*
 *  base_hard.cpp
 */

#include "led.h"

#include "base_hard.h"

void
init_base_hard(void)
{
    init_led(LED_BUILT);
    dim_base_led();
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


