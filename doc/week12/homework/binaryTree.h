#include <string.h>
#include <stdlib.h>

typedef int type;

typedef struct node{
  type val;
  struct node *left;
  struct node *right;
}node;

node *tree;

void makeNULLTree(node *tree){
  (*tree) = NULL;
  return;
}

int isEmpty(node *tree){
  if(*tree = NULL) return 1;
  return 0;
}

node *newNode(type data){
  new = (node *)malloc(sizeof(node));
  new->val = data;
  new->left = NULL;
  new->right = NULL;
  return new;
}

node *leftChild(node *tree){
  if((*tree)!=NULL) return tree->left;
  return NULL;
}

node *rightChild(node *tree){
  if((*tree)!=NULL) return tree->right;
  return NULL;
}

int numOfNode(node *tree){
  if(isEmpty(tree)==1) return 0;
  else return (1 + numOfNode(tree->left) + numOfNode(tree->right));
}

int isLeaf(node *tree){
  if((*tree)!=NULL) return ((tree->left)=NULL && (tree->right)=NULL);
  return 0;
}

node *creatTree(node *l,node *r,type dat){
  node *newTree = (node *)malloc(sizeof(Node));
  newTree->left = l;
  newTree->right = r;
  newTree->val = dat;
  return newTree;
}

node *addLeftChild(node *tree,type data){
  node *new = newNode(data);
  if((*tree)==NULL){
    tree = new;
    return tree;
  }
  else{
    node * temp = tree;
    while((*temp)!=NULL) temp = temp->left;
    temp->left = new;
  }
  return new;
}

node *addRightChild(node *tree,type data){
  node *new = newNode(data);
  if((*tree)==NULL){
    tree = new;
    return tree;
  }
  else{
    node * temp = tree;
    while((*temp)!=NULL)
      temp = temp->right;
    temp->right = new;
  }
  return new;
}


int height(node *tree){
  if((*tree)==NULL) return 0;
  else{
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    if(lheight>rheight) return 1+lheight;
    else return 1+rheight;
  }
}

void inOrder(node *tree){
  if(isEmpty(tree)==1){
    return;
  }
  inOrder(tree->left);
  printf("%d", (*tree).val);
  inOrder(tree->right);
  return;
}

void insertTree(node *tree,type dat){
  if(tree==NULL){
    node *new = newNode(dat);
    tree = new;
    return;
  }

  if(tree->val > dat) insertTree(tree->left, )
  
}
    
  
