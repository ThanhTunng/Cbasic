#include <stdio.h>
#include <stdlib.h>

typedef int type;

typedef struct Node{
  type data;
  struct Node *next;
}Node;

typedef struct queue{
  Node *front;
  Node *rear;
}queue;

queue newQueue(){
  queue *q=(queue *)malloc(sizeof(queue));

  q->rear = (Node *)malloc(sizeof(Node));
  q->front = NULL;
  return q;
}

int isEmpty(queue *q){
  if((*q).front==NULL) return 1;
  return 0;
}

int queueLength(queue *q){
  int len = 0;
  Node *temp;
  temp = q->front;
  while(temp!=NULL){
    len++;
    temp = temp->next;
  }
  return len;
}

int waitTime(queue *q){//show the time the last person have to wait
  if(q->front==NULL) return 0;
  return (q->rear->data);//return the last have to wait;
}

void enqueue(queue *q,type dat){
  Node *new = (Node *)malloc(sizeof(Node));
  if(new==NULL){
    printf("Allocate memory failed\n");
    return;
  }

  new->data = waitTime(q) + 15;
  q->rear->next = new;
  q->rear = new;
  if(q->front==NULL) q->front = q->rear;
  
}

int dequeue(queue *q){
  int n=0;
  Node *temp = (Node *)malloc(sizeof(Node));
  if(isEmpty(q)){
    printf("Queue is empty\n");
    return 0;
  }

  temp = q->front;
  n = temp->data;
  q->front = q->front-next;
  free(q);

  return n;
}

void updateQueue(queue *q,type m){
  Node *temp = q->front;
  Node *prev;
  if(temp==NULL) return;
  while(temp!=NULL){
    temp->data -= m;
    prev = temp;
    temp = temp->next;
    if(prev->data<=0) dequeue(q);
  }
}
