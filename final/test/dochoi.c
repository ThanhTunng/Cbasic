#include <stdio.h>
#include "BST.h"

int countLines(char * textFile){
  FILE * f = fopen(textFile, "r");
  char c;
  int count = 0;
  while((c=fgetc(f))!=EOF){
    if(c=='\n') count++;
  }
  fclose(f);
  return count;
}



void getDataFromA(BSTnode **root,int n){
  FILE * fr = fopen("A.txt","r");
  if(fr==NULL){
    printf("cannot open file\n");
    return;
  }

  BSTtype temp[20];
  for(int i=1;i<=n;i++){
    fscanf(fr,"%d%s",&temp[i].ID,temp[i].dochoi);
    if(strcmp(temp[i].dochoi,".")==0){
      printf("Name model %d missing, enter the name: ",temp[i].ID);
      scanf("%s",temp[i].dochoi);
    }

    BSTinsertNode(root,temp[i]);
  }

  fclose(fr);
  return;
}

void getDataFromB(BSTtype type[],int n){
  FILE * fr = fopen("B.txt","r");
  if(fr==NULL){
    printf("cannot open file\n");
    return;
  }

  for(int i=1;i<=n;i++){
    fscanf(fr,"%d%s",&type[i].ID,type[i].dochoi);
    if(strcmp(type[i].dochoi,".")==0){
      strcpy(type[i].dochoi,"\t");
    }
  }

  fclose(fr);
  return;
}

void search(BSTnode **root,BSTtype typeB[],int nB){
  for(int i=1;i<=nB;i++){
    deleteBSTnodeByScore(root,typeB[i].ID);
  }
  return;
}

void gather(BSTnode **root,BSTtype typeB[],int nB){
  for(int i=1;i<=nB;i++){
    BSTinsertNode(root,typeB[i]);
  }
  return;
}
  
int main(){
  BSTnode *root;
  BST_initial(&root);

  BSTtype typeB[20];
  int n = countLines("A.txt");
  int nB = countLines("B.txt");
   int choice;
   do{
     printf("1.Read file A\n");
     printf("2.Read file B\n");
     printf("3.Search\n");
     printf("4.Gather\n");
     printf("5.List\n");
     printf("6.Exit\n");  
     printf("Enter your choice: ");
     scanf("%d", &choice);
     switch(choice){
     case 1:{
       getDataFromA(&root,n);
       printf("%-10s%-10s\n","ID","Name");
       inOrder(root);
       break;
     }
     case 2:{
       getDataFromB(typeB,nB);
       printf("%-10s%-10s\n","ID","Name");
       for(int i=1;i<nB;i++){
	 printf("%-10d%-10s\n",typeB[i].ID,typeB[i].dochoi);
       }
       break;
     }
     case 3:{
       search(&root,typeB,nB);
       printf("%-10s%-10s\n","ID","Name");
       inOrder(root);
       break;
     }
     case 4:{
       gather(&root,typeB,nB);
       printf("%-10s%-10s\n","ID","Name");
       reverseInOrder(root);
       break;
     }
     case 5:{
       break;
     }
       
     case 6:{
       printf("You've exit the application\n");
       break;
     }
     default:{
       printf("Try again!!\n");
       getchar();
       break;
     }
     }
   }while(choice!=6);
   return 0;
}
