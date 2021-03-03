#include <stdio.h>
#include "BST.h"

typedef struct match{
  char team1[10];
  char team2[10];
  int score1;
  int score2;
}Match;

int countLines(){
  FILE * f = fopen("bongda.txt","r");
  if(f==NULL){
    printf("cannot open file .txt\n");
    return 0;
  }
  char c;
  int count = 0;
  while((c=fgetc(f))!=EOF){
    if(c=='\n') count++;
  }
  
  fclose(f);
  return count;
}

void getData(BSTnode **root,int n){
  FILE * fr = fopen("bongda.txt", "r");
  if(fr==NULL){
    printf("Cannot open file .txt\n");
    return;
  }

  BSTtype temp[20];
  for(int i=1;i<=2*n;i++){
    temp[i].score = 0;
  }
  
  Match match[10];
  int count = 0;
  for(int i=1;i<=n;i++){
    count++;
    int a,b;
    char c;
    fscanf(fr,"%s%s%d%d",temp[count].ID,temp[count+1].ID,&a,&b);
    if(a>b){
      temp[count].score +=3;
      temp[count+1].score +=0;
    }
    if(a==b){
      temp[count].score +=1;
      temp[count+1].score +=1;
    }
    if(a<b){
      temp[count].score +=0;
      temp[count+1].score +=3;
    }
    BSTinsertNode(root,temp[count]);
    printf("Node number %d created\n", count);
    BSTinsertNode(root,temp[count+1]);
    printf("Node number %d created\n", count+1);
    count++;
  }

  /*
  int count = 0;
  for(int i=1;i<=n;i++){

    strcpy(temp[count++].ID,match[i].team1);
    strcpy(temp[count++].ID,match[i].team2);

    int a = match[i].score1;
    int b = match[i].score2;

    if(a>b){
      temp[count-1].score +=3;
      temp[count].score +=0;
    }
    if(a==b){
      temp[count-1].score +=1;
      temp[count].score +=1;
    }
    if(a<b){
      temp[count-1].score +=0;
      temp[count].score +=3;
    }

    BSTinsertNode(&root,temp[count-1]);
    BSTinsertNode(&root,temp[count]);
  
    }*/
  
  fclose(fr);
  return;
}


int main(){
  BSTnode *root;
    BST_initial(&root);

  int n = countLines("bongda.txt","r");
  
   int choice;
   do{
     printf("\n\n1.Creat Tree\n");
     printf("2.Result\n");
     printf("3.Search\n");
     printf("4.Lower\n");
     printf("5.Print out File\n");
     printf("6.Exit\n");
     printf("Enter your choice: ");
     scanf("%d", &choice);
     switch(choice){
     case 1:{
       printf("%d\n",n);
       getData(&root,n);
       
       //   inOrder(root);
       break;
     }
     case 2:{     
       printf("%-10s%-5s\n","Team","Score");
       inOrder(root);
       break;
     }
     case 3:{
       char id[10];
       printf("Enter the ID: ");
       scanf("%s",id);
       BSTnode *temp = searchByID(root,id);
       if(temp == NULL){
	 printf("ID not existed\n");
	 break;
       } 
       printf("%-10s%-5s\n","Team","Score");
       printf("%-10s%-5d\n",temp->data.ID,temp->data.score);
       break;
     }
     case 4:{
       int min;
       printf("Input your minimum score: ");
       scanf("%d",&min);
       BSTnode *temp;
       printf("The lowest teams: \n");
       printf("%-10s%-5s\n","Team","Score");
	 temp = searchByScore(root,min);
	 printf("%-10s%-5d\n",temp->data.ID,temp->data.score);
	 deleteBSTnodeByScore(&root,temp->data.score);
       
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
