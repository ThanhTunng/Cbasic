#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dataType{
  char name[30];
}dataType;

typedef struct Node{
  dataType data;
  struct Node *leftC;
  struct Node *rightC;
}Node;

void initNode(Node **root){
  (*root) = NULL;
  return;
}

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
      int l1 = strlen(data.name)-1;
      int l2 = strlen((*root)->data.name)-1;
      
      char buff1[20];
      for(int i=l1;i>=0;i--){
	if(data.name[i]!= ' '){
	  buff1[l1-i] = data.name[i];
	}
	else break;
      }

      char buff2[20];
      for(int i=l2;i>=0;i--){
	if((*root)->data.name[i]!= ' '){
	  buff2[l2-i] = (*root)->data.name[i];
	}
	else break;
      }
      
      if(strcmp(buff1,buff2)<0){
	insertNode(&((*root)->leftC),data);
      }
      else if(strcmp(buff1,buff2)>0){
	insertNode(&((*root)->rightC),data);
      }
      else{
	if(strcmp((*root)->data.name,data.name) >0){
	  insertNode(&((*root)->leftC),data);
	}else{
	  insertNode(&((*root)->rightC),data);
	}
      }
    return;
  }

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
/*
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
*/
void inOrder(Node *root){
  if(root == NULL){
    return;
  }else{
    inOrder(root->leftC);
    printf("%s\n",root->data.name);
    inOrder(root->rightC);
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
  

void displayNode(Node *node){
  node->data.id[strlen(node->data.id)-1] ='\0';
  node->data.name[strlen(node->data.name)-1] ='\0';
  node->data.total[strlen(node->data.total)-1] ='\0';
  node->data.food[strlen(node->data.food)-1] ='\0';
  node->data.electronics[strlen(node->data.electronics)-1] ='\0';
  node->data.gartment[strlen(node->data.gartment)-1] ='\0';
  
  printf("%s%s%s%s%s%s\n",node->data.id,node->data.name,node->data.total,node->data.food,node->data.electronics,node->data.gartment);
  return;
  }*/

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
