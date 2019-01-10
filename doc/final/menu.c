#include <stdio.h>
#include "BST.h"

typedef struct blockList{
  char block[30];
}blockList;

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

void getData(char*file,BSTnode **root,int n){
  FILE *fr = fopen(file,"r");
  if(fr==NULL){
    printf("cannot open file\n");
    return;
  }
  BSTtype temp[20];
  char c;
 
  for(int i=1;i<=n;i++){
    fscanf(fr,"%s%s",temp[i].name,temp[i].ip);
    BSTinsertNode(root,temp[i]);
   
  }
  fclose(fr);
  return;
}

void diffGetData(char *file,char);

void getBlock(char *file,blockList bL[],int nb){
  FILE *fr = fopen(file,"r");
  if(fr==NULL){
    printf("cannot open file\n");
    return;
  }
  char str[30];
  for(int i=1;i<=nb;i++){
    fgets(bL[i].block,30,fr);
  }
  fclose(fr);
  return;
}

int main(){
  BSTnode *root;
  BST_initial(&root);

  blockList bL[100];
   int choice;
   int n = countLines("ip.txt");
   int nb = countLines("blockedip.txt");
   do{
     printf("\n1.Reading Data\n");
     printf("2.IP lookup\n");
     printf("3.Block websites\n");
     printf("4.IP sort\n");
     printf("5.Exit\n");
     printf("Enter your choice: ");
     scanf("%d", &choice);
     switch(choice){
     case 1:{
       getData("ip.txt",&root,n);
       inOrder(root);
       break;
     }
     case 2:{
       char str[20];
       printf("Input the domain name: ");
       scanf("%s",str);
       BSTtype temp1;
       strcpy(temp1.name,str);
       //searchInOrder(root,temp1);
       if(searchInOrder(root,temp1)!=NULL){
	 printf("Redirecting to %s\n",searchInOrder(root,temp1)->data.ip);}
       break;
     }
     case 3:{
       getBlock("blockedip.txt",bL,nb);
       printf("List blocked: \n");
       for(int i=1;i<=nb;i++){
	 printf("%s",bL[i].block);	 
       }
       char subStr[30];
       
       
       printf("Input the domain name to search: ");
       scanf("%s",subStr);
       /*
       BSTtype temp1;
       strcpy(temp1.name,subStr);
       BSTnode *temp2 = searchBlock(&root,temp1.name);
       if(temp2==NULL){
	 printf("This site has been blocked\n");
       }
       else{
	 BSTnode *temp2 = searchInOrder(root,temp1);
       printf("Redirecting to %s\n",temp2->data.ip);
       }
       */
       
       break;
     }
     case 4:{
       
       break;
     }
     case 5:{
       printf("You've exit the application\n");
       break;
     }
     default:{
       printf("Try again!!\n");
       getchar();
       break;
     }
     }
   }while(choice!=5);
   return 0;
}
