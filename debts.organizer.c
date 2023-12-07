//Project in C that can keep a bill history to be employed later
//Author: Luiz Felipe Kaue da Silva;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct debt{
char title[100];
float value;
struct debt * right;
}BILLS;

typedef BILLS * LIST;

void CleanList(LIST* l) { //Function that will clean all the single-chained list after ending the compilation;
  BILLS* current = *l;
  while (current != NULL) {
    BILLS* next = current->right;
    free(current);
    current = next;
  }
  *l = NULL;
}

void insertDebt(LIST *l, char *title, float value) { // Function that will insert a new bill and alocate it dinamically in the memory; 
    BILLS *NewDebt;
    NewDebt = (BILLS*) malloc(sizeof(BILLS));
    NewDebt->value = value;
    strcpy(NewDebt->title, title);
    NewDebt->right = NULL;

    if (*l == NULL) {
        *l = NewDebt;
    } else {
        BILLS* current = *l;
        while (current->right != NULL) {
            current = current->right;
        }
        current->right = NewDebt;
    }
}



void showList(LIST *l) { //Function that will show all the list at the point the user inserted their data. 
  BILLS* current = *l;
    if(*l == NULL)
    {
        return;
    }
    else
    { 
        printf("%s - ", current->title);
        printf("%.2f\n", current->value);
        mostrar(&(*l)->right);
    }
    
  printf("\n");
}

int main(){ 

LIST l = NULL;
float value;
char title[100];
int option;
do {

    puts("Montly Debts Organizer:\n");
    puts("=================================\n");
    puts("[1]Insert a data bill\n");
    puts("[2]Show the bills in sequency\n");
    puts("[3]Leave\n");
    scanf("%i", &option);

    switch (option){
        case 1:
            puts("Type the nature of the bill:\n");
            scanf("%s", title);
            puts("Type the value that will be spent:\n");
            scanf("%f", &value);
            insertDebt(&l, title, value);
        break;

        case 2:
            puts("\n=========================\n");
            showList(&l);
            puts("\n=========================\n");
        break;

        case 3:
            break;
        
        default:
        puts("Invalid option!\n");
        break;
    }
    
}while (option != 3);

CleanList(&l);












return 0;
}
