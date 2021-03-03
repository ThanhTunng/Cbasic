typedef struct stack_float
{
	float data;
	struct stack_float *next;
} stack_float;

stack_float *newNode_float(float data) {

	stack_float *node = (stack_float *)calloc(1, sizeof(stack_float));
	node->data = data;
	node->next = NULL;
	
	return(node);
}

void init_stack_float(stack_float **root) {

	(*root) = NULL;
	return;
}

float isEmpty_float(stack_float **root) {

	return( !(*root) );
}

void push_float (stack_float **root, float data) {

	stack_float *node = newNode_float(data);

	node->next = *root;
	*root = node;
	return;
}

float pop_float(stack_float **root) {

	if ( isEmpty_float(root) ) {
		printf("Stack is empty!\n");
		return(-1.0);
	}
	
	stack_float *temp = *root;
	*root = (*root)->next;
	
	float popped = temp->data;
	free(temp);

	return(popped);
}

float peek_float(stack_float **root) {

	if ( isEmpty_float(root) ) {
		printf("Stack is empty!\n");
		return(-1);
	}

	return( (*root)->data );
}

void print_stack_float(stack_float **root) {

	stack_float *temp = *root;
	
	while (temp != NULL) {
		printf(" %.2f", temp->data);
		temp = temp->next;
	}
	
	return;
}
