#include "BST.h"

void getData(dataType arr[],Node *root){
  FILE * fr = fopen("list.txt","r");
  if(fr == NULL){
    printf("cannot open file\n");
    return ;
  }

  int i=0;
  while(!feof(fr)){
    fgets(arr[i].name,50,fr);
    arr[i].name[strlen(arr[i].name)-1] = '\0';
    insertNode(&root,arr[i]);
    i++;
  }
    inOrder(root);
  return;
}

int main(){
  Node *root;
  initNode(&root);
  dataType arr[50];
  
  getData(arr,root);

  return 0;
}
