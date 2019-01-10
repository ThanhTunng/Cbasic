#include <stdlib.h>
#include <string.h>

typedef int queueType;

typedef struct queueNode
{
  queueType data;
  struct queueNode* next;
}queueNode;

typedef struct
{
  queueNode *front;
  queueNode *rear;
}queue;

void queue_initial(queue *Q)
{
  queueNode *header = (queueNode*)malloc(sizeof(queueNode));
  header->next = NULL;
  Q->front = header;
  Q->rear = header;
}

int isEmpty_queue(queue *Q)
{
  return ((*Q).front == (*Q).rear);
}

void enqueue(queue *Q,queueType x) //InsertAtTail
{
  Q->rear->next = (queueNode*)malloc(sizeof(queueNode));
  Q->rear = Q->rear->next;
  Q->rear->data = x;
  Q->rear->next = NULL;
  
}

void dequeue (queue *Q) //DeleteAtHead
{
  if (!isEmpty_q(Q))
    {
      queueNode T;
      T = Q->front;
      Q->front = Q->front->next;
      free(T);
    }
  else printf("\nError: Queue is empty.\n");
  return;
}

void freeQueue (queue *Q)
{
  queueNode to_free;
  while ((to_free=Q->front) != NULL)
    {
      Q->front = Q->front->next;
      free(to_free);
    }
} 
