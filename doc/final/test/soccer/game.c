#include <stdio.h>
#include <string.h>
#include "singleLinkedList.h"
#define MAX 100

typedef struct Match{
  int id1;
  int id2;
  int scoreId1;
  int scoreId2;
}Match;

typedef struct vongdau{
  Match match[10];
}Round;

SLLnode *searchByID(SLL *list,int n,int key){
  SLLnode *temp = list->root;
  for(int i=1;i<=n;){
    if(temp->data.id==key) return temp;
    temp = temp->next;
  }
  return NULL;
}

SLLnode *searchByScore(SLL *list,int n,int key){
  SLLnode *temp = list->root;
  for(int i=1;i<=n;){
    if(temp->data.score==key) return temp;
    temp = temp->next;
  }
  return NULL;
}

int readFile(SLL *list,Round round[]){

  FILE * fr = fopen("bongda.txt","r");
  if(fr==NULL){
    printf("cannot open file\n");
    return 0;
  }
  
  int n;
  fscanf(fr,"%d",&n);
  SLLtype type;
  for(int i = 1;i<=n;i++){
    fscanf(fr,"%d%[^\n]s",&type.id,type.name);
    //  type.name[strlen(type.name)-1] = '\0';
    type.score = 0;
    type.win = 0;
    type.lose = 0;
    SLLinsertLast(&list,type);
  }

  char tempStr[10];
  for(int i=1;i<n;i++){
    fgets(tempStr,100,fr);
    fgets(tempStr,100,fr);
    for(int j=1;j<=(n/2);j++){
      fscanf(fr,"%d%d",&round[i].match[j].id1,&round[i].match[j].id2);
      round[i].match[j].scoreId1 = 0;
      round[i].match[j].scoreId2 = 0;
    }
    
  }
  return n;
}

void updateScore(SLLnode **root,int n,int key,int mark,int w,int l){
  SLLnode * temp = *root;
  for(int i=1;i<=n;){
    if(temp->data.id == key){
      temp->data.score = mark + temp->data.score;
      temp->data.win = w + temp->data.win;
      temp->data.lose = l + temp->data.lose;
      return;
    }
    temp = temp->next;
  }
  return;
}
/*
char *convertIdName(SLL *list,char *key,int n){
  SLLnode* temp = list->root;
  char *str;
  
  for(int i=1;i<=n;i++){
  
    if(atoi(temp->data.id) == atoi(key)){
      strcpy(str,temp->data.name);
    }
    temp = temp->next;
  }
  return str;
}
*/
int main(){
  SLL * list = (SLL *)malloc(MAX*sizeof(SLL));
  Round round[10];
  int n = readFile(list,round);
  int choice;
  do{
    printf("\n***************Tourament SV****************");
    printf("\n1.Print competitors\n");
    printf("2.Print matches\n");
    printf("3.Update\n");
    printf("4.Elimination\n");
    printf("5.Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
    case 1:{
      printf("%-5s%-30s%-10s%-10s%-10s\n","ID","Name","Score","Win","Lose");
      SLLnode * temp;
      temp = list->root;
      for(int i=1;i<=n;i++){
	printf("%-5d%-30s%-10d%-10d%-10d\n",temp->data.id,temp->data.name,temp->data.score,temp->data.win,temp->data.lose);
	temp = temp->next;
  }
      break;
    }
    case 2:{
      for(int i=1;i<n;i++){
	printf("Vong %d\n",i);
	for(int j=1;j<=n/2;j++){
	  int a = round[i].match[j].id1;
	  int b = round[i].match[j].id2;
	  printf("%-15s -vs- %-15s\n",searchByID(list,n,a)->data.name, searchByID(list,n,b)->data.name);
	}
      }
      break;
    }
    case 3:{
        printf("Update: \n");
      for(int i=1;i<n;i++){
	printf("Vong %d\n",i);
	for(int j=1;j<=(n/2);j++){
	  int a = round[i].match[j].id1;
	  int b = round[i].match[j].id2;
	  do{
	  printf("%-10s -vs- %-10s: ",searchByID(list,n,a)->data.name, searchByID(list,n,b)->data.name);	 
	  scanf("%d-%d",&round[i].match[j].scoreId1,&round[i].match[j].scoreId2);
	  }while(round[i].match[j].scoreId1 < 0 || round[i].match[j].scoreId2 < 0);
	  
	  int x = round[i].match[j].scoreId1;
	  int y = round[i].match[j].scoreId2;
	  
	  if(x>y){
	    updateScore(&(list->root),n,a,3,x,y);
	    updateScore(&(list->root),n,b,0,x,y);
	  }
	  else if(x==y){
	    updateScore(&(list->root),n,a,1,x,y);
	    updateScore(&(list->root),n,b,1,x,y);
	  }
	  else if(x<y){
	    updateScore(&(list->root),n,a,0,x,y);
	    updateScore(&(list->root),n,b,3,x,y);
	  }
	}
      }
      
      printf("%-5s%-30s%-10s%-10s%-10s\n","ID","Name","Score","Win","Lose");
      SLLnode * temp;
      temp = list->root;
      for(int i=1;i<=n;i++){
	printf("%-5d%-30s%-10d%-10d%-10d\n",temp->data.id,temp->data.name,temp->data.score,temp->data.win,temp->data.lose);
	temp = temp->next;
      }
      break;
      }
    case 4:{
      
      SLLnode *tempMin = list->root;
     int  min = tempMin->data.score;
      for(int i=2;i<=n;i++){	
	tempMin = tempMin->next;
	if(tempMin->data.score < min){
	  min = tempMin->data.score;
	}
      }
      tempMin = searchByScore(list,n,min);
      printf("The competitor got the lowest score: \n");
      printf("%-5s%-30s%-10s%-10s%-10s\n","ID","Name","Score","Win","Lose");
      
      printf("%-5d%-30s%-10d%-10d%-10d\n",tempMin->data.id,tempMin->data.name,tempMin->data.score,tempMin->data.win,tempMin->data.lose);

      SLLdelete(&list,tempMin);
      
      printf("\nThe rest of competiors are: \n");
      printf("%-5s%-30s%-10s%-10s%-10s\n","ID","Name","Score","Win","Lose");
      SLLnode *temp = list->root;
      for(int i=1;i<n;i++){
	printf("%-5d%-30s%-10d%-10d%-10d\n",temp->data.id,temp->data.name,temp->data.score,temp->data.win,temp->data.lose);
	temp = temp->next;
      }
      break;
    }
    }
  }while(choice!=5);
    
  return 0;
}
