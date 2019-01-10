#include <string.h>

typedef struct {
	char name[20];
	char id[10];
	float grade;
} student;

typedef struct node {
	student *info;
	struct node *next;
} node;

typedef struct {
	node *root;
	node *last;
} singleLinkedList;

void clear_buffer() {
	while (getchar() != '\n')
		;
	return;
}

void init_list(singleLinkedList *list) {

	list->root = NULL;
	list->last = NULL;
	return;
}

node *makeNode(student *info) {
	
	node *newnode = (node *)malloc( sizeof(node) );

	newnode->info = info;
	newnode->next  = NULL;
	
	return(newnode);
}

student *getInfo() {
	
	student *info = (student *)malloc( sizeof(student) );

	printf("name : ");
	fgets(info->name, 20, stdin);
	info->name[ strlen(info->name) - 1 ] = '\0';

	printf("ID : ");
	scanf("%s", info->id);
	clear_buffer();
	
	printf("Grade : ");
	scanf("%f", &(info->grade));
	clear_buffer();
	
	return(info);
}

void displayNode(node *node) {

	printf("%-20s%-10s%-10.1f\n", \
		   node->info->name, \
		   node->info->id, \
		   node->info->grade); 
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

void insertLast(singleLinkedList *list, student *info) {

	node *newnode = makeNode(info);

	if (list->last == NULL) {
		list->last = list->root = newnode;
		return;
	}

	list->last->next = newnode;
	list->last = newnode;
	
	return;
}

void insertAfter(singleLinkedList *list, node *targetNode, student *info) {

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

void insertBefore(singleLinkedList *list, node *targetNode, student *info) {

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

void delete(singleLinkedList *list,  node *target) {

	if (target == list->root) {
		list->root = list->root->next;
		return;
	}

	node *curr = list->root;
	node *prev = NULL;

	while (curr != NULL && curr != target) {
		prev = curr;
		curr = curr->next; 
	}

	if (curr == NULL) {
		printf("Node not  in list !\n");
		return;
	}

	if (curr == list->last) {
		prev->next = NULL;
		list->last = prev;
		return;
	}

	prev->next = curr->next;
	free(curr);
	return;
}
