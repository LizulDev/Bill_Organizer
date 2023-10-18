#include <stdio.h>
#include <stdlib.h>

int main(){

  int array_exem[6];
  int i;
  int aux_cmp = 0;
  for(i=0; i < 6; i++)  // going forth the array; 
   {
    aux_cmp = array_exem[i];
    puts("Type a number here:\n");
    scanf("%i", &array_exem[i]);
    
     if (array_exem[i] == aux_cmp) // verifies if the value is really equal to the same in the var aux_cmp;
       {
        for (int k = 0; k < i; k++)
          {
            array_exem[k] = array_exem[k+1];  
          }
       }
      puts("array:\n");
      for (int j = 0; j < i; j++) // Present the values in the array;
        {
        
         printf(" %i ", array_exem[j]);
         
        }
        puts("\n");
   }
   
