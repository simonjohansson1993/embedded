// ---- Program template for Arduino in Tinkercad VT 2020
#include <avr/io.h>
#include <util/delay.h>
 
/* --- Macros preedefind for the compiler
DDRB  Data direction register B
PORTB Outport B
PINB  Inport B
DDRD  Data direction register D
PORTD Outport D
PIND  Inport D
*/



int main() {
  int b1 = 1;
  int b2 = 2;
  
    DDRD = 0xff; //out
	DDRB = 0x00;  // in
	PORTD = 0b00000011; //set to 3
  
  while(1){
   _delay_ms(500);
  
    PORTD = (1<<b1) | (1<<b2);
    
    
    if(PINB == 1){
    	if(b2 == 7){
      	 	b2 = 0;
       		b1++;
    	}
    	else if(b1 ==7){
      	 	b1 = 0;
       		b2++;
      
    	}
    	else{
      		b1++;
      		b2++;
    	}
    }
  
  
  }
  return 0;
  
}