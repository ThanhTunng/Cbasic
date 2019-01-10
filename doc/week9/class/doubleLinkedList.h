
typedef struct elementtype{
  char name[20];
  char memory[20];
  float display;
  char price[20];
}elementtype;

typedef struct node{
  elementtype *element;
  struct node *prev;
  struct node *next;
}node;


  node *root=NULL;
  node *cur=NULL;
  node *tail=NULL;

node *newNode(elementtype *ele){
  node *new = (node *)malloc(sizeof(node));
  new->element = ele;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

void insertFirst(elementtype *ele){
  if(root==NULL){
    root = tail = newNode(ele);
    return;
  }
  node *new = newNode(ele);
  new->next = root;


  root->prev = new;
  root = new;
  free(new);
  return;
}

void insertLast(node *new){
  if(tail == NULL){
    tail = root = new;
    return;
  }
  tail->next = new;
  new->prev = tail;
  tail = new;
  return;
}


void displayNode(node *p){
  printf("%-15s%-10s%-10.1f%-7s\n",
	 p->element->name,
	 p->element->memory,		\
	 p->element->display,
	 p->element->price);
  return;
}

void displayList(){
  node * temp = (node *)malloc(sizeof(node));
  for(temp = root;temp!=NULL;temp = temp->next){
    displayNode(temp);
  }
  free(temp);
  return;
}


void delList(node *p){
  if(root==NULL) printf("Empty list\n");
  else{
    if(p == root) root->next;
    else{
      p->prev->next = p->next;
    }
    free(p);
  }
}
