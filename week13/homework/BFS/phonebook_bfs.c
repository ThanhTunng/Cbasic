#include <stdio.h>
#include <stdlib.h>
#include "bTree.h"
#include "queue.h"
/*
int readData(char *fn, dataTypeTree arr[]) {

	FILE *f = fopen(fn, "r");
	if (f == NULL) {
		printf("Can not open file %s \n", fn);
		return(-1);
	}

	int i;
	for (i = 0; !feof(f);  i++) {
		fgets(arr[i].name, 100, f);
	}

	fclose(f);
	return(i);
}
*/
treeNode *pickOne(treeNode *one, treeNode *two) {
	int r = rand() % 2;
 
	if (r == 0) {
		return(one);
	}
	else {
		return(two);
	}
}

treeNode *buildTree(dataTypeTree arr[], int n) {

	int i;
	treeNode *treeNodeArray[n];
	
	for (i = 0; i < n; i++) {
		treeNodeArray[i] = makeNewTreeNode(arr[i]);
	}

	int j = -1;
	int index = -1;
	while (n != 1) {
		j = -1;
		index = -1;
		while (j < n) {
			treeNode *one = treeNodeArray[++j];
			treeNode *two = treeNodeArray[++j];
			treeNodeArray[++index] = createTreeFrom2(one, two, pickOne(one, two)->data);
		}

		n = n / 2;
	}
	
	return(treeNodeArray[0]);
}

void bfs(treeNode *root) {

	queue *Q = (queue *) malloc(sizeof(queue));
	queue_init(Q);

	treeNode *temp = root;

	while (temp != NULL) {
		displayTreeNode(temp);

		if (temp->left != NULL) {
			enQueue(Q, temp->left);
		}

		if (temp->right != NULL) {
			enQueue(Q, temp->right);
		}

		temp = deQueue(Q);
		
	}
	return;
}

int main() {

	dataTypeTree arr[100];
	
	//int n = readData("USopen.txt", arr);

	//treeNode *root = buildTree(arr, n);

	treeNode *root;
	tree_init(&root);

	root = makeNewTreeNode(1);
	root->left = makeNewTreeNode(2);
	root->right = makeNewTreeNode(3);
	root->left->left = makeNewTreeNode(4);
	root->left->right = makeNewTreeNode(5);
	bfs(root);
	return(0);
}


