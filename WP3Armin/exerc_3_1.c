#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

enum DIRECTION {N,O,S,W};
typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;
#define MAXCOORDINATE 99
#define MINCOORDINATE 0

void move(ROBOT*robot);
void turn(ROBOT*robot);
void startpos(ROBOT*robot);

int main() {
    ROBOT robot;
    robot.xpos = 0;
    robot.ypos = 0;
    int choice = 0;
    robot.dir = N;

    printf("Welcome to the Robot invasion \n ");
    startpos( &robot );

    do {
        printf("What actions do you wish to take? \n");
        printf("1. Move \n");
        printf("2. Turn \n");
        printf("3. Stop \n");
        scanf("%d", &choice );

        if ( choice == 1 ) {
            move( &robot );
        }

        else if ( choice == 2 ) {
            turn( &robot );
        }

        else {
            printf(" Thanks for joining the invasion \n ");
        }

        printf("\n X is: %d and Y is: %d\n",robot.xpos,robot.ypos);
    } while ( choice != 3 );

    return 0;
}

void startpos( ROBOT *robot ){
    int xposition = MINCOORDINATE;
    int yposition = MINCOORDINATE;
    printf("Enter a starting position horizontal coordinate: \n" );
    scanf("%d", &xposition );

    if ( (xposition > MAXCOORDINATE) || ( xposition < MINCOORDINATE ) ) {
        printf("X coordinate out of bound and is set to 0 by default \n " );
    }

    else {
        robot->xpos = xposition ;
        printf(" X is %d \n ", robot->xpos );
    }

    printf("Enter a starting position vertical coordinate: \n " );
    scanf("%d", &yposition );

    if ( ( yposition > MAXCOORDINATE ) || ( yposition < MINCOORDINATE ) ) {
        printf("Y coordinate out of bound and is set to 0 by default \n " );
    }

    else {
        robot->ypos = yposition;
        printf("Y is %d \n ", robot->ypos );
    }
}
void turn( ROBOT *robot) {
    int direction = robot->dir;

    if ( direction == N ) {
        robot->dir = O;
        printf("Directed to east" );
    }

    else if ( direction == O ) {
        robot->dir = S;
        printf("Directed to South" );
    }

    else if ( direction == W ) {
        robot->dir = N;
        printf("Directed to North" );
    }

    else if ( direction == S ) {
        robot->dir = W;
        printf("Directed to West" );
    }
}


void move( ROBOT *robot ) {

    int direction = robot->dir;

    if ( direction == N ) {
        if( robot->xpos < MAXCOORDINATE){
        robot->xpos = robot->xpos + 1;
        printf("you are at position %d\n", robot->xpos);
    } else{
        printf("There is a cliff. stop! I suggest a Turn.");
        }
    }

    else if ( direction == O ) {
        if( robot->ypos < MAXCOORDINATE ) {
            robot->ypos = robot->ypos + 1;
            printf("you are at position %d\n", robot->ypos );
        } else {
            printf("There is a cliff. stop! I suggest a Turn." );
        }
    }

    else if ( direction == W ) {
        if ( robot->ypos >= 1 ){
            robot->ypos = robot->ypos - 1;
            printf("you are at position %d \n", robot->ypos );
        } else {
            printf("I suggest a Turn");
        }
    }

    else if (direction == S) {
        if (robot->xpos >= 1) {
            robot->xpos = robot->xpos - 1;
            printf("you are at position %d\n", robot->xpos);
        } else {
            printf("Please turn");
        }

    } else {
        printf("Try to rotate\n");
    }
}

