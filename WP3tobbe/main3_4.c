#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 10
// -----Typedefs -------
typedef struct {
    char firstname[20];
    char famnamne[20];
    char pers_number[13];
    //yyyymmddnnnc
}PERSON;
// Function declaration (to be extend)
PERSON input_record( void);// Reads in a person record.
void write_new_file(PERSON *inrecord); //Creats a file and write a first record
void printfile(PERSON *inrecord); // print out all persons in the file
void search_by_firstname( char *name, PERSON *persPtr);// print out person if in list
void append_file(PERSON *inrecord);// appends a new person to the file
void clear_stdin()
{
    while( getchar() != '\n' ){
        ;
    }
}

int main( void){
    PERSON ppost[MAX];
    char *name = ppost[0].firstname;
    int choice = 0;
    write_new_file(ppost);
    puts("Welcome to the person register!\n"
         "Choose what you want to do:");


    while (true) {
        puts("1. Delete the old register and create a new one");
        puts("2. Print all records");
        puts("3. Add a person to the register");
        puts("4. Search for a person in the register");
        puts("5. Exit");

        if ((scanf("%d", &choice) == 0)) {
            puts("Input must be an integer");
        } else {
            clear_stdin();
            switch (choice) {
                case 1:
                    write_new_file(ppost);
                    break;
                case 2:
                    printfile(ppost);
                    break;
                case 3:
                    append_file(ppost);
                    break;
                case 4:
                    search_by_firstname(name, ppost);
                    break;
                case 5:
                    break;
                default:
                    puts("Choice must be between 1-5");
            }
            if (choice == 5){
                break;
            }
        }

    }



    return(0);
}
void write_new_file(PERSON *inrecord){
    FILE *fileptr;
    strcpy(inrecord->firstname, "Tobias");
    strcpy(inrecord->famnamne, "Banck");
    strcpy(inrecord->pers_number, "199005203030");

    if((fileptr=fopen("Register.dat","wb"))==NULL) {
        printf("\n Can not create the file");
        exit(1);
    }

    fwrite(inrecord, sizeof(PERSON),1,fileptr);

    fclose(fileptr);

}

void printfile(PERSON *persPtr){
    FILE *fileptr;
    if((fileptr=fopen("Register.dat","rb"))==NULL) {
        printf("\n Can not open file");
        exit(1);
    }   // --------   Reads all file  --------
    while(!feof(fileptr)){
        if (fread(persPtr,sizeof(PERSON),1,fileptr)) {
            printf("\n %s", persPtr->firstname);
            printf("\n %s", persPtr->famnamne);
            printf("\n %s", persPtr->pers_number);
            puts("\n-----------------------");
            persPtr++;
        }

    }   fclose(fileptr);
}
void append_file(PERSON *inrecord){
    FILE *fileptr;
    char firstname[20];
    char famnamne[20];
    char pers_number[13];

    puts("Enter first name:");
    gets(firstname);

    puts("Enter family name:");
    gets(famnamne);

    puts("Enter personal number:");
    gets(pers_number);

    if((fileptr=fopen("Register.dat","rb"))==NULL) {
        printf("\n Can not open file");
        exit(1);
    }   // --------   Reads all file  --------
    while(!feof(fileptr)){
        if (fread(inrecord,sizeof(PERSON),1,fileptr)) {
            inrecord++;
        }

    }

    strcpy(inrecord->firstname, firstname);
    strcpy(inrecord->famnamne, famnamne);
    strcpy(inrecord->pers_number, pers_number);


    if((fileptr=fopen("Register.dat","ab"))==NULL) {
        printf("\n Can not create the file");
        exit(1);
    }


    fwrite(inrecord, sizeof(PERSON),1,fileptr);


    fclose(fileptr);

}
void search_by_firstname( char *name, PERSON *persPtr) {
    FILE *fileptr;
    char nameToSearch[20];
    int choice;
    int found = 0;
    while (true){
        puts("Search for first name(1) or family name(2)");
        if ((scanf("%d", &choice) == 0)) {
            puts("Input must be an integer");
            clear_stdin();
        } else {
            if (choice == 1) {
                name = persPtr->firstname;
                break;
            } else if (choice == 2){
                name = persPtr->famnamne;
                break;
            } else{
                puts("Input must be 1 or 2");
            }
        }
    }
    clear_stdin();

    puts("Enter name:");
    gets(nameToSearch);

    if((fileptr=fopen("Register.dat","rb"))==NULL) {
        printf("\n Can not open file");
        exit(1);
    }   // --------   Reads all file  --------
    while(!feof(fileptr)){
        if (fread(persPtr,sizeof(PERSON),1,fileptr)) {
            if(strcmp(name, nameToSearch)== 0){
                found = 1;
                printf("\n %s", persPtr->firstname);
                printf("\n %s", persPtr->famnamne);
                printf("\n %s", persPtr->pers_number);
                puts("\n-----------------------");
            }
            persPtr++;
            if (choice == 1){
                name = persPtr->firstname;
            } else if (choice == 2){
                name = persPtr->famnamne;
            }

        }

    }   fclose(fileptr);
    if (found == 0){
        puts("No records found");
    }

}
