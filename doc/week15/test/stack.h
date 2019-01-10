
/*----------- declararation -----------------------------------*/

typedef char dataTypeStack;

typedef struct stackNode {
	dataTypeStack data;
	struct stackNode *next;
} stackNode;

/*-----------change when data type change-----------------------*/

dataTypeStack pop(stackNode **stack) {

	if (*stack == NULL) {
		printf("Empty stack! Can not pop !\n");
		dataTypeStack empty = '\0';  /* change here */
		return(empty);
	}
	
	stackNode *top = *stack;
	dataTypeStack data = top->data;

	*stack = (*stack)->next;

	free(top);
	
	return(data);
}

/*--------------------------------------------------------------*/
void stack_init(stackNode **stack) {
	*stack = NULL;
	return;
}

stackNode *makeNewStackNode(dataTypeStack data) {

	stackNode *newNode = (stackNode *) malloc(sizeof(stackNode));

	newNode->data = data;
	newNode->next = NULL;
	
	return(newNode);
}

int isEmptyStack(stackNode **stack) {

	if (*stack == NULL) {
		return(1);
	}
	
	return(0);
}

void push(stackNode **stack, dataTypeStack data) {

	stackNode *newNode = makeNewStackNode(data);

	newNode->next = *stack;
	*stack = newNode;
	
	return;
}

dataTypeStack top(stackNode **stack) {
	return((*stack)->data);
} 




