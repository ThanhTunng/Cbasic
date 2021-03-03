#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue_ll.c"

void readFiletoQueue(FILE *stream, Queue **Q){
	char buff[20];
	while(fscanf(stream, "%s", buff) != EOF){
		treeNode *temp = newNode(buff);
		enQueue(Q, temp);
	}
}

void makeGame(Queue **Q, treeNode **root){
	while(queueSize(*Q) > 1){
		treeNode *node1 = deQueue(Q);
		treeNode *node2 = deQueue(Q);
		treeNode *node3 = newNode(node1->data);
		node3->left = node1;
		node3->right = node2;
		enQueue(Q, node3);
	}
	*root = deQueue(Q);
}

int main(int argc, char const *argv[]){
	Queue *Q = creatQueue();
	FILE *fin = fopen("usopen.txt", "r");
	readFiletoQueue(fin, &Q);
	treeNode *root = NULL;
	// traversing(Q);
	makeGame(&Q, &root);
	printLevelOrder(root);
}
