#include <stdio.h>
#include <string.h>
#include "stackLib.h"
/*
    int strrcmp(char a[], char b[])
    {
        int aj = strlen(a), bj = strlen(b);
        while (aj && a[--aj]== '\0');     //omit all '0' at the end 
        while (bj && b[--bj]== '\0');     //..
        if (aj > bj) return 1;      
        if (aj < bj) return -1;          
        while (aj && a[aj]==b[aj])aj--;    // Nếu độ dài như nhau thì tìm đến chữ số khác nhau đầu tiên
        return a[aj] - b[aj]; // So sánh hai chữ số đó, cùng lắm thì so các chữ số đầu tiên.
    }*/

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

  //****



  //case n1>=n2*************************************
  //if(strrcmp(n1,n2)==1){
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

      int i= temp1.val - temp2.val - over;

      if(i<0){
	i+=10;
	over = 1;
      }
      
      else over = 0;
   
    
      elementType temp3;
      temp3.val = i;

      push(stack3,temp3);
    

    }
    //}
  /*
  //case n1 < n2***********************************
  else if(strrcmp(n1,n2)==-1){
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

      int i= temp1.val - temp2.val - over;

      if(i<0){
	i+=10;
	over = 1;
      }
      
      else over = 0;
   
    
      elementType temp3;
      temp3.val = i;

      push(stack3,temp3);
    

    }

    }*/

  //print result*********************************

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
