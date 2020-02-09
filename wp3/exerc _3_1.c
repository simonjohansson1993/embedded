
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum DIRECTION {
    N, O, S, W
};
typedef struct {
    int xPos;
    int yPos;
    enum DIRECTION dir;
} robot;
robot rob;
robot *rob_ptr = &rob;
robot rob;

char inputPosX[100];
char inputPosY[100];
char inputDirection[100];
char userVal[6];

void readPos();

void move(robot *robot1);

void turn(robot *robot1);

int xValue = 0;
int yValue = 0;

int main() {
    int i = 0;
    rob.xPos = 0;
    rob.yPos = 0;
    rob.dir = N;

    printf("------------Hello friend-------------\n");
    while (true) {
        rob.dir = N;
        readPos();

        printf("Robot: Give me directions (m = move, t = turn)\n");

        memset(inputDirection, 0, sizeof(inputDirection));
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
        if (strcmp(userVal, "exit") == 0) {
            break;
        }
    }
}

void move(robot *robot1) {
    int direction = robot1->dir;
    switch (direction) {
        case 0:
            robot1->yPos++;
            printf("Robot: I moved to %d\n", robot1->yPos);
            break;
        case 1:
            robot1->xPos++;
            printf("Robot: I moved to %d\n", robot1->xPos);
            break;
        case 2:
            robot1->yPos--;
            printf("Robot: I moved to %d\n", robot1->yPos);
            break;
        case 3:
            robot1->xPos--;
            printf("Robot: I moved to %d\n", robot1->xPos);
            break;
        default:
            printf("robot did not move");
    }

}

void readPos() {
    int xStatus = 0;
    int yStatus = 0;
    char c;

    do {
        xStatus = 0;
        printf("Robot: Give me a starting position (X) between 0-99\n");
        memset(inputPosX, 0, sizeof(inputPosX));
        fgets(inputPosX, 6, stdin);

        for (int i = 0; inputPosX[i] != '\n'; i++) {
            c = inputPosX[i];
            if (c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' &&
                c != '8' && c != '9' && c != '\n') {
                xStatus = 1;
            }
        }
        xValue = atoi(inputPosX);//get x value

        if (xValue > 99 || xValue < 0 || xStatus == 1) {
            printf("X value invalid\n");
        }
    } while (xValue > 99 || xValue < 0 || xStatus == 1);

    do {
        yStatus = 0;
        printf("Robot: Give me a starting position (Y) between 0-99\n");
        memset(inputPosY, 0, sizeof(inputPosY));
        fgets(inputPosY, 6, stdin);

        for (int i = 0; inputPosY[i] != '\n'; i++) {
            c = inputPosY[i];
            if (c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' &&
                c != '8' && c != '9' && c != '\n') {
                yStatus = 1;
            }
        }
        yValue = atoi(inputPosY);//get x value

        if (yValue > 99 || yValue < 0 || yStatus == 1) {
            printf("Y value invalid\n");
        }
    } while (yValue > 99 || yValue < 0 || yStatus == 1);
    //set start values
    rob.xPos = xValue;
    rob.yPos = yValue;
    printf("Robot: My starting position is x: %d, y: %d \n", rob.xPos, rob.yPos);
}

void turn(robot *robot1) {
    if (robot1->dir == 3) {
        robot1->dir = 0;
    } else {
        robot1->dir++;
    }
    printf("Robot: I have turned 90 degrees\n");
}
