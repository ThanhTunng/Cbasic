#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define max 50
#include <gtk.h>
int countLine(char *nameFile){
  FILE * f = fopen(nameFile, "r");
  if(f==NULL) printf("cannot open file\n");
  else{
    char c;
    int count =0;
    while((c=fgetc(f))!=EOF){
      if(c=='\n') count++;
    }
    return count;
  }
}

int main()
{
  int count = countLine("contact.dat");

  int choice;

  do{
    printf("\n1.Display the contacts.\n");
    printf("Insert more contact: \n");
    printf("\t2.Before current position\n\t3.After current position\n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
    case 1:{
      FILE * f = fopen("contact.dat","rb");
      if(f==NULL){
	printf("cannot open file .dat\n");
      }
      
      while(!feof(f)){
	phone * contact = (phone *)malloc(sizeof(phone));
	fread(contact,sizeof(phone),1,f);
	insertEnd(contact);
      }
      fclose(f);
     
      printList();
      break;
    }
    case 2:{
      FILE * f = fopen("contact.dat","wb");
      phone *extra = (phone *)malloc(1*sizeof(phone));
      printf("Enter the name: ");
      scanf("%s", extra->name);
      printf("Enter the number: ");
      scanf("%s", extra->number);
      printf("Enter email: ");
      scanf("%s", extra->mail);

      insertBefore(extra,cur);
      fclose(f);
      free(extra);
      break;
    }
    case 3:{
      FILE * f = fopen("contact.dat","wb");
      phone *extra = (phone *)malloc(1*sizeof(phone));
      printf("Enter the name: ");
      scanf("%s", extra->name);
      printf("Enter the number: ");
      scanf("%s", extra->number);
      printf("Enter email: ");
      scanf("%s", extra->mail);

      insertAfter(extra,cur);
      fclose(f);
      free(extra);
      break;
    }
    case 4:{
      printf("You've exit the application\n\n");
      break;
    }
    default:{
      printf("Try again!!\n");
      getchar();
      break;
    }
    }
  }while(choice!=4);
  freeList();
  return 0;
}
