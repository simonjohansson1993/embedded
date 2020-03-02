#include <stdio.h>
#define ML13_status 0x0B10;
#define ML13_control 0x0B00;
#define read_control *(char*)ML13_status
#define set_control(x) *(char*)ML13_control

int elevatorStatus = 0;
int control = 0;
int RISING = 1;

void attachInterrupt( int pin,void *param, int mode){

}
void delay(){
    for (int i = 0; i < 5000; ++i) {
        for (int j = 0; j < 5000; ++j) {

        }
    }
}
void openDoor(){
    // writes to the control port address, 1 for opening, 2 for closing (00000001, 00000010)
    set_control(1)
    delay();

}
void closeDoor(){
    // writes to the control port address, 1 for opening, 2 for closing (00000001, 00000010)
    set_control(2)
    //no delay after closing door because it should immediately open when ISR is called
}

void interruptML13(){

    //if door is closing, open it immediately
    if (elevatorStatus == 4){
        // writes to the control port address, 1 for opening, 2 for closing (00000001, 00000010)
        openDoor();

    }
    //if door is opening, extend the delay
    else if (elevatorStatus == 3){
        delay();
    }
    //if door is closed, open it
    else if (elevatorStatus == 2){
        openDoor();
    }
    //if door is open, extend the delay
    else {
        delay();
    }



}
int checkElevatorstatus(){
    //read the current status
    int status = read_control;
    //if status is 10000000, door is closing.
    if ((status) % (1 << 7) == 128){
        return 4;
    }
    //if status is 01000000, door is opening slowly
    else if ((status) % (1 << 6) == 64){
        return 3;

    }
    //if status is 00100000, door is closed.
    else if ((status) % (1 << 5) == 32){
        return 2;

    }
    //if status is 00010000, door is wide open.
    else if ((status) % (1 << 4) == 16) {
        return 1;
    }


}



int main() {

    //attaching interrupt service routine to pin 3 to call interruptML13 when pin goes from 0 to 1
    attachInterrupt(3, interruptML13, RISING);

    //Main loop tries to continuously close the door, interrupt service routine opens door.
    while(1){
        elevatorStatus = checkElevatorstatus();
        //if door is wide open, close it (interrupt service routine takes care of the delay so that it doesn't close immediately)
        if (elevatorStatus == 1){
            closeDoor();
        }
        //if door i closed, reset control register.
        if (elevatorStatus == 2){
            set_control(0)
        }


    }
    return 0;
}
