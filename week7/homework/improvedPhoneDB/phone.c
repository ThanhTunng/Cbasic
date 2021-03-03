#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "linklist.h"
#define max 100
int countPhone(char * textFile){
  FILE * f = fopen(textFile, "r");
  char c;
  int count = 0;
  while((c=fgetc(f))!=EOF){
    if(c=='\n') count++;
  }
  fclose(f);
  return count;
}

void readDataFromTextFile(char * textFile,int count){
  FILE * fr = fopen("phoneDB.txt", "r");
  if(fr==NULL){
    printf("Cannot open phoneDB.txt\n");
    return;
  }
  
  while(!feof(fr)){
    Phone * list = (Phone *)malloc(sizeof(Phone));
    
    fscanf(fr , "%s%s%f%s", list->model, list->memory, &(list->display), list->price);
    insertEnd(list);
    
  }
  fclose(fr);
}

void readDataFromDatFile(char * datFile, Phone * phone){
  FILE* fr = fopen("phoneDB.dat", "rb");
  if(fr==NULL){
    printf("Cannot open phoneDB.dat\n");
    return;
  }

  while(!feof(fr)){
    phone = (Phone *)malloc(sizeof(Phone));
    fread(phone,sizeof(Phone),1,fr);
    insertEnd(phone);
  }
  free(phone);
  fclose(fr);
}

void searchByModel(){
  char *model = (char *)malloc(20*sizeof(char));
  printf("Enter the model you want: ");
  scanf("%s", model);
  node * p = (node *)malloc(sizeof(malloc));
  if(root==NULL) printf("The list is empty\n");
  p = root;
  while(p!=NULL){
    if(strstr(p->phone->model,model)!=NULL)
      displayNode(p);
    p = p->next; 
  }
  free(model);
}

void searchByPrice(){
  float cost;
  printf("Enter the price: ");
  scanf("%f", &cost);

  node * temp = root;
  int found=0;

  while(temp!=NULL){
    if(atof(temp->phone->price) <= cost){
      displayNode(temp);
      found++;
    }
    temp = temp->next;
  }

  if(!found) printf("There is no models you want\n");
}

void exportToData(char *datFile){
  FILE * f = fopen(datFile, "wb");
  if(f==NULL) printf("cannot open file .dat\n");
  else{
    node * temp = (node *)malloc(sizeof(node));
    temp = root;
    while(temp!=NULL){
      fwrite(temp->phone, sizeof(Phone), 1, f);
      temp = temp->next;
    }
  }
}

int main(){
  Phone* list;
  list = (Phone*)malloc(max*sizeof(Phone));
  
  int count=countPhone("phoneDB.txt");
  int choice;
  do{
    printf("\n1. Read data from text file and build the list\n");
    printf("2. Read data from .dat file and build the list\n");
    printf("3. Display List\n");
    printf("4. Search by model\n");
    printf("5. Search phone of which the price is under the value inputted\n"); 
    printf("6. Export to Dat: store infor in linked list to phoneDB.dat\n");
    printf("7. Exit\n\n");
    printf("*Your choice: "); scanf("%d", &choice);
    switch(choice){
    case 1:{
      readDataFromTextFile("phoneDB.txt",count);
      break;
    }
    case 2:{
      readDataFromDatFile("phoneDB.dat",list);
      break;
    }
    case 3:{
      displayList();
      break;
    }
    case 4:{
      searchByModel();
      break;
    }
    case 5:{
      searchByPrice();
      break;
    }
    case 6:{
      exportToData("phoneDB.dat");
      break;
    }
    case 7:{
      printf("You've exit the application\n");
      break;
    }
    default:{
      printf("Try again\n");
      getchar();
      break;
    }
    }
  }while(choice!=7);
  free(list);
  return 0;
}

