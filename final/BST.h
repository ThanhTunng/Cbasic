
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BSTdataType{
  char ip[20];
  char name[30];
}BSTtype;

typedef struct Node{
  BSTtype data;
  struct Node *leftC;
  struct Node *rightC;
}BSTnode;

void BST_initial(BSTnode **root){
  (*root) = NULL;
  return;
}

BSTnode *newBSTnode(BSTtype data){
  BSTnode *newNode = (BSTnode *)malloc(sizeof(BSTnode));

  newNode->data = data;
  newNode->leftC = NULL;
  newNode->rightC = NULL;
  return (newNode);
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
    if(strcmp((*root)->data.name,data.name)>0){
      BSTinsertNode(&((*root)->leftC),data);
    }/*
    else if(strcmp((*root)->data.ID,data.ID)==0){
      (*root)->data.score += data.score;
      }*/
    else{
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

void inOrder(BSTnode *root){
  if(root == NULL){
    return;
  }else{
    inOrder(root->leftC);
    printf("%-30s%-20s\n",root->data.name,root->data.ip);
    inOrder(root->rightC);
  }
  return;
}

BSTnode *searchInOrder(BSTnode *root,BSTtype type){
  if(root==NULL){
    return NULL;
  }
  else{
    searchInOrder(root->leftC,type);
    if(strcmp(root->data.name,type.name)==0) {return (root);}
    searchInOrder(root->rightC,type);
  }
  return NULL;
}

BSTnode *updateBlock(BSTnode **root,char *str){
  if(*root==NULL){
    return NULL;
  }
  else{
    updateBlock(&((*root)->leftC),str);
    if(strcmp((*root)->data.name,str)==0 ||
       strcmp((*root)->data.ip,str)==0 ){
      strcpy((*root)->data.name,"this site has been blocked");
      return (*root);
    }
    updateBlock(&((*root)->rightC),str);
  }
  return NULL;
}

BSTnode* searchBlock(BSTnode **root,char *str){
  if(*root==NULL){
    return NULL;
  }
  else{
    searchBlock(&((*root)->leftC),str);
    if(strcmp((*root)->data.name,str)==0){
      return NULL;
    }
    searchBlock(&((*root)->rightC),str);
  }
  return NULL;
}

/*
void reverseInOrder(BSTnode *root){
  if(root == NULL){
    return;
  }else{
    reverseInOrder(root->rightC);
    printf("%-10d%-10s\n",root->data.ID,root->data.dochoi);
    reverseInOrder(root->leftC);
  }
  return;
  }*/
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



BSTtype BSTdeleteMin(BSTnode **root){
  BSTtype key;

  if((*root)->leftC == NULL){
    key = (*root)->data;
    (*root) = (*root)->rightC;
    return key;
  }
  else{
    return BSTdeleteMin(&(*root)->leftC);
  }
}
/*
void deleteBSTnode(BSTnode **root,char *key){
  if((*root) == NULL) return;
  else{
    if(strcmp((*root)->data.ID,key) > 0){
      deleteBSTnode(&((*root)->leftC),key);
    }
    
    else if(strcmp((*root)->data.ID,key) < 0){
      deleteBSTnode(&((*root)->rightC),key);
      
    }else if(((*root)->leftC == NULL) && ((*root)->rightC == NULL)){
      (*root)=NULL;
    }else if(((*root)->leftC == NULL)){
      (*root) = (*root)->rightC;
    }else if(((*root)->rightC == NULL)){
      (*root) = (*root)->leftC;
    }else{
      (*root)->data = BSTdeleteMin(&((*root)->rightC));
    }
  }
  return;
  }*/


/*
 void deleteBSTnodeByScore(BSTnode **root,int key){
  if((*root) == NULL) return;
  else{
    if((*root)->data.ID > key){
      deleteBSTnodeByScore(&((*root)->leftC),key);
    }
    
    else if((*root)->data.ID < key){
      deleteBSTnodeByScore(&((*root)->rightC),key);
      
    }else if(((*root)->leftC == NULL) && ((*root)->rightC == NULL)){
      (*root)=NULL;
    }else if(((*root)->leftC == NULL)){
      (*root) = (*root)->rightC;
    }else if(((*root)->rightC == NULL)){
      (*root) = (*root)->leftC;
    }else{
      (*root)->data = BSTdeleteMin(&((*root)->rightC));
    }
  }
  return;
}
/*

BSTnode * searchByID(BSTnode *root,char *key){
  if(root==NULL){
    return NULL;
  }
  searchByID(root->leftC,key);
  
  if(strcmp(root->data.ID,key)==0) return (root);

  searchByID(root->rightC,key);
}

BSTnode *searchByScore(BSTnode *root,int key){
  if(root==NULL){
    return NULL;
  }
  searchByScore(root->leftC,key);
  
  if(root->data.score == key){
    return root;
  };

  searchByScore(root->rightC,key);

}*/

/*
void BSTinsertNode(BSTnode **root,BSTtype data){
  
  if(*root == NULL){
    BSTnode *newNode = newBSTnode(data);
    *root = newNode;
    return;
  }else{
    if((*root)->data.ID>data.ID){
      BSTinsertNode(&((*root)->leftC),data);
    }/*
    else if((*root)->data.ID==data.ID){
      deleteBSTnodeByScore(root,data.ID);
      }*/
/* else{
    BSTinsertNode(&((*root)->rightC),data);
    }
    return;
  }
  }*/
