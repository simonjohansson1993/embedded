#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5
typedef struct q{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

int main(int argc, char *argv[]){
    int nr=0;
    REGTYPE* currentNode , *head=NULL;

    srand( time(0));

    head = random_list();
    currentNode=head;


    while( currentNode!=NULL){
        printf(" Post nr %d : %d\n" , nr++, currentNode->number);
        currentNode=currentNode->next;
    }

    head = add_first(head, rand()%99+1);

    puts("");
    puts("After adding new node: ");
    currentNode=head;
    nr = 0;

    while( currentNode!=NULL){
        printf(" Post nr %d : %d\n" , nr++, currentNode->number);
        currentNode=currentNode->next;
    }

    while((currentNode=head)!=NULL){
        head=currentNode->next;
        free(currentNode);
    }
    return 0;
}
REGTYPE* random_list(void ){

    REGTYPE *top, *old, *item;
    top = (struct q*)malloc(sizeof(struct q));
    old = (struct q*)malloc(sizeof(struct q));
    item = (struct q*)malloc(sizeof(struct q));

    top->number = rand() %99+1;
    old->number = rand() %99+1;
    item->number = rand() %99+1;

    top->next = old;
    old->next = item;
    item->next = NULL;

    top->prev = NULL;
    old->prev = top;
    item->prev = old;


    return(top);
}
REGTYPE* add_first(REGTYPE* temp, int data){
    REGTYPE *newNode;
    newNode = (struct q*)malloc(sizeof(struct q));

    newNode->next = temp;
    newNode->number = data;
    newNode->prev = NULL;

    temp->prev = newNode;

    return (newNode);

}

