
typedef int dataType;

typedef struct node {
	dataType data;
	struct node *next;
	struct node *prev;
} node;

typedef struct {
	node *first;
	node *last;
} DLL;

void DLL_init(DLL *list) {
	list->first = NULL;
	list->last = NULL;
	return;
}

dataType getData() {
	int data;
	printf("Data : ");
	scanf("%d", &data);
	return(data);
}

node *makeNode(dataType data) {

	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	
	return(newnode);
}

void displayNode(node *p) {

	printf("%d \n", p->data);
	return;
}

void insertAtLast(DLL *list, dataType data) {

	node *newnode = makeNode(data);
	if (list->last == NULL) {
		list->last = list->first = newnode;
		return;
	}

	list->last->next = newnode;
	newnode->prev = list->last;
	list->last = newnode;
	return;
}

void insertAtFirst(DLL *list, dataType data) {

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

void insertAfter(DLL *list, node *target, dataType data) {

	
	if (target == list->last) {
		insertAtLast(list, data);
		return;
	}

	node *newnode = makeNode(data);
	node *curr = list->first;

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

void insertBefore(DLL *list, node *target, dataType data) {

	node *newnode = makeNode(data);
	
	if (list->first == NULL) {
		list->first = list->last = newnode;
		return;
	}

	if (target == list->first) {
		insertAtFirst(list, data);
		return;
	}
	
	node *curr = list->first;
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

void delete(DLL *list, node *target) {

	
	return;
}

void printListFromFirst(DLL *list) {

	if (list->first == NULL) {
		printf("List is empty!\n");
		return;
	}

	node *curr = list->first;
	while (curr != NULL) {
		displayNode(curr);
		curr = curr->next;
	}
	return;
}

void printListFromLast(DLL *list) {

	if (list->last == NULL) {
		printf("List is empty!\n");
		return;
	}

	node *curr = list->last;
	while (curr != NULL) {
		displayNode(curr);
		curr = curr->prev;
	}
	return;
}
