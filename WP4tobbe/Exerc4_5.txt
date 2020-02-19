#include <avr/io.h>
#include <util/delay.h>

int col;
int row;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

void setRowLow(int i){
  switch(i){
    case 0: 
    PORTB = 0b00000111;
    break;
    case 1:
    PORTB = 0b00001011;
    break;
    case 2:
    PORTB = 0b00001101;
    break;
    case 3:
    PORTB = 0b00001110;
    break;
  }
  
}

int checkColumn(){
  //showing the bits
  /*if((PIND & 0b10000000) == 0){
    return 0;
  }
  else if((PIND & 0b01000000) == 0){
    return 1;
  }
  else if((PIND & 0b00100000){
    
    return 2;
  }
  else if((PIND & 0b00010000) == 0){
    
    return 3;
  }*/
  
  if((PIND & (1 << PD7)) == 0){
    return 0;
  }
  else if((PIND & (1 << PD6)) == 0){
    return 1;
  }
  else if((PIND & (1 << PD5)) == 0){
    
    return 2;
  }
  else if((PIND & (1 << PD4)) == 0){
    
    return 3;
  }
  
  else{
    return -1;
  }
}

void setup()
{
  Serial.begin(9600);
  DDRB = 0b00001111;
  DDRD = 0x00;
  
}

void loop()
{
    col = 0;
    row = 0;
        
    //iterate over the rows
    for(int i=0; i < 4; i++) 
    {
      row = i;
      setRowLow(i);
      col = checkColumn();
     
      if(col != -1){
        Serial.println(keys[row][col]);
      }
      
      
    }
  delay(1000);
}