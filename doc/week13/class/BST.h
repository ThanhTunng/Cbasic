#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char dataType;

typedef struct Node{
  dataType data;
  struct Node *leftC;
  struct Node *rightC;
}Node;

Node *makeNode(dataType data){
  Node *newNode = (Node*)malloc(sizeof(Node));

  newNode->data = data;
  newNode->leftC = NULL;
  newNode->rightC = NULL;
  return newNode;
}

void insertNode(Node **root,dataType data){
  
  if(*root == NULL){
    Node *newNode = makeNode(data);
    *root = newNode;
    return;
  }else{
    if(strcmp((*root)->data.email,data.email) >0){
      insertNode(&((*root)->leftC),data);
    }else{
    insertNode(&((*root)->rightC),data);
    }
    return;
  }
}

Node * creatTree(Node *node1, Node *node2,dataType ch){
  Node *root = (Node *)malloc(sizeof(Node));

  root->data = ch;
  root->leftC = node1;
  root->rightC = node2;

  return root;
}

Node *findMax(Node *root){
  if(root == NULL) return NULL;

  Node *max = root;

  while(max->rightC != NULL){
    max = max->rightC;
  }
  return max;
}

Node *findMin(Node *root){
  if(root == NULL) return NULL;

  Node *min = root;

  while(min->leftC != NULL){
    min = min->leftC;
  }
  return min;
}

Node *search(Node *root,char *email){
  if (root == NULL) {
		return(NULL);
	}

	if (strcmp(root->data.email, email) == 0) return(root);

	if (strcmp(root->data.email, email) > 0 )
		return( search(root->leftC, email) );
	else
		return( search(root->rightC, email) );
}

void inOrder(Node *root){
  if(root == NULL){
    return;
  }else{
    inOrder(root->leftC);
    printf("%s",root->data.email);
    inOrder(root->rightC);
  }
  return;
}

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
}

void displayNode(Node *node){
  node->data.name[strlen(node->data.name)-1] ='\0';
  node->data.tel[strlen(node->data.tel)-1] ='\0';
  node->data.email[strlen(node->data.email)-1] ='\0';
  printf("%s\n%s\n%s\n",node->data.name,node->data.tel,node->data.email);
  return;
}
dataType deleteMin(Node **root){
  dataType key;

  if((*root)->leftC == NULL){
    key = (*root)->data;
    (*root) = (*root)->rightC;
    return key;
  }
  else{
    return deleteMin(&(*root)->leftC);
  }
}/*
void deleteNode(char *email, Node *root){
  if(root == NULL) return;
  else{
    if(strcmp(root->data.email,email) > 0){
      deleteNode(email,root->leftC);
    }else if(strcmp(root->data.email,email) <=0){
      deleteNode(email,root->rightC);
    }else if((root->leftC == NULL) && (root->rightC == NULL)){
      root=NULL;
    }else if((root->leftC == NULL)){
      root = root->rightC;
    }else if((root->rightC == NULL)){
      root = root->leftC;
    }else{
      root->data =deleteMin(root->rightC);
    }
  }
  return;
}
 */
