#include <stdio.h>
#include <stdbool.h>

enum DIRECTION {N,E,S,W};

typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void clear_stdin()
{
    while( getchar() != '\n' ){
        ;
    }
}

void move (ROBOT *robot){
    int direction = robot->dir;
    switch (direction){
        case 0: robot->ypos++;
            puts("Robot moved on step to the north");
            break;
        case 1: robot->xpos++;
            puts("Robot moved on step to the east");
            break;
        case 2: robot->ypos--;
            puts("Robot moved on step to the south");
            break;
        case 3: robot->xpos--;
            puts("Robot moved on step to the west");
            break;
        default:printf("robot did not move");
    }

}
void turn(ROBOT *robot){
    if(robot-> dir == 3){
        robot->dir = 0;
    } else{
        robot->dir++;
    }
    int direction = robot->dir;
    switch (direction){
        case 0:
            puts("Robot turned to the north");
            break;
        case 1:
            puts("Robot turned to the east");
            break;
        case 2:
            puts("Robot turned to the south");
            break;
        case 3:
            puts("Robot turned to the west");
            break;
        default:printf("robot did not move");
    }

}
void readStartingPos(ROBOT *robot){
    int xValue = 0;
    int yValue = 0;

    while (true) {
        puts("Enter an X value (1-99):");
        scanf("%d", &xValue);
        if (xValue >= 0 &&  xValue < 99){
            robot->xpos = xValue;
            break;
        } else {
            puts("input must be between 1-99");
            clear_stdin();
        }
    }
    while (true) {
        puts("Enter a Y value (1-99):");
        scanf("%d", &yValue);
        if (yValue >= 0 &&  yValue < 99){
            robot->ypos = yValue;
            break;
        } else {
            puts("input must be between 1-99");
            clear_stdin();
        }
    }
}

int main() {
    ROBOT robot;
    robot.xpos = 0;
    robot.ypos = 0;

    puts("---Welcome to the Robot program---");

    while (true){
        int choice;
        robot.dir = N;
        puts("Enter a starting position for the for the robot");
        readStartingPos(&robot);
        clear_stdin();

        printf("Robot starting position is X:%d Y:%d\n", robot.xpos, robot.ypos);

        puts("Input a string of numbers to move the robot towards it's current direction (m) or to turn the robot 90 degrees(t)");

        while((choice = getchar()) != '\n'){
            if (choice == 'm'){
                move(&robot);
            } else if (choice == 't'){
                turn(&robot);
            } else{
                puts("Input invalid");
            }
        }

        printf("Robot position is now X:%d Y:%d\n", robot.xpos, robot.ypos);

        char again = 'N';
        puts("Want to give a new starting position? (Y/N)");
        scanf("%c", &again);

        if (again == 'Y' || again == 'y' ){

        } else if (again == 'N' || again == 'n'){
            break;
        }
        clear_stdin();
    }

    return 0;
}
