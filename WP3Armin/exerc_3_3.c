#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5
#define MAXRAND 100

typedef struct REGTYPE{
    int number;
    struct REGTYPE *next;
    struct REGTYPE *prev;
} REGTYPE;


REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);


int main(int argc, char *argv[])
{
    int nr=0;
    REGTYPE *current , *head=NULL;
    srand( time(0));

    head=random_list();
    current=head;

    while ( current != NULL ) {
        printf(" Post nr %d : %d\n", nr++, current->number );
        current = current->next ;
    }

    head = add_first (head, rand() %MAXRAND );
    printf("_________________________________________ \n");
    current = head;
    nr = 0;

    while (current != NULL) {
        printf("\n Post nr %d : %d", nr++, current->number);
        current = current->next;
    }

    while( (current = head) != NULL ) {
        head = current->next;
        free( current );
    }

    return 0;
}


REGTYPE *add_first( REGTYPE *temp, int data ) {

    REGTYPE *regtype = malloc( sizeof(REGTYPE) );
    regtype->next = temp;
    regtype->number = data;
    temp->prev = regtype;
    return regtype;
}

REGTYPE *random_list( void ) {
    int nr;
    REGTYPE *top, *old;
    old = NULL;

    for (int i = 0; i < MAX; ++i) {
        REGTYPE *regtype = malloc(sizeof(REGTYPE));
        nr = rand() % MAXRAND;
        regtype->number = nr;

        if (i == 0){
            top = regtype;
        } else {
            old->next = regtype;
        }

        regtype -> prev = old;
        regtype -> next = NULL;
        old = regtype;
    }

    return(top);
}



