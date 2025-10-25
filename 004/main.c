
/*
 * File:                    main.c
 * Author:                  Daniel Martinez
 *                          dagmtzs@gmail.com
 * Date:                    Sun Jan 01 00:00:00 AM CST 2024
 * Target:                  ATmega328P
 * Description:             This is a template for ATmega328P programs written in C
 */

/************************************************
 *       << Area for macro definitions >>       *
 ************************************************/
#define F_CPU 1000000UL

/************************************************
 *       << Area for includes >>                *
 ************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
 

void initialize(void);

/************************************************
 *       << Main function >>                    *
 ************************************************/
void main(void)
{
    /* Initialization */
    initialize();

    /* Main loop */
    while (1U) 
    {
       PORTC = PINC ^ (1 << PC5);
       _delay_ms(250);
    }

}

/************************************************
 *       << Initialization routine >>           *
 ************************************************/
void initialize(void)
{
    /* Set External Interrupt Control Register A to trigger an interrupt request with a falling edge of INT0*/
    EICRA |= (1 << ISC00) | (1 << ISC01);   // ISC01 = 1, ISC00 = 1


    /* Enable External Interrupt Request 0 */
    EIMSK |= (1 << INT0);

    /* Set PORTD2 as input and enable internal pull-up resistor */
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);

    /* Set PORTD4 as output */
    DDRC |= (1 << PC5);

    /* Enable global interrupts */
    sei();
}

ISR(INT0_vect)
{
    DDRC ^= (1 << PC5);
}
