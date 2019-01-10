#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char word[50];
  int count;
}dataType;

typedef struct BSTnode{
  dataType data;
  struct BSTnode *left;
  struct BSTnode *right;
}BSTnode;

int compare(dataType rootData, dataType data){

  if(strcmp(rootData.word,data.word) >  1){
    return 1;
  }else if(strcmp(rootData.word,data.word) < 0){
    return -1;
  }else return 0;
}

void displayBSTnode(BSTnode *root){
  printf("%s(%d)\n", root->data.word,root->data.count);
}

BSTnode *makeBSTnode(dataType data){

  BSTnode *newNode = (BSTnode*)malloc(sizeof(BSTnode));

  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return(newNode);
}

void BSTnode_init(BSTnode **root){
  *root = NULL;

  return;
}

BSTnode *search(BSTnode *root, dataType data){

  if(root == NULL) return NULL;

  if( compare(root->data,data) == 0) return root;

  if( compare(root->data,data) == 1){
    return(search(root->left,data));
  }else{
    return(search(root->right,data));
  }
}

void insertBSTnode(BSTnode **root,dataType data){
  if(*root == NULL){
    BSTnode *newNode = makeBSTnode(data);
    *root = newNode;

    return;
  }else if( compare((*root)->data, data) == 1){
    insertBSTnode(&(*root)->left,data);
  }else{ 
    insertBSTnode(&(*root)->right,data);
  }
}
void inOrder(BSTnode *root){
  if(root == NULL) return;
  else{
    inOrder(root->left);
    inOrder(root->right);
    displayBSTnode(root); 
  }
}
