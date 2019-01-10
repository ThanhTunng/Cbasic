#include <stdio.h>
#include <stdlib.h>

typedef int DLLtype;

typedef struct DLLnode {
	DLLtype data;
	struct DLLnode *next;
	struct DLLnode *prev;
} DLLnode;

typedef struct {
	DLLnode *first;
	DLLNode *last;
} DLL;

void DLL_initial(DLL *list) {
	list->first = NULL;
	list->last = NULL;
	return;
}

DLLnode *newDLLnode(dataType data) {

	DLLnode *newnode = (DLLnode *)malloc(sizeof(DLLnode));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	
	return(newnode);
}


void DLLinsertAtLast(DLL *list, dataType data) {

	DLLnode *newnode = makeNode(data);
	if (list->last == NULL) {
		list->last = list->first = newnode;
		return;
	}

	list->last->next = newnode;
	newnode->prev = list->last;
	list->last = newnode;
	return;
}

void DLLinsertAtFirst(DLL *list, dataType data) {

	node *newnode = makeNode(data);
	if (list->first == NULL) {
		list->first = list->last = newnode;
		return;
	}

	newnode->next = list->first;
	list->first->prev = newnode;
	list->first = newnode;
	return;
}

void DLLinsertAfter(DLL *list, DLLnode *target, DLLtype data) {

	
	if (target == list->last) {
		insertAtLast(list, data);
		return;
	}

	DLLnode *newnode = makeNode(data);
	DLLnode *curr = list->first;

	while (curr != NULL && curr != target) {
		curr = curr->next;
	}

	if (curr == NULL) {
		printf("Node not found! \n");
		return;
	}

	newnode->next = curr->next;
	curr->next->prev = newnode;
	curr->next = newnode;
	newnode->prev = curr;
	
	return;
}

void DLLinsertBefore(DLL *list, DLLnode *target, DLLtype data) {

	DLLnode *newnode = makeNode(data);
	
	if (list->first == NULL) {
		list->first = list->last = newnode;
		return;
	}

	if (target == list->first) {
		DLLinsertAtFirst(list, data);
		return;
	}
	
	DLLnode *curr = list->first;
	while (curr != NULL && curr != target) {
		curr = curr->next;
	}

	if (curr == NULL) {
		printf("Node not found! \n");
		return;
	}

	newnode->next = curr;
	newnode->prev = curr->prev;
	curr->prev->next = newnode;
	curr->prev = newnode;
	return;
}

void DLLdisplayNode(DLLnode * node){
  printf("",node->data);
}

void DLLprintListFromFirst(DLL *list) {

	if (list->first == NULL) {
		printf("List is empty!\n");
		return;
	}

	DLLnode *curr = list->first;
	while (curr != NULL) {
		displayNode(curr);
		curr = curr->next;
	}
	return;
}

void DLLprintListFromLast(DLL *list) {

	if (list->last == NULL) {
		printf("List is empty!\n");
		return;
	}

	DLLnode *curr = list->last;
	while (curr != NULL) {
	  DLLdisplayNode(curr);
		curr = curr->prev;
	}
	return;
}

