#include <stdio.h>
#include <stdlib.h>

typedef ... ElementType;

typedef struct node{
  ElementType *  element;
  struct node * next;
}node;

/*-------------------------*/
node * root = NULL;
node * cur = NULL;
node * prev = NULL;
node * end = NULL;

/*------------------------*/

//make new node

node * makeNode(ElementType * ele){
  node *new = (node *)malloc(1*sizeof(node));

  new->element = ele;
  new->next = NULL;
  
  return new;
}

//input data to node

void readNode(node *new);

// display a single node

void displayNode(node *p);

//display all nodes

void transversing(){
  if(root == NULL){
    printf("The list is empty;\n");
    return;
  }
  else{
    node * temp = (node *)malloc(1*sizeof(node));

    for(temp = root; temp!=NULL; temp = temp->next){
      displayNode(temp);
    }
    free(temp);
    return;
  }
}

// free memory

void freeList(){
  if(root==NULL){
    printf("Free completed!!");
  }

  node * temp = root;
  for(temp = root; temp!=NULL; temp = temp->next){
      free(temp);
  }

  return;
}

// insert End position

void insertEnd(ElementType * ele){
  node * temp = makeNode(ele);

  if(end == NULL){
    root = end = temp;
  }
  else{
    end->next = temp;
    end = temp;
  }
  return;
}

//insert after

void insertAfter(node *target,ElementType *ele){
  node *new = makeNode(ele);

  if(target->next == NULL){
    target->next = new;
    end = new;
  }
  else{
    node *temp = (node *)malloc(1*sizeof(node));

    temp = target->next;
    target->next = new;
    new->next = temp;
      
  }

  return;
}

//insert Before

void insertBefore(node *target, ElementType * ele){
  node *new = makeNode(ele);

  cur = root;
  prev = NULL;

  while(cur != target && cur!=NULL){
    prev = cur;
    cur = cur->next;
  }

  if(cur == NULL){
    printf("Target node cant be found!!\n");
    return;
  }

  else{
    prev->next = new;
    new->next = cur;
    cur = new;
    return;
  }
}

void insertAtHead(ElementType * ele){
  node *temp = makeNode(ele);
  if(root == NULL){
    root = end = temp;
  }
  else{
    temp->next = root;
    root = temp;  
  }
  free(temp);
  return;
}

void insertAtPosition(int pos,ElementType *ele){
  if(pos<0){
    printf("Position is invalid!!\n");
    return;
  }
  else{
    cur = root;
    int index = 1;

    if(pos == 0){
      insertAtHead(ele);
      return;
    }
    while(cur!=NULL){
      if(index == pos){
	insertAfter(cur,ele);
      }

      cur = cur->next;
      index++;
    }
  }

  return;
}

//delete root

void delFirst(){
  node *temp = (node *)malloc(1*sizeof(node));
  if(root == NULL){
    printf("There is no list\n");
    return;
  }
  else{
    temp = root;
    root = temp->next;
    free(temp);
    return;
  }
}


