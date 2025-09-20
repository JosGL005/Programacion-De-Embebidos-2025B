#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>
void initialize(void) ;
void main(void) {

    uint8_t boton=0;
    uint8_t mascara=0;
    
    initialize();
    while (1U){
        


        mascara=(1<<PORTC1);
        boton= PINC;
        boton= boton & mascara;
        if (boton!=0)
        {
            PORTC=(1<<PORTC0);
        }
        else
        {
            PORTC=0;
        }
    }
}

void initialize(void){
    //    76543210
 DDRC = 0b00000001; 
}

