#include <stdio.h>
#include <string.h>
#include "stackLib.h"

int main(){
  stackList *stack1 = (stackList *)malloc(sizeof(stackList));
  stackList *stack2 = (stackList *)malloc(sizeof(stackList));
  stackList *stack3 = (stackList *)malloc(sizeof(stackList));

  initialList(stack1);
  initialList(stack2);
  initialList(stack3);

  char n1[50];
  char n2[50];
  
  printf("Enter the number 1: ");
  scanf("%s", n1);

  printf("Enter the number 2: ");
  scanf("%s", n2);

  for(int i=0;i<strlen(n1);i++){
    elementType temp;
    temp.val = n1[i]-'0';
    push(stack1,temp);
  }

  for(int i=0;i<strlen(n2);i++){
    elementType temp;
    temp.val = n2[i]-'0';
    push(stack2,temp);
  }

  

  int over =0;
    
    while(!isEmpty(stack1) || !isEmpty(stack2)){
    elementType temp1;
    elementType temp2;
    
    if(!isEmpty(stack1)){
        temp1 = pop(stack1);
    }
    else{
      temp1.val = 0;
    }
    
    if(!isEmpty(stack2)){
      temp2 = pop(stack2);
    }
    else{
      temp2.val = 0;
    }
   
    int i= (temp1.val)+(temp2.val)+over;
    
    elementType temp3;
    temp3.val = i%10;

    push(stack3,temp3);
    
    if(i>=10){
      over = 1;
    }
    else over = 0;

  }
  

   char result[51];
   int j=0; 
 
   while(!isEmpty(stack3)){
        elementType tmp = pop(stack3);
     result[j] = tmp.val + '0'; 
     j++; 
   }

   printf("The result: %s\n", result); 
  

  return 0;
  
  
}
