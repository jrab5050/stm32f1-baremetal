/**
 * @file     main.c
 * @author   Rohit Nimkar <https://www.linkedin.com/in/rohit-nimkar>
 * @brief    Blink LED connected to PC13
 * @version  1.2
 * @date     2024-01-06
 *
 * @copyright Copyright (c) 2024
 *
 * @attention
 * This software component is licensed by Rohit Nimkar under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at: opensource.org/licenses/BSD-3-Clause
 *
 */

#include <stm32f1xx.h>

void ms_delay(int ms)
{
    while (ms-- > 0)
    {
        volatile int x = 1000;
        while (x-- > 0)
            __asm("nop");
    }
}

int main(void)
{
    /* Enable clock for port A */
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    /* Set PA5 as General Purpose Output @2MHZ */
    GPIOA->CRL &= ~(GPIO_CRL_CNF5 | GPIO_CRL_MODE5);
    GPIOA->CRL |= GPIO_CRL_MODE5;

    while (1)
    {
        /* Set bit corresponding to PA5 */
        GPIOA->BSRR = GPIO_BSRR_BS5;
        ms_delay(1000);

        /* Reset bit corresponding to PA5 */
        GPIOA->BRR = GPIO_BRR_BR5;
        ms_delay(1000);
    }
}

