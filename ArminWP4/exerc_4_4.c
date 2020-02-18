#include <avr/io.h>
#include <util/delay.h>
 
void setup() {  
  DDRD = 0xFF; //1111 1111
  DDRB = 0x00;// 0000 0000
  PORTD = B00000011;
}

void loop(){
  
  if( PINB == 1 )
  {
    if( PORTD < B10000000 ){
      PORTD = PORTD << 1;
    }
    
    else if(PORTD >= B11000000){
      PORTD = B10000001;
    }
    
    else{
       PORTD = B00000011;
    }
  }
  delay(500);
}

  


  
