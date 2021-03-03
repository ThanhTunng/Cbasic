#include <stdio.h>
#include <stdlib.h>
#include "abc.h"

typedef treeNode* dataType;
typedef struct stackNode
{
  dataType tree;
  struct stackNode* next;
}stackNode;

void stack_init(stackNode **stack) {
	*stack = NULL;
	return;
}

int IsEmpty(stackNode **top)
{
  if( *top == NULL)
    return 1;
  else return 0;
}

stackNode *newNode(dataType tree)
{
  stackNode* new = (stackNode*)malloc(sizeof(stackNode));
  new->tree = tree;
  new->next = NULL;
  return new;
}

void push(dataType tree,stackNode **top)
{
  stackNode* new = newNode(tree);
  new->next = *top;
  *top = new;
}

dataType pop(stackNode **top)
{
  if(IsEmpty(top) == 1){
    printf("Empty\n");
    return NULL;
  }else{
    dataType value = (*top)->tree;
    stackNode *to_free = *top;
    *top = (*top)->next;
    free(to_free);
    return value;
  }
}


