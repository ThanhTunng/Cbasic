#include <stdio.h>
#include "BST.h"

int count=0;

int tower(char a, char b, char c,int n){
  if(n==1){
    count++;
    printf("Step %d: Move 1 dish from %c to %c\n",count, a, c);
    return count;
  }
  else{
    tower(a,c,b,n-1);
    tower(a,b,c,1);
    tower(b,a,c,n-1);
    return count;
  }
}

int main(){

  BSTnode *root;
  BST_initial(&root);
  FILE * fw = fopen("bst.txt","w+");
  if(fw==NULL){
    printf("cannot open file\n");
    return 0;
  }
  
  BSTtype arr[] = {3,1,2,4,6,5,9,8,7};
  for(int i=0;i<9;i++){
    BSTinsertNode(&root,arr[i]); 
  }
  inOrder(root,fw);
  return 0;
}
