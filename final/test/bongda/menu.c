#include <stdio.h>
 
int main(){
   int choice;
   do{
     printf("1.\n");
     printf("2.\n");
     printf("Enter your choice: ");
     scanf("%d", &choice);
     switch(choice){
     case 1:{
       
       break;
     }
     default:{
       printf("Try again!!\n");
       getchar();
       break;
     }
     }
   }while(choice!=);
   return 0;
}
