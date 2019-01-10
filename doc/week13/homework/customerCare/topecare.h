#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char id[30];
  char name[50];
  int TP;
  int DT;
  int MM;
  int max;
}dataTypeTC;

typedef struct TCnode{
  dataTypeTC data;
  struct TCnode *left;
  struct TCnode *right;
}TCnode;

int compare(dataTypeTC rootData, dataTypeTC data){

  if(( rootData.max - data.max) > 0){
    return 1;
  }else if((rootData.max - data.max == 0)){
    return 0;
  }else return -1;
}

void displayTCnode(TCnode *root){

  printf("%s %-20s %d %d %d\n",
	 root->data.id,
	 root->data.name,
	 root->data.TP,
	 root->data.DT,
	 root->data.MM);

  return;
}

TCnode *makeTCnode(dataTypeTC data){

  TCnode *newNode = (TCnode*)malloc(sizeof(TCnode));

  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return(newNode);
}

void TCnode_init(TCnode **root){
  *root = NULL;

  return;
}

TCnode *findMin(TCnode *root){

  if(root == NULL){
    return NULL;
  }else{
    TCnode *min = root;
    while(min->left != NULL){
      min = min->left;
    }

    return(min);
  }
}

TCnode *findMax(TCnode *root){

  if(root == NULL) return NULL;
  else{
    TCnode *max = root;
    while(max->right != NULL){
      max = max->left;
    }

    return(max);
  }
}

TCnode *search(TCnode *root, dataTypeTC data){

  if(root == NULL) return NULL;

  if( compare(root->data,data) == 0) return root;

  if( compare(root->data,data) < 0){
    return(search(root->left,data));
  }else{
    return(search(root->right,data));
  }
}

void insertTCnode(TCnode **root,dataTypeTC data){
  if(*root == NULL){
    TCnode *newNode = makeTCnode(data);
    *root = newNode;

    return;
  }else if( compare((*root)->data, data) == 1){
    insertTCnode(&(*root)->left,data);
  }else if( compare((*root)->data, data) == -1){ 
    insertTCnode(&(*root)->right,data);
  }
}

void inOrder(TCnode *root){
  if(root == NULL) return;
  else{
    inOrder(root->left);
    inOrder(root->right);
    displayTCnode(root); 
  }
}
