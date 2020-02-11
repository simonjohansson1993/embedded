#include <stdio.h>
int search_number( int number, int tab[], int size);
void sort (int number, int tab []);

int main() {
    int test [] = { 1,2,34,5,67,3,23,12,13,10};

    int n;
    int * valueptr;
    valueptr = &n;

    printf("Give a value of N");
    scanf("%d", valueptr );
    int position = search_number( *valueptr, test, sizeof(test) );
    printf("Number found in place %d \n", position );

    sort(10,test);
    for ( int i = 0; i < 10 ; ++i) {
        printf(" %d,", test[i] );
    }
    return 0;
}
void sort (int number, int tab []){
    int temp=0;
    int i=0;
    int j=0;

    for (i = 0; i < number; ++i) {
        for (j = i; j < number - 1; ++j) {
          if ( tab[i] > tab[j+1] ) {
                temp = tab[j+1];
                tab[j+1] = tab[i];
                tab[i] = temp;
          }
       }
    }
}


int search_number( int number, int tab[], int size) {
    int i = 0;
    size = 10;
    int *temp = NULL;
    for (i = 0; i < size; i++) {
        temp = &tab[i];

        if (number == *temp) {
            return i;
        }
    }
            return -1;
}
