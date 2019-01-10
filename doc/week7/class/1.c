#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[20];
	char phone[12];
	char email[30];
}address;

typedef struct {
	struct node* next; // the pointer express next element, an element of adddress
	address addr; //instance of an address
}node;

node * newNode(){
	node *new = (node *)malloc(sizeof(node));
	new->addr = addr;
	new->next = NULL;

	return new;
}

node * root = newNode();
node * cur = newNode();
node * prev = newNode();

void readNode(node * p){
  printf("Name: ");
  scanf(" ");
  fgets((p->addr).name,20,stdin);
  
  printf("Tel: ");
  scanf(" ");
  fgets((p->addr).phone,12,stdin);

  printf("email: ");
  scanf(" ");
  fgets((p->addr).email,30,stdin);

  p->next = NULL;
}

void displayNode(node * p){
  //display single node
  printf("Name: %s\n", (p->addr).name);
  printf("Tel: %s\n", (p->addr).phone);
  printf("eMail: %s\n", (p->addr).email);
  printf("Next: %p\n", p->next);
}

void traversingList(){
  node * p;
  for(p=root;p!=NULL;p = p->next){
    displayNode(p);
  }
}

node * insertNode(address addr,node * p){
  //insert an address addr into the position after p
  node * q = newNode;
  q->addr = addr;

  if(p==NULL){
    q->next = NULL;
    p = q;
  }
  else{
    q->next = p->next;
    p->next = q;
  }
  return q;
}

void del(node * p){
  if(p==root){
    node * tmp = root->next;
    free(root);
    root = tmp;
  }
  else{
    node * pi = root;
    while(pi!=NULL && pi->next!=p)
      pi=pi->next;
    if(pi != NULL){
	pi->next = p->next;
	free(p);
    }
  }
}

node * prev(node * p){
  node * tmp = root;
  while(p!=NULL){
    if(tmp->next == p)
      return tmp;
    tmp = tmp->next;
  }
  return NULL;
}

int main()
{
  return 0;
}
