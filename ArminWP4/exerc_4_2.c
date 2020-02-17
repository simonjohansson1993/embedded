#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    unsigned char hexdecimal;
    unsigned char byte;

    unsigned char brake2;
    unsigned char brake1;
    unsigned char key_pos;
    unsigned char gear_pos;
    unsigned char engine_on;

if (argc==2){
    byte = strtol(argv[1],&hexdecimal,16);

    brake2=byte & 0b00000001;

    brake1=(byte & 0b00000010) >> 1 ;

    key_pos = (byte & 0b00001000 ) >> 2;

    gear_pos = (byte & 0b00100000)>> 4;

    engine_on = (byte & 0b10000000)>> 7;



    printf("HEX %d\n",byte);
    printf("brake2 %d\n",brake2);
    printf("brake1 %d\n",brake1);
    printf("Key Pos on %d\n",key_pos);
    printf("Gear Pos on %d\n",gear_pos);
    printf("Engine on %d\n",engine_on);
} else{
    printf("Check arguments passed");
}


}
