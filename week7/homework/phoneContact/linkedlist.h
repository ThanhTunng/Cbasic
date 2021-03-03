//declare sruct
typedef struct phone{
  char name[15];
  char number[12];
  char mail[30];
}phone;

//declare node
typedef struct node{
  phone * contact;
  struct node * next;
}node;

//intializing global node
node * root = NULL;
node * cur = NULL;
node * prev = NULL;
node * end = NULL;

//make new node
node * newNode(phone *cont){
  node * new = (node *)malloc(sizeof(node));

  new->contact = cont;
  new->next = NULL;

  return new;
}


//insert at the end of single linked list
void insertEnd(phone * contact){
  node * p = newNode(contact);
  if(end==NULL){
    end = root = p;
  }
  else{
    end->next = p;
    end = p;
  }
  return;
}


//insert before a given node
void insertBefore(phone * contact,node * p){
  if(p == root){
    node * new = newNode(contact);
    new->next = root;
    root = new;
    return;
  }
  else{
    cur = root;
    while(cur!=p && cur!=NULL){
      prev = cur;
      cur = cur->next;
    }

    if(cur == NULL){
      printf("The node doesn't exist\n");
      return;
    }
    node * newnode = newNode(contact);
    prev->next = newnode;
    newnode->next = cur;

    return; 
  }
}

//insert after a given node
void insertAfter(phone * contact, node *p){
  if(p->next == NULL){
    insertEnd(contact);
    return;
  }

  else{
    node * q = newNode(contact);
    q->next = p->next;
    p->next = q;
    return;
  }
}

//display a single node
void displayNode(node * p){
  printf("%-15s%-12s%-30s\n", p->contact->name, p->contact->number, p->contact->mail);
  return;
}

//display all nodes
void printList(){
  if(root == NULL){
    printf("The list is empty\n");
    return;
  }
  node * temp = (node *)malloc(1*sizeof(node));
  temp = root;
  cur = temp;
  while(temp!=NULL){
    displayNode(temp);
    temp = temp->next;
    cur = temp;
  }
  return;
}

//free all nodes
void freeList(){
  if(root == NULL){
    printf("Free process completed\n!");
    return;
  }
  else{
    node * temp = root;
    while(temp!=NULL){
      free(temp);
      temp = temp->next;
    }
    printf("Free process completed\n");
  }
}
