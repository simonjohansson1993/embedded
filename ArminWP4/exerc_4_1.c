#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned char bitArray;

    if (argc==6){

        int engine_on=atoi(argv[1]);
        int gear_pos=atoi(argv[2]);
        int key_pos=atoi(argv[3]);
        int brake1=atoi(argv[4]);
        int brake2=atoi(argv[5]);

        bitArray|=brake2;
        bitArray|=(brake1<<1);
        bitArray|=(key_pos<<2);
        bitArray|=(gear_pos<<4);
        bitArray|=(engine_on<<7);

        printf("hexa is %X\n",bitArray);
        printf("hexa is %d",bitArray);
    } else {
        printf("Change input arguments");
    }
    return 0;
}
