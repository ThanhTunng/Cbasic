#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int stackType;
typedef struct stackNode
{
  stackType data;
  struct stackNode* next;
}stackNode;

typedef struct stack{
  stackNode * top;
}stack;

void stack_initial(stack **st) {
	*st = NULL;
	return;
}

int stack_isEmpty(stack **st)
{
  if( *st == NULL)
    return 1;
  else return 0;
}

stackNode *newStackNode(stackType dat)
{
  stackNode * new = (stackNode*)malloc(sizeof(stackNode));
  new->data = dat;
  new->next = NULL;
  return new;
}

void push(stack **st,stackType dat)
{
  stackNode* new = newStackNode(dat);
  if((*st)->top == NULL){
    (*st)->top = new;
    return;
  }
  
  new->next = (*st)->top;
  (*st)->top = new;
  return;
}

stackType pop(stack **st)
{
  if(stack_isEmpty(st) == 1){
    printf("Empty\n");
    return NULL;
  }
  else{
    stackType value = (*st)->top->data;
    stackNode *to_free = (*st)->top;
    (*st)->top = (*st)->top->next;
    free(to_free);
    return value;
  }
}


