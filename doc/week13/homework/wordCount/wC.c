#include <stdio.h>
#include "BST.h"

int getData(dataType arr[],Node *root){
  FILE *fr = fopen("text.txt","r");
  if(fr==NULL){
    printf("cannot open file\n");
    return 0;
  }
  
  int i=0;
  while(!feof(fr)){
    if(i==0){
      fscanf(fr, "%s", arr[i].word);
      arr[i].freq +=1;
    }else{
      char buff[10];
      fscanf(fr, "%s", buff);

      int flag=0;

      for(int j=0;j<i;j++){
	if(strcmp(buff,arr[j].word)==0){
	  arr[j].freq +=1;
	  flag = 1;
	}
       }
       
       if(flag==0){
	 strcpy(arr[i].word,buff);
	 arr[i].freq +=1;
	}
    }
    i++;
  }
  return i;
  
  /*
  char buff[10];
  while(fscanf(fr, "%s", buff)!=EOF){
    if(search(root,buff)==NULL){
      dataType *temp = (dataType *)malloc(sizeof(dataType));
      strcpy((*temp).word,buff);
      (*temp).freq = 1;
      insertNode(&root,*temp);
    }
    else{
      (*search(root,buff)).data.freq += 1;
    }
  }
  return;*/
}

int main(){
  dataType arr[100];
  for(int i=0;i<100;i++){
    arr[i].freq = 0;
  }

  Node *root;
  initNode(&root);
 
  
  int n = getData(arr,root);
    for(int i=0;i<n;i++){
    insertNode(&root,arr[i]);
    }

  inOrder(root);

  return 0;
}
