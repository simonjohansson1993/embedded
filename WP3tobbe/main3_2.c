#include <stdio.h>

int search_number( int number, int tab[], int size);
void sort (int number, int tab []);


int main() {

    int test [] = { 1,2,34,5,67,3,23,12,13,10};
    for (int i = 0; i < 10 ; ++i) {
        printf("%d,", test[i]);
    }
    int number = search_number(67, test, 11);
    puts("");
    printf("%d\n", number);
    puts("after sort:");
    sort(10, test);
    for (int i = 0; i < 10 ; ++i) {
        printf("%d,", test[i]);
    }

    return 0;
}
void sort(int number, int tab[]){
    int temp = 0;
    for (int i = 0; i < number ; ++i) {
        for (int j = i; j < number-1; ++j) {
            if (tab[j+1] < tab[i]){
                temp = tab[j+1];
                tab[j+1] = tab[i];
                tab[i] = temp;
            }
        }

    }
}
int search_number(int number, int tab[], int size){
    for (int i = 0; i < size ; i++) {
        if (number == tab[i]){
            return i;
        }
    }
    return -1;
}
