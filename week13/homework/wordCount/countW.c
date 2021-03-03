#include <stdio.h>
#include "countW.h"
#include <stdlib.h>
#define COUNT 10
void getData(char *fin, BSTnode **root){
  FILE *f = fopen(fin,"r");
  if(f == NULL){
    printf("cannot open file\n");
    return;
  }else{
    dataType temData;

    while(fscanf(f, "%s", temData.word) == 1 ){
      temData.count =1;

      if(search((*root),temData) != NULL){
	BSTnode *temp = search((*root),temData);
	temp->data.count = temp->data.count + 1;
      }else{
	insertBSTnode(root,temData);
      }
    }
    return;
  }
  fclose(f);
}


int main()
{
  BSTnode *root;
  BSTnode_init(&root);

  getData("countW.txt",&root);
  inOrder(root);
  return 0;
}
