#include <string.h>
#include <stdlib.h>

typedef struct SLLdataType{
  int id;
  char name[30];
  int score;
  int win;
  int lose;
}SLLtype;

typedef struct SLLnode {
	SLLtype data;
	struct SLLnode *next;
}SLLnode;

typedef struct {
	SLLnode *root;
	SLLnode *last;
}SLL;

void SLL_initial(SLL **list) {
  (*list)->root = NULL;
  (*list)->last = NULL;
  return;
}

SLLnode *newSLLnode(SLLtype dat) {
	
	SLLnode *newnode = (SLLnode *)malloc(sizeof(SLLnode));

	newnode->data = dat;
	newnode->next = NULL;
	
	return(newnode);
}

/*
void SLLdisplayNode(SLLnode *node) {

	printf();
	return;
}
/*
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

void SLLprintList(SLL *list) {

	if (list->root == NULL) {
		printf("the List is empty!\n");
		return;
	}

	SLLnode *temp = list->root;

	while (temp != NULL) {
		SLLdisplayNode(temp);
		temp = temp->next;
	}
	return;
}*/

void SLLinsertAtHead(SLL **list,SLLtype dat){
  SLLnode *new = newSLLnode(dat);
  if((*list)->root==NULL){
    (*list)->root = new;
    return;
  }
  new->next = (*list)->root;
  (*list)->root = new;
  return;
}

int SLL_isNULL(SLLnode *node){
  if(node==NULL) return 1;
  return 0;
}

void SLLinsertLast(SLL **list,SLLtype dat) {

	SLLnode *newnode = newSLLnode(dat);

	if ((*list)->last==NULL) {
	  (*list)->last = (*list)->root = newnode;
		return;
	}

	(*list)->last->next = newnode;
	(*list)->last = newnode;
	
	return;
}

void SLLinsertAfter(SLL **list, SLLnode *targetNode, SLLtype dat) {

	if (targetNode->next == NULL) {
		SLLinsertLast(list,dat);
		return;
	}

	SLLnode *newnode = newSLLnode(dat);
	SLLnode *temp = targetNode->next;
	
	targetNode->next = newnode;
	newnode->next = temp;
	return;
}

void SLLinsertBefore(SLL **list, SLLnode *targetNode, SLLtype dat) {

  if (targetNode == (*list)->root) {
		SLLnode *newnode = newSLLnode(dat);
		newnode->next = (*list)->root;
		(*list)->root = newnode;
		return;
	}

  SLLnode *current = (*list)->root;
	SLLnode *previous = NULL;
	while (current != targetNode && current != NULL) {
		previous = current;
		current = current->next;
	}

	if (current == NULL) {
		printf("The target node is not in list '\n");
		return;
	}

	SLLnode *newnode = newSLLnode(dat);
	
	previous->next = newnode;
	newnode->next = current;
	
	return;
}

void SLLinsertAtPosition(SLL **list, int pos,SLLtype dat) {

	if (pos < 0) {
		printf("The position can not negative!\n");
		return;
	}


	if (pos == 0) {

		SLLnode *newnode = newSLLnode(dat);
		if ((*list)->root == NULL) {
		  (*list)->root = newnode;
		  (*list)->last = newnode;
		} else {
		  newnode->next = (*list)->root;
		  (*list)->root = newnode;
		}

		return;
	}

	
	SLLnode *current = (*list)->root;
	int index = 1;

	while (current != NULL) {
		current = current->next;
		index ++;

		if (index == pos) {
			SLLinsertAfter(list,current,dat);
			return;
		} 
	}

	// if the position num is larger than number of phones -> insert Last
	SLLinsertLast(list,dat);
	return;
}

void SLLdelete(SLL **list,  SLLnode *target) {

  if (target == (*list)->root) {
    (*list)->root = (*list)->root->next;
    return;
  }

  SLLnode *curr = (*list)->root;
  SLLnode *prev = NULL;

  while (curr != NULL && curr != target) {
		prev = curr;
		curr = curr->next; 
	}

	if (curr == NULL) {
		printf("Node is not  in list !\n");
		return;
	}

	if (curr == (*list)->last) {
		prev->next = NULL;
		(*list)->last = prev;
		return;
	}

	prev->next = curr->next;
	free(curr);
	return;
}

void SLLdeleteFirst(SLL *list) {
  SLLdelete(&list,list->root);
	return;
}

void SLLdeleteAtPosition(SLL *list, int pos) {

	// start from 0
	if (pos == 1) {
		SLLdelete(&list, list->root);
		return;
	}

	if (pos <= 0) {
		printf("The position must be greater than 0! \n");
		return;
	}

	int index = 1;
	SLLnode *tmp = list->root;
	while (tmp != NULL) {
		tmp = tmp->next;
		index++;

		if (index == pos) {
			SLLdelete(&list, tmp);
			return;
		}
	}
	return;
}

void SLLreverseList(SLL * list) {

	SLLnode *curr = list->root;
	SLLnode *next = NULL;
	SLLnode *prev = NULL;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	list->root = prev;
	return;
}

