#include <stdio.h>
#include <stdlib.h>

typedef struct elementtype
{
  int num;
  char ch;
}type;

typedef struct node
{
  type val;
  struct node* next;
}stackNode;

typedef struct stack
{
  stackNode *top;
}stack;

int isEmpty(stack s)
{
  if(s.top == NULL)
    return 1;
  else return 0;
}

type readNode()
{
  type new;
  printf("number:");
  scanf("%d",&new.num);
  return new;
}

stackNode* newNode(type val)
{
  stackNode* new = (stackNode*)malloc(sizeof(stackNode));
  new->val = val;
  new->next = NULL;
  return new;
}

void push(type val,stack *s)
{
  stackNode* new = newNode(val);
  new->next = (*s).top;
  (*s).top = new;
}

type pop(stack *s)
{
  if(isEmpty(*s) == 1){
    printf("Empty\n");
    type value;
    value.num = 0;
    return value;
  }else{
    type value = (*s).top->val;
    stackNode* to_free = (*s).top;
    (*s).top = (*s).top->next;
    free(to_free);
    return value;
  }
}
