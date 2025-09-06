#define F_CPU 16000000UL
#include <avr/io.h>
void initialize(void) ;
void main(void) {
    
    initialize();
    while (1U) 
    
   {
   PORTC = 0b00000001;
    }
}
void initialize(void) 
{
    //    76543210
 DDRC = 0b00000001; 

}

