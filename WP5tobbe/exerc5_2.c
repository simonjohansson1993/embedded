#include <avr/io.h>
#include <util/delay.h>

bool keyHit = false;
int col;
int row;
char key;
float analogValue;

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
  /*if((1110001 & 0b10000000) == 0){
    return 0;
  }
  else if((11110011 & 0b01000000) == 0){
    return 1;
  }
  else if((11110000 & 0b00100000)== 0){
    
    return 2;
  }
  else if((11110000 & 0b00010000) == 0){
    
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
void keyboardirq(){
  //iterate over the rows
    for(int i=0; i < 4; i++) 
    {
      row = i;
      setRowLow(i);
      col = checkColumn();
     
      if(col != -1){
        keyHit = true;
        key = keys[row][col];
        break;
      }
      
      
    }
  
}

void setup()
{
  Serial.begin(9600);
  DDRB = 0b00001111;
  DDRD = 0x00;
  attachInterrupt(digitalPinToInterrupt(2), keyboardirq , FALLING);
  
}

void loop()
{
    col = 0;
    row = 0;
    PORTB = 0b00000000;
  if (keyHit){
    Serial.println(key);
    
  }
  keyHit = false;
  
  analogValue = analogRead(A0);
  
  float voltage = analogValue * 5.0;
  voltage /= 1024.0;
  
  float temperatureC = (voltage - 0.5) * 100 ;
  
  Serial.print("Temperature:");
  Serial.println(temperatureC);
  
  delay(500);
  
}