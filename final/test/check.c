#include <stdio.h>
#include "stackLL.h"

void printData(char *file){
  FILE * fr = fopen(file,"r");
  if(fr == NULL){
    printf("cannot open file\n");
    return;
  }
  
  char str[10000];
  while(fgets(str,10000,fr)!=NULL){
    printf("%s",str);
  }

  fclose(fr);
  return;
}

int check(char c1,char c2){
  if(c1 == '{' && c2 == '}' ) return 1;
  else if(c1 == '[' && c2 == ']') return 1;
  else if(c1 == '(' && c2 == ')') return 1;
  else return 0;
}

int main(){
  stackNode *st;
  stack_initial(&st);

  
  int choice;
  char str[50];
   do{
     printf("\n1.Input the link and print out data\n");
     printf("2.Check\n");
     printf("3.Exit\n");
     printf("Enter your choice:");
     scanf("%d", &choice);
     switch(choice){
     case 1:{
       
       printf("Input the link");
       scanf("%s",str);
       printData(str);
       
       break;
     }
     case 2:{
       FILE * fr = fopen("text.txt","r");
       if(fr==NULL){
	 printf("cannot open file\n");
	 return 0;
       }

       stackType c;
       int line=1;
       int column=0;
       while((c=fgetc(fr))!=EOF){
	 column++;
	 if(c=='\n'){
	   line++; column = 1;
	 }

	 else if(c=='{' || c=='(' || c=='['){
	   push(&st,c);
	 }
	 else if(c=='}' || c=='}' || c==']'){
	   char subC = pop(&st);
	   if(stack_isEmpty(&st)){
	     printf("Loi thieu dong hoac mo loai %c dong %d cot %d\n",c,line,column);
	 }
	   else if(check(subC,c)!=1)
	     printf("Loi cap khong tuong dong %c hoac %c dong %d cot %d\n",subC,c,line,column);
       }
       }
       
       break;
     }
     case 3:{
       printf("You've exit the application\n");
       getchar();
       break;
     }
     default:{
       printf("Try again!!\n");
       getchar();
       break;
     }
     }
   }while(choice!=3);
   return 0;
}
