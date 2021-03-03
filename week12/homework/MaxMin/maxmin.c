#include <stdio.h>
#include "binaryTree.h"
/*
int input(char *file,char buff[]){
  FILE *fr = fopen(file,"r");
  if(fr==NULL){
    printf("Cannot open file.\n");
    return -1;
  }
  int i=0;
  while(!feof(fr)){
    fscanf(fr, "%s ", buff[i]);
    i++;
  }
  fclose(fr);
  return i;
}*/

int main(){
  printf("3\n");
  makeNULLTree(&tree);
  printf("1\n");
  (*tree).val = 5;
  printf("2\n");
  tree->left->val = 4;
  tree->right->val = 6;
  printf("56\n");
  printf("%d", findMax(tree));
  return 0;
}
