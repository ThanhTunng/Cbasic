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
}DLL;

void DLL_initial(DLL **list) {
  (*list)->first = NULL;
  (*list)->last = NULL;
	return;
}

DLLnode *newDLLnode(DLLtype data) {

	DLLnode *newnode = (DLLnode *)malloc(sizeof(DLLnode));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	
	return(newnode);
}


void DLLinsertAtLast(DLL *list, DLLtype dat) {

	DLLnode *newnode = newDLLnode(dat);
	if (list->last == NULL) {
	  list->last = list->first = newnode;
		return;
	}

	list->last->next = newnode;
	newnode->prev = list->last;
	list->last = newnode;
	return;
}

void DLLinsertAtFirst(DLL *list, DLLtype dat) {

	DLLnode *newnode = newDLLnode(dat);
	if (list->first == NULL) {
	  list->first = list->last = newnode;
		return;
	}

	newnode->next = list->first;
	list->first->prev = newnode;
	list->first = newnode;
	return;
}

void DLLinsertAfter(DLL *list, DLLnode *target, DLLtype dat) {

	
  if (target == list->last) {
		DLLinsertAtLast(&list, dat);
		return;
	}

	DLLnode *newnode = newDLLnode(dat);
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

void DLLinsertBefore(DLL *list, DLLnode *target, DLLtype dat) {

	DLLnode *newnode = newDLLnode(dat);
	
	if (list->first == NULL) {
		list->first = list->last = newnode;
		return;
	}

	if (target == list->first) {
		DLLinsertAtFirst(&list, dat);
		return;
	}
	
	DLLnode *curr = list->first;
	while (curr != NULL && curr != target) {
		curr = curr->next;
	}

	if (curr == NULL) {
		printf("Node is not found! \n");
		return;
	}

	newnode->next = curr;
	newnode->prev = curr->prev;
	curr->prev->next = newnode;
	curr->prev = newnode;
	return;
}

void DLLdelete(DLL **list,DLLnode *target){
  if((*list)->first == target){
    (*list)->first = (*list)->first->next;
    (*list)->first = NULL;
  }

  DLLnode *curr = (*list)->first;
  DLLnode *prev = NULL;

  while(curr !=NULL && curr!=target){
    prev = cur;
    
    curr = curr->next;
    curr->prev = prev;
  }

  if(curr == NULL){
    printf("Node is not found\n");
    return;
  }

  if(curr == (*list)->last){
    prev->next = NULL;
    (*list)->last = prev;
    return;
  }

  curr->next->prev = prev;
  prev->next = curr->next;
  free(curr);
  return;
}

/*
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

*/
