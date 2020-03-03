#include <unistd.h>
#define ML13_Status 0x0B10
#define ML13_Control 0x0B00
#define read_status * (char*) ML13_Status
#define set_control(x) *(char*) ML13_Control = x

//------------VARIABLES
const char open = 0x01;
const char closed = 0x02;

//---------------START OF MAIN-------------------------
int main() {

    while (1) {

        const char status = read_status;
        const char is_closing = status & 0x80; //128 -> door is closing
        const char is_closed = status & 0x20;  //32 -> door is closed
        const char sensor_active = status & 0x08;  //8 -> sensor is active

        //check if sensor detects a person when door is either closed or closing

        if ((is_closing && sensor_active) || (is_closed && sensor_active)) {
            
            set_control(open); //0000 0001 -> write door is open
            sleep(3);

            //else door is open and we want to close it
        } else {
            
            set_control(closed);
            //no delay when closing if sensor reads a person again
        }
    }
}
