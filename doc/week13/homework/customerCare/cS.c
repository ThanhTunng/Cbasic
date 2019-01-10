#include <stdio.h>
#include "BST.h"

int main(){
  FILE *fr = fopen("topCare.txt","r");
  if(fr==NULL){
    printf("cannot open file.\n");
    return 1;
  }
    
  Node *root;
  initNode(&root);
  
  dataType arr[100];

  int i=0;
  while(!feof(fr)){
    fscanf(fr, "%s" , arr[i].id);
    fscanf(fr, "%s" , arr[i].name);
    fscanf(fr, "%s" , arr[i].total);
    fscanf(fr, "%s" , arr[i].food);
    fscanf(fr, "%s" , arr[i].electronics);
    fscanf(fr, "%s" , arr[i].gartment);
    i++;
  } 
  printf("%s%15s%20s%10s  %10s%10s\n", "ID", "Name", "Total", "Food", "Electronics", "Gartment");
  for(int j=0;j<=i;j++){
    insertNode(&root,arr[j]);
  }

  inOrder(root);
  return 0;

}
