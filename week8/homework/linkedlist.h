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

phone *getInfo() {
	
	phone *info = (phone *)malloc( sizeof(phone) );

	printf("name : ");
	scanf("%s", info->name);
	printf("Memory : ");
	scanf("%s", info->memory);
	printf("Display : ");
	scanf("%f", &(info->display));
	printf("Price : ");
	scanf("%s", info->price);
	
	return(info);
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

	// if the position num is larger than number of phones -> insert Last
	insertLast(list, info);
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

void deleteFirst(singleLinkedList *list) {
	delete(list, list->root);
	return;
}

void deleteAtPosition(singleLinkedList *list, int pos) {

	// start from 0
	if (pos == 0) {
		delete(list, list->root);
		return;
	}

	if (pos < 0) {
		printf("The position can not be nagative! \n");
		return;
	}

	int index = 0;
	node *tmp = list->root;
	while (tmp != NULL) {
		tmp = tmp->next;
		index++;

		if (index == pos) {
			delete(list, tmp);
			return;
		}
	}
	return;
}

void reverseList(singleLinkedList *list) {

	node *curr = list->root;
	node *next = NULL;
	node *prev = NULL;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	list->root = prev;
	return;
}

void splitFile(char *fin, int size, int n, char *fno1, char *fno2) {

	if (n > size) {
		printf("n Over the number of phones\n");
		return;
	}
	
	FILE *fi = fopen(fin, "rb");

	if (fi == NULL) {
		printf("Can not open file \n");
		return;
	}

	FILE *f1 = fopen(fno1, "w+b");
	FILE *f2 = fopen(fno2, "w+b");

	phone temp;
	for (int i = 0; i < n; i++) {
		fread(&temp, sizeof(phone), 1, fi);
		fwrite(&temp, sizeof(phone), 1, f1);
	}

	fread(&temp, sizeof(phone), 1, fi);	
	while ( !feof(fi) ) {
		fwrite(&temp, sizeof(phone), 1, f2);
		fread(&temp, sizeof(phone), 1, fi);
	}

	fclose(fi);
	fclose(f1);
	fclose(f2);
	return;
}

void mergeFile(char *fIn1, char *fIn2, char *fO) {

	FILE *fi1 = fopen(fIn1, "rb");
	FILE *fi2 = fopen(fIn2, "rb");

	if (fi1 == NULL || fi2 == NULL) {
		printf("Can not open file\n");
		return;
	}

	FILE *fo = fopen(fO, "w+b");

	phone temp;

	fread(&temp, sizeof(phone), 1, fi1);
	while ( !feof(fi1) ) {
		fwrite(&temp, sizeof(phone), 1, fo);
		fread(&temp, sizeof(phone), 1, fi1);
	}

	fread(&temp, sizeof(phone), 1, fi2);
	while ( !feof(fi2) ) {
		fwrite(&temp, sizeof(phone), 1, fo);
		fread(&temp, sizeof(phone), 1, fi2);
	}
	
	fclose(fi1);
	fclose(fi2);
	fclose(fo);
	return;
}

void fileRead(char *file){
	FILE *f = fopen(file, "rb");

	if (f == NULL) {
		printf("Can not open file %s \n", file);
		return;
	}

	phone temp;

	fread(&temp, sizeof(phone), 1, f);
	
	while ( !feof(f) ) {
		printf("%-15s%-10s%-10.1f%-7s\n", 
		   temp.name, 
		   temp.memory, 
		   temp.display, 
		   temp.price);
		fread(&temp, sizeof(phone), 1, f);
	}
	
	fclose(f);
	return;
}
