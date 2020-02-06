//
// Created by simon on 2020-02-06.
//
#include <stdio.h>
#include <stdlib.h>
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
void move(robot*robot1);
void turn(robot*robot1);

int main(){
    int coordinates;
    rob.xPos = 0;
    rob.yPos = 0;
    rob.dir = N;

    printf("------------Hello friend-------------\n");
    printf("Give me a starting position (x, y), range 0-99\n");
    fgets(inputPos,100,stdin);

    printf()
    printf("")

    turn(rob_ptr);
    move(rob_ptr);
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
void turn(robot*robot1){
    int direction = robot1->dir;
    direction++;
    robot1->dir = direction;
}
