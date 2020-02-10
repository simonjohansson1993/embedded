#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

typedef struct NODE{
    int number;
    struct NODE *next;
    struct  NODE *prev;
}NODE;

NODE* random_list (void);
NODE * add_first (NODE* temp, int data);

int main(int argc, char *argv[]) {
    int nr = 0;
    NODE *current, *head = NULL;
    srand(time(0));
    head = random_list();
    current = head;
    while (current != NULL) {
        printf("\n Post nr %d value: %d", nr++, current->number);
        current = current->next;
    }
    nr = 0;

    head = add_first(head,50);
    printf("\n After inserting new Node with data: %d at index: %d ",head->number,nr);
    current = head;

    while (current != NULL) {
        printf("\n Post nr %d value: %d", nr++, current->number);
        current = current->next;
    }

    // --- Free of allocated memory ---
    while((current=head) != NULL){
        head=current->next;
        free(current);
    }
    //------------------
    return 0;
}
// ==== End of main ======================================
NODE* random_list(void ){
    int nr;
    int i=0;
    NODE *top, *old = NULL, *item;

    while (i<MAX){
        NODE *new_node = malloc(sizeof(NODE)*1);
        new_node->next = NULL;
        new_node->prev = NULL;
        nr = rand() % 101;
        new_node->number = nr;

        if (i == 0){
            top = new_node;
        }
        else {
            old->next = new_node;
        }

        new_node -> next = NULL;
        new_node ->prev = old;
        old = new_node;
        i++;
    }

    return(top);
}
//==========================================================
NODE* add_first(NODE* temp, int data){

    NODE *new_node = malloc(sizeof(NODE)*1);
    new_node->next = temp;
    new_node->prev = NULL;
    new_node->number = data;

    temp->prev = new_node;

    return new_node;
}
