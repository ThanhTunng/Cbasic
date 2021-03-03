#include <stdio.h>
#include "binaryTree.h"
#include <time.h>

#define COUNT 10

typedef struct{
  char name[100];
}player;

int readData(char *fn, player arr[]) {

	FILE *f = fopen(fn, "r");
	if (f == NULL) {
		printf("Can not open file %s \n", fn);
		return(-1);
	}

	int i;
	
	for (i = 0; !feof(f);  i++) {
		fgets(arr[i].name, 100, f);
Node *build(player arr[],int n){
  int i;
  Node *nodeArr[n];

  for(i=0;i<n;i++){
    nodeArr[i] = makeNode(arr[i].name);
  }

  int j;
  int index;

  while(n != 1){
    j=-1;
    index=-1;
    while(j < n){
      Node *one = nodeArr[++j];
      Node *two = nodeArr[++j];
      nodeArr[++index] = creatTreeFrom2(one,two,pickWin(one,two)->element);
    }
    n = n/2;
  }

  return(nodeArr[0]);
}

void print2DU(Node *root,int space,FILE *f){
  if(root == NULL) return;

  space += COUNT;
  print2DU(root->rightChild,space,f);

  fprintf(f,"\n");

  for(int i=space;i>COUNT;i--)
  fprintf(f," ");
  
    fprintf(f,"%s",root->element);

  print2DU(root->leftChild,space,f);
}

void print2D(Node *root,FILE *f){
  print2DU(root,0,f);
}

void exportData(char *fn,Node *root) {
	
	FILE *f = fopen(fn, "w+");
   
	print2D(root, f);
	return;
} 

int main() {

	player arr[100];
	int n = readData("USopen.txt", arr);

	Node *root = build(arr, n);

	exportData("treegame.txt", root);
	return (0);
}
