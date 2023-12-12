#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct debt{
char title[100];
float value;
struct debt * right;

}BILLS;

typedef BILLS * LIST;

void CleanList(LIST* l) {
  BILLS* current = *l;
  while (current != NULL) {
    BILLS* next = current->right;
    free(current);
    current = next;
  }
  *l = NULL;
}

void insertDebt(LIST *l, char *title, float value) {
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



void showList(LIST *l) {
  BILLS* current = *l;
    if(*l == NULL)
    {
        return;
    }
    else
    { 
        printf("%s - ", current->title);
        printf("%.2f\n", current->value);
        showList(&(*l)->right);
    }
    
  printf("\n");
}

float Sum_Values(LIST *l){
    BILLS * temp = *l;
    float sum;
    while (temp != NULL){
        sum += temp->value;
        temp = temp->right;
    }
    return sum;
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
    puts("[3]Sum all the values\n");
    puts("[4]Clean the list\n");
    puts("[5]Leave\n");
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
            puts("\n=========================\n");
            printf("The sum of the values is: %.2f", Sum_Values(&l));
            puts("\n=========================\n");
            break;
        
        case 4:
            CleanList(&l);
            break;
            

        case 5:
            break;
        
        default:
        puts("Invalid option!\n");
        break;
    }
    
}while (option != 5);

CleanList(&l);

return 0;
}
