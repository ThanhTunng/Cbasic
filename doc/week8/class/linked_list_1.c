#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char name[30];
	char tel[30];
	char email[30];
	struct node *next;
} node;

/*--------------------------------------------------------------*/

node *root = NULL;
node *last = NULL;

/* ------------------------------------------------------------ */

node *makeNode() {

	node *newNode = (node *)malloc( sizeof(node) );

	printf("Name  : ");
	fgets(newNode->name, 30, stdin);
	newNode->name[ strlen(newNode->name) - 1 ] = '\0';
	
	printf("tel   : ");
	fgets(newNode->tel, 30, stdin);
	newNode->tel[ strlen(newNode->tel) - 1 ] = '\0';
	
	printf("email : ");
	fgets(newNode->email, 30, stdin);
	newNode->email[ strlen(newNode->email) - 1 ] = '\0';

	newNode->next = NULL;
	
	return(newNode);
}

void displayNode(node *node) {

	printf("%-15s%-15s%-15s\n", node->name, node->tel, node->email);
	return;
}

void printList(node *root) {

	if (root == NULL) {
		printf("The list is empty! \n");
		return;
	}

	node *temp;

	for (temp = root; temp != NULL; temp = temp->next) {
		displayNode(temp);
	}
	
	return;
}

void freeList(node *root) {

	if (root == NULL) return;
	
	node *temp = root;

	while (temp != NULL) {
		free(temp);
		temp = temp->next;
	}
	
	return;
}

void insertLast() {

	node *newnode = makeNode();

	if (last == NULL) {
		root = last = newnode;
		return;
	} else {
		last->next = newnode;
		last = newnode;
	}

	return;
}

void insertAfter(node *targetNode) {

	node *newnode = makeNode();
	
	if (targetNode->next == NULL) {
		targetNode->next = newnode;
		last = newnode;
	} else {
		node *temp;
		
		temp = targetNode->next;
		targetNode->next = newnode;
		newnode->next = temp;
	}

	return;
}

void insertBefore(node *targetNode) {

	node *newnode = makeNode();

	node *current = root;
	node *previous = NULL;

	while (current != targetNode && current != NULL) {
		previous = current;
		current = current->next;
	}

	if (current == NULL) {
		printf("the target node is not in list !\n");
		return;
	}

	previous->next = newnode;
	newnode->next = current;
	return;
}

void insertAtposition(int pos) {

	if (pos < 0) {
		printf("positon can not negative ! \n");
		return;
	}
	
	node *current = root;
	int index = 1;

	while (current != NULL) {
		current = current->next;
		index ++;

		if (index == pos) {
			insertAfter(current);
			return;
		}
	}

	insertLast();

	return;
}


int main() {

	insertLast();
	insertLast();
	insertLast();
	insertLast();

	//insertBefore(root->next);
	//insertAfter(root->next);
	insertAtposition(2);

	printList(root);

	freeList(root);
	return(0);
} 
