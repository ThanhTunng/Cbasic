#include <stdlib.h>

typedef enum { false, true } bool;

typedef char type;

typedef struct stackNode{
  struct stackNode *next;
  type data;
}stackNode;


typedef struct stack{
  stackNode *top;
}stack;

void initialList(stack s){
  s.top=NULL;
  return;
}

int isEmpty(stack s){
  if(s.top==NULL) return 1;
  return 0;
}

type readNode(){
  type new;
  printf("Enter the value: ");
  scanf("%c", &new);
  return new;
}

stackNode *newNode(type n){
  stackNode *new = (stackNode *)malloc(sizeof(stackNode));
  if(new == NULL){ 
   printf("no memo available error\n"); 
   return NULL;
  }

  (*new).data = n;
  new->next = NULL;

  return new;
  
}

void push(stack *s,type n){
  stackNode *temp = newNode(n);

  if((*s).top==NULL){
    (*s).tail = (*s).top = temp;
    return;
  }
  
  temp->next = (*s).top;
  (*s).top = temp;
  
  return; 
}

elementType pop(stack *s){
  if(isEmpty(s)){
    printf("Empty stack\n");
  }
  else{
    stackNode *temp = (stackNode *)malloc(sizeof(stackNode));

    type value = (*s).top->data;

    temp = (*s).top;
    (*s).top = (*s).top->next;

    free(temp);
    return value;
  }
}


void displayStack(stack *s){
  stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
  temp = s->top;
  if(s->top==NULL){
    printf("Empty stack\n");
    return;
  }
  
  while(temp!=NULL){
    printf("%c", (*temp).data);
    temp = temp->next;
  }
  free(temp);
  return;
}

void freeStack(stack *s){
  
  stackNode *cur = (*s).top;
  while(cur!=NULL){
    stackNode *temp = cur;
    cur = cur->next;
    free(temp);
  }
  s->top = NULL;
  return;
}
