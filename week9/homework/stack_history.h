typedef struct {
	char str[20];
} history;

typedef struct stackHistory {
	history data;
	struct stackHistory *next;
} stackHistory;

void stackHistory_init(stackHistory **stack) {
	*stack = NULL;
	return;
}

stackHistory *makeNodeHistory(history data) {

	stackHistory *newnode = (stackHistory *)malloc(sizeof(stackHistory));
	newnode->data = data;
	newnode->next = NULL;
	
	return(newnode);
}

void pushHistory(stackHistory **top, history data) {

	stackHistory *newnode = makeNodeHistory(data);
	newnode->next = *top;
	*top = newnode;

	return;
}

history popHistory(stackHistory **top) {

	history data = (*top)->data;
	stackHistory *p = *top;
	*top = (*top)->next;
	free(p);
	return(data);
}

history peakHistory(stackHistory **stack) {

	history data = (*stack)->data; 

	return(data);
}

bool isEmptyHistory(stackHistory **top) {
	return( *top == NULL );
}

void freeStackHistory(stackHistory **top) {

	stackHistory *curr = *top;
	stackHistory *temp;
	
	while (curr != NULL) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}

	*top = NULL;
	return;
}
