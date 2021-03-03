#include <stdlib.h>

typedef enum { false, true } bool;

typedef int dataType;

typedef struct stackNode {
	dataType data;
	struct stackNode *next;
} stackNode;

void stack_init(stackNode **stack) {
	*stack = NULL;
	return;
}

dataType getData() {
	dataType data;
	printf("Data : ");
	scanf("%d", &data);
	
	return(data);
}


bool isEmpty(stackNode **top) {
	return( *top == NULL );
}

stackNode *makeNode(dataType data) {

	stackNode *newnode = (stackNode *)malloc(sizeof(stackNode));
	newnode->data = data;
	newnode->next = NULL;
	
	return(newnode);
}

void push(stackNode **top, dataType data) {

	stackNode *newnode = makeNode(data);
	newnode->next = *top;
	*top = newnode;

	return;
}

dataType pop(stackNode **top) {

	if (isEmpty(top) == true) {
		printf("Empty stack \n");
		return(-11111);
	} 
	dataType data = (*top)->data;
	stackNode *p = *top;
	*top = (*top)->next;
	free(p);
	return(data);
}

dataType peak(stackNode **stack) {

	dataType data = (*stack)->data; 

	return(data);
}

void freeStack(stackNode **top) {

	stackNode *curr = *top;
	stackNode *temp;
	
	while (curr != NULL) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}

	*top = NULL;
	return;
}
