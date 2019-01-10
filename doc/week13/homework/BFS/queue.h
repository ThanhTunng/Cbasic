
/* ----------Declarartion -------------------------------- */

typedef treeNode* dataTypeQueue;

typedef struct queueNode {
	dataTypeQueue data;
	struct queueNode *next;
} queueNode;

typedef struct {
	queueNode *head;
	queueNode *tail;
} queue;

/*-------------------------------------------------------- */

dataTypeQueue deQueue(queue *Q) {

	if (Q->head == NULL) {

		printf("Empty Queue! Can not deQueue!\n");
		dataTypeQueue empty = 0;
		return(empty);
	}

	if (Q->head == Q->tail) {
		
		dataTypeQueue data = Q->head->data;
		free(Q->head);
		Q->head = Q->tail = NULL;
		
		return(data);
	}

	dataTypeQueue data = Q->tail->data;
	queueNode *temp = Q->tail;
	
	Q->tail = Q->tail->next;
	free(temp);
	
	return(data);
}

/*-------------------------------------------------------- */

void queue_init(queue *Q) {

	Q->head = NULL;
	Q->tail = NULL;
	return;
}

queueNode *makeNewQueueNode(dataTypeQueue data) {

	queueNode *newNode = (queueNode *) malloc(sizeof(queueNode));

	newNode->data = data;
	newNode->next = NULL;
	return(newNode);
}

int isEmptyQueue(queue *Q) {

	if (Q->head == NULL) {
		return(1);
	}
	
	return(0);
}

void enQueue(queue *Q, dataTypeQueue data) {

	queueNode *newNode = makeNewQueueNode(data);

	if (Q->head == NULL) {
		Q->head = Q->tail = newNode;
		return;
	}

	Q->head->next = newNode;
	Q->head = newNode;
	
	return;
}
