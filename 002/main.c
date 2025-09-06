#include <avr/io.h>

void initialize(void);

void main(void)
{
    /* Initialization */
    initialize();

    /* Main loop */
    while (1U) 
    {  //mandar a portb 0x05

        if( PINB == 0X01){
            PORTB = 0X02;
        }else{
            PORTB = 0X00;
        }
        
    }
}

void initialize(void)
{
    // Escribir al ddrb 0x04
   DDRB = 0x02; 

}