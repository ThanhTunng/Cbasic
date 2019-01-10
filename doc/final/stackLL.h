#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char stackType;
typedef struct stackNode{
  stackType data;
  struct stackNode *next;
}stackNode;
/*
typedef struct stack{
  stackNode * top;
}stack;
*/
void stack_initial(stackNode **stack) {
	*stack = NULL;
	return;
}

int stack_isEmpty(stackNode **stack)
{
  if( *stack == NULL)
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

void push(stackNode **st,stackType dat)
{
  stackNode* new = newStackNode(dat);
  /* if(stack_isEmpty(st)){
    (*st)->top = new;
    return;
    }*/
  
  new->next = (*st);
  (*st) = new;
  return;
}

stackType pop(stackNode **st)
{
  if(stack_isEmpty(st) == 1){
    printf("Empty\n");
    stackType c='\0';
    return c;
  }
  else{
    stackType value = (*st)->data;
    stackNode *to_free = (*st);
    (*st) = (*st)->next;
    free(to_free);
    return value;
  }
}


