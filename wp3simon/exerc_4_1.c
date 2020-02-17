#include <stdlib.h>
#include <stdio.h>

unsigned char byteArray;

int main(int argc, char *argv[]){
    if (argc < 6|| argc > 6) {
        printf("Enter correct amount of arguments\n");
        return 1;
    }else {     // hex AB = 10101011
        int engine_on = atoi(argv[1]);
        int gear_pos = atoi(argv[2]);
        int key_pos = atoi(argv[3]);
        int brake1 = atoi(argv[4]);
        int brake2 = atoi(argv[5]);

        byteArray= brake2;
        byteArray= byteArray|(brake1<<1);
        byteArray= byteArray|(key_pos<<2);
        byteArray= byteArray|(gear_pos<<4);
        byteArray = byteArray|(engine_on<<7);
        printf("\nHexa value is: %X",byteArray);
        printf("\nHexa value is: %d",byteArray);
        return 0;
    }

}

