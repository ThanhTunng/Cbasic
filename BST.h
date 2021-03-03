#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int BSTtype;

typedef struct Node{
  BSTtype data;
  struct Node *leftC;
  struct Node *rightC;
}BSTnode;

void BST_initial(BSTnode **root){
  (*root) = NULL;
  return;
}

BSTnode * newBSTnode(BSTtype data){
  BSTnode *newNode = (BSTnode*)malloc(sizeof(BSTnode));

  newNode->data = data;
  newNode->leftC = NULL;
  newNode->rightC = NULL;
  return newNode;
}

BSTnode *creatBSTtree(BSTnode *treeLeft, BSTnode *treeRight, BSTtype dat){
  BSTnode *root = newBSTnode(dat);
  root->leftC = treeLeft;
  root->rightC = treeRight;
  return (root);
}

void BSTinsertNode(BSTnode **root,BSTtype data){
  
  if(*root == NULL){
    BSTnode *newNode = newBSTnode(data);
    *root = newNode;
    return;
  }else{
    if((*root)->data > data){
      BSTinsertNode(&((*root)->leftC),data);
    }else{
    BSTinsertNode(&((*root)->rightC),data);
    }
    return;
  }
}

BSTnode * BSTfindMax(BSTnode *root){
  if(root == NULL) return NULL;

  BSTnode *max = root;

  while(max->rightC != NULL){
    max = max->rightC;
  }
  return max;
}

BSTnode *BSTfindMin(BSTnode *root){
  if(root == NULL) return NULL;

  BSTnode *min = root;

  while(min->leftC != NULL){
    min = min->leftC;
  }
  return min;
}
/*
BSTnode *search(BSTnode *root,char *email){
  if (root == NULL) {
		return(NULL);
	}

	if (strcmp(root->data.email, email) == 0) return(root);

	if (strcmp(root->data.email, email) > 0 )
		return( search(root->leftC, email) );
	else
		return( search(root->rightC, email) );
}
*/
void inOrder(BSTnode *root,FILE *fw){
  if(root == NULL){
    return;
  }else{
    inOrder(root->leftC,fw);
    fprintf(fw,"%s\n",root->data);
    inOrder(root->rightC,fw);
  }
  return;
}
/*
void preOrder(Node *root){
  if(root==NULL) return;
  printf("%s",root->data.email);
  preOrder(root->leftC);
  preOrder(root->rightC);
  return;
}

void postOrder(Node *root){
  if(root==NULL) return;
  postOrder(root->leftC);
  postOrder(root->rightC);
  printf("%s",root->data.email);
  return;
  }*/

void BSTdisplayNode(BSTnode *node){
 
  return;
}
/*
BSTtype BSTdeleteMin(BSTnode **root){
  BSTtype key;

  if((*root)->leftC == NULL){
    key = (*root)->data;
    (*root) = (*root)->rightC;
    return key;
  }
  else{
    return deleteMin(&(*root)->leftC);
  }
}
/*
void deleteNode(char *email, Node **root){
  if((*root) == NULL) return;
  else{
    if(strcmp((*root)->data.email,email) > 0){
      deleteNode(email,&((*root)->leftC));
    }else if(strcmp((*root)->data.email,email) <=0){
      deleteNode(email,&((*root)->rightC));
    }else if(((*root)->leftC == NULL) && ((*root)->rightC == NULL)){
      (*root)=NULL;
    }else if(((*root)->leftC == NULL)){
      (*root) = (*root)->rightC;
    }else if(((*root)->rightC == NULL)){
      (*root) = (*root)->leftC;
    }else{
      (*root)->data =deleteMin(&((*root)->rightC));
    }
  }
  return;
}
*/
