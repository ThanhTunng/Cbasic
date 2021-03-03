#ifndef _ABC_H
#define _ABC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int dataTypeTree;
typedef struct treeNode{
  dataTypeTree data ;
  struct treeNode *leftC;
  struct treeNode *rightC;
}treeNode;

void initTree(treeNode **root){
  *root = NULL;
  return;
}
treeNode *makeNode(dataTypeTree data){
  treeNode *newNode = (treeNode*)malloc(sizeof(treeNode));

  newNode->data = data;
  newNode->leftC = NULL;
  newNode->rightC = NULL;
  return newNode;
}
treeNode *creatTreeFrom2(treeNode *treeL, treeNode *treeR,dataTypeTree rootData){
  treeNode *root = makeNode(rootData);
  root->leftC = treeL;
  root->rightC = treeR;

  return root;
  
}
#endif 
