#include <stdlib.h>

typedef struct elementType{
  int val;
}elementType;

typedef struct stackNode{
  struct stackNode *next;
  elementType data;
}stackNode;


typedef struct stackList{
  stackNode *top;
  stackNode *cur;
  stackNode *tail;
}stackList;

void initialList(stackList *s){
  (*s).top=NULL;
  (*s).cur=NULL;
  (*s).tail=NULL;
  return;
}

int empty(stackList *s){
  if((*s).top==NULL) return 1;
  return 0;
}

elementType readNode(){
  elementType new;
  printf("Enter the value: ");
  scanf("%d", &new.val);
  return new;
}

stackNode *newNode(elementType n){
  stackNode *new = (stackNode *)malloc(sizeof(stackNode));
  if(new == NULL){ 
   printf("no memo available error\n"); 
   return NULL;
  }

  (*new).data = n;
  new->next = NULL;

  return new;
  
}

void push(stackList *s,elementType n){
  stackNode *temp = newNode(n);

  if((*s).top==NULL){
    (*s).tail = (*s).top = temp;
    return;
  }
  
  temp->next = (*s).top;
  (*s).top = temp;
  
  return; 
}

elementType pop(stackList *s){
  if(empty(s)){
    printf("Empty stack\n");
  }
  else{
    stackNode *temp = (stackNode *)malloc(sizeof(stackNode));

    elementType value = (*s).top->data;

    temp = (*s).top;
    (*s).top = (*s).top->next;

    free(temp);
    return value;
  }
}
/*
void displaySingleNode(stackNode *stack){
  if(stack==NULL){
    printf("No data\n");
    return;
  }
  
  printf("%d\n", pop(stack).val);
  return;
}*/

void displayStack(stackList *s){
  stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
  temp = s->top;
  if(s->top==NULL){
    printf("Empty stack\n");
    return;
  }
  
  while(temp!=NULL){
    printf("%d", (*temp).data.val);
    temp = temp->next;
  }
  free(temp);
  return;
}
