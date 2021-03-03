#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone{
  	char name[30];
	char tel[30];
	char email[30];
}phone;

typedef struct node {
  phone * contact;
  struct node *next;
} NODE;

/*--------------------------------------------------------------*/

node *root = NULL;
node *cur = NULL;
node *prev = NULL;
node *last = NULL;

/* ------------------------------------------------------------ */

node *makeNode(phone *contact) {

	node *newNode = (node *)malloc( sizeof(node) );

	newNode->contact = contact;
	newNode->next = NULL;
	
	return(newNode);
}

void readNode(node *newNode){
  newNode = makeNode();
	printf("Name  : ");
	fgets(newNode->name, 30, stdin);
	newNode->name[ strlen(newNode->name) - 1 ] = '\0';
	
	printf("tel   : ");
	fgets(newNode->tel, 30, stdin);
	newNode->tel[ strlen(newNode->tel) - 1 ] = '\0';
	
	printf("email : ");
	fgets(newNode->email, 30, stdin);
	newNode->email[ strlen(newNode->email) - 1 ] = '\0';
   
}

void displayNode(node *node) {

	printf("%-15s%-15s%-15s\n", node->name, node->tel, node->email);
	return;
}

void printList() {

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

void freeList() {

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


void delFirst{
  node * temp = (node *)malloc(sizeof(node));
  temp = root;
  root = temp->next;
  free(temp);
}

void delFromMiddle{
  if(cur == root){
    delFirst();
    return;
  }
  
  prev->next = cur->next;
  free(cur);
  cur = prev->next;
}

int main() {
  
  node * p = (node *)malloc(sizeof(node));
  p = makeNode();
  readNode(p);

  delFirst();
  printList();

  freeList(root);
  free(p);

  return(0);
} 
