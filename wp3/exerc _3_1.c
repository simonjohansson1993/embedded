
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
enum DIRECTION {N,O,S,W};
typedef struct {
    int xPos;
    int yPos;
    enum DIRECTION dir;
} robot;
robot rob;
robot *rob_ptr = &rob;
robot rob;

char inputPos[100];
char inputDirection[100];
char userVal[6];
void readPos();
void move(robot*robot1);
void turn(robot*robot1);
int xValue = 0;
int yValue = 0;

int main(){
    int i = 0;
    rob.xPos = 0;
    rob.yPos = 0;
    rob.dir = N;

    printf("------------Hello friend-------------\n");
    while (true) {
        do {

            readPos();

        } while (xValue > 99 || xValue < 0);

        printf("Robot: Give me directions (m = move, t = turn)\n");

        memset(inputDirection, 0, sizeof(inputPos));
        fgets(inputDirection, 100, stdin);
        for (i = 0; inputDirection[i] != '\0'; ++i) {
            if ((int) inputDirection[i] == 116) {
                turn(rob_ptr);
            } else if ((int) inputDirection[i] == 109) {
                move(rob_ptr);
            }
        }
        printf("Robot: My new position is x: %d, y: %d\n", rob.xPos, rob.yPos);
        printf("\ntype any key to continue or exit to quit\n");
        gets(userVal);
        if (strcmp(userVal,"exit") == 0){
            break ;
        }

    }
}
void move (robot*robot1){
    int direction = robot1->dir;
    switch (direction){
        case 0: robot1->yPos++;
        break;
        case 1: robot1->xPos++;
        break;
        case 2: robot1->yPos--;
        break;
        case 3: robot1->xPos--;
        break;
        default:printf("robot did not move");
    }
}
void readPos() {
    char y1 = '0';
    char y2 = '0';
    int yValue1 = 0;
    int yValue2 = 0;
    int i = 0;
    int status= 0;

    printf("Robot: Give me a starting position (x. y)\n");
    memset(inputPos, 0, sizeof(inputPos));
    fgets(inputPos, 6, stdin);

        xValue = atoi(inputPos); //get x value
        if (xValue > 99 || xValue < 0) {
            printf("X too high enter a new position\n");
        }
        if (xValue < 10) {
            y1 = inputPos[2];
            y2 = inputPos[3];
        } else if (xValue > 10 && xValue < 100) {
            y1 = inputPos[3];
            y2 = inputPos[4];
        } else {
            printf("Number too high enter a new position\n");
        }
        yValue1 = y1 - '0';
        yValue2 = y2 - '0';
        if (yValue2 > -1 && yValue2 < 9) {
            yValue1 = (yValue1 * 10);
            yValue = yValue1 + yValue2;
        } else {
            yValue = yValue1;
        }
        //set start values
        rob.xPos = xValue;
        rob.yPos = yValue;
        printf("Robot: My starting position is x: %d, y: %d \n", rob.xPos, rob.yPos);
    }

void turn(robot*robot1){
    int direction = robot1->dir;
    direction++;
    robot1->dir = direction;
}

