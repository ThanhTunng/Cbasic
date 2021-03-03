#include <stdio.h>
#include <stdlib.h>

typedef struct pro{
	int mark;
	int id;
	int memory;
}pro;


typedef int elementtype;
typedef struct node
{
  elementtype data1;
  elementtype data2;
  struct node* next;
} node;

typedef node* Position;
typedef struct
{
  Position front;
  Position rear;
} queue;

void Init_q(queue *Q)
{
  Position header = (node*)malloc(sizeof(node));
  header->next = NULL;
  Q->front = header;
  Q->rear = header;
}

int isEmpty_q (queue Q)
{
  return (Q.front == Q.rear);
}

void Enqueue(queue *Q, elementtype x, elementtype y) //InsertAtTail
{
  Q->rear->next = (node*)malloc(sizeof(node));
  Q->rear = Q->rear->next;
  Q->rear->data1 = x;
  Q->rear->data2 = y;
  Q->rear->next = NULL;
}

void Dequeue (queue *Q) //DeleteAtHead
{
  if (!isEmpty_q(*Q))
    {
      Position T;
      T = Q->front;
      Q->front = Q->front->next;
      free(T);
    }
  else printf("\nError: Queue is empty.\n");
}

void freeQueue (queue *Q)
{
  Position to_free;
  while ((to_free=Q->front) != NULL)
    {
      Q->front = Q->front->next;
      free(to_free);
    }
} 
