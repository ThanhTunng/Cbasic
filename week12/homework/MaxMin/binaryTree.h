#include <stdlib.h>
#include <time.h>

typedef int type;

typedef struct node{
  type val;
  struct node *left;
  struct node *right;
}node;

node *tree;

void makeNULLTree(node **tree){
  (*tree) = NULL;
  return;
}

int isEmpty(node *tree){
  if(tree == NULL) return 1;
  return 0;
}

node *newNode(type data){
  node *new = (node *)malloc(sizeof(node));
  new->val = data;
  new->left = NULL;
  new->right = NULL;
  return new;
}

node *leftChild(node *tree){
  if(tree!=NULL) return tree->left;
  return NULL;
}

node *rightChild(node *tree){
  if(tree!=NULL) return tree->right;
  return NULL;
}

int numOfNode(node *tree){
  if(isEmpty(tree)==1) return 0;
  else return (1 + numOfNode(tree->left) + numOfNode(tree->right));
}

int isLeaf(node *tree){
  if(tree!=NULL) return ((tree->left)==NULL && (tree->right)==NULL);
  return 0;
}

node *creatTree(node *l,node *r,type dat){
  node *newTree = (node *)malloc(sizeof(node));
  newTree->left = l;
  newTree->right = r;
  newTree->val = dat;
  return newTree;
}

node *addLeftChild(node *tree,type data){
  node *new = newNode(data);
  if(tree==NULL){
    tree = new;
    return tree;
  }
  else{
    node * temp = tree;
    while(temp!=NULL) temp = temp->left;
    temp->left = new;
  }
  return new;
}

node *addRightChild(node *tree,type data){
  node *new = newNode(data);
  if(tree==NULL){
    tree = new;
    return tree;
  }
  else{
    node * temp = tree;
    while(temp!=NULL)
      temp = temp->right;
    temp->right = new;
  }
  return new;
}


int height(node *tree){
  if(tree==NULL) return 0;
  else{
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    if(lheight>rheight) return 1+lheight;
    else return 1+rheight;
  }
}
/*
node *find(node *tree,type target){
  if(tree==NULL){
    printf("The tree is empty\n");
    return NULL;
  }
  if((*tree).val == target) return tree;
  node *temp = tree
}*/

type findMax(node *tree){
  if(tree==NULL){
    printf("The tree is empty\n");
    return 0;
  }
  type max = (*tree).val;
  type max1 = findMax(tree->left);
  type max2 = findMax(tree->right);

  if(max1>max2) return (max = (max1>max)? max1:max);
  else return (max = (max2>max)? max2:max);
}

type findMin(node *tree){
  if(tree==NULL){
    printf("The tree is empty\n");
    return 0;
  }
  type min = (*tree).val;
  type min1 = findMin(tree->left);
  type min2 = findMin(tree->right);

  if(min1<min2) return (min = (min1<min)? min1:min);
  else return (min = (min2<min)? min2:min);

}

void insertTree(node *tree,type dat){
  if(tree==NULL){
    node *new =newNode(dat);
    tree = new;
    return;
  }
  if(tree->val > dat) insertTree(tree->left,dat);
  else insertTree(tree->right,dat);
  return;
}

/*void inOrder(node *tree){
  if(isEmpty(tree)==1){
    printf("The tree is empty\n");
    return;
  }
  type dat;
  }*/
