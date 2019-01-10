#include <string.h>

typedef struct {
	char name[20];
	char memory[20];
	float display;
	char price[20];
} phone;

typedef struct node {
	phone *info;
	struct node *next;
} node;

typedef struct {
	node *root;
	node *last;
} singleLinkedList;
	
void init_list(singleLinkedList *list) {

	list->root = NULL;
	list->last = NULL;
	return;
}

node *makeNode(phone *info) {
	
	node *newnode = (node *)malloc( sizeof(node) );

	newnode->info = info;
	newnode->next  = NULL;
	
	return(newnode);
}

void displayNode(node *node) {

	printf("%-15s%-10s%-10.1f%-7s\n", \
		   node->info->name, \
		   node->info->memory, \
		   node->info->display, \
		   node->info->price);
	return;
}

void freeList(singleLinkedList *list) {

	if (list->root == NULL) {
		printf("Free list completed!\n");
		return;
	}

	node *temp = list->root;
	while (temp != NULL) {
		free(temp);
		temp = temp->next;
	}

	printf("Free list completed!\n");

	return;
}

void printList(singleLinkedList *list) {

	if (list->root == NULL) {
		printf("the List is empty!\n");
		return;
	}

	node *temp = list->root;

	while (temp != NULL) {
		displayNode(temp);
		temp = temp->next;
	}
	return;
}

void insertLast(singleLinkedList *list, phone *info) {

	node *newnode = makeNode(info);

	if (list->last == NULL) {
		list->last = list->root = newnode;
		return;
	}

	list->last->next = newnode;
	list->last = newnode;
	
	return;
}

void insertAfter(singleLinkedList *list, node *targetNode, phone *info) {

	if (targetNode->next == NULL) {
		insertLast(list, info);
		return;
	}

	node *newnode = makeNode(info);
	node *temp = targetNode->next;
	
	targetNode->next = newnode;
	newnode->next = temp;
	return;
}

void insertBefore(singleLinkedList *list, node *targetNode, phone *info) {

	if (targetNode == list->root) {
		node *newnode = makeNode(info);
		newnode->next = list->root;
		list->root = newnode;
		return;
	}

	node *current = list->root;
	node *previous = NULL;
	while (current != targetNode && current != NULL) {
		previous = current;
		current = current->next;
	}

	if (current == NULL) {
		printf("The target node is not in list '\n");
		return;
	}

	node *newnode = makeNode(info);
	
	previous->next = newnode;
	newnode->next = current;
	
	return;
}

void insertAtPosition(singleLinkedList *list, int pos, phone *info) {

	if (pos < 0) {
		printf("The position can not negative!\n");
		return;
	}


	if (pos == 0) {

		node *newnode = makeNode(info);
		if (list->root == NULL) {
			list->root = newnode;
			list->last = newnode;
		} else {
			newnode->next = list->root;
			list->root = newnode;
		}

		return;
	}

	
	node *current = list->root;
	int index = 1;

	while (current != NULL) {
		current = current->next;
		index ++;

		if (index == pos) {
			insertAfter(list, current, info);
			return;
		} 
	}

	// id the pos is larger than the length of the list, insert last
	insertLast(list, info);
	return;
}
