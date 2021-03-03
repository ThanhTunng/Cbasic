typedef struct{
	char model[20];
	char memory[10];
	float display;
	char price[10];
} Phone;


typedef struct node{
  Phone *phone;
  struct node * next;
}node;



node * newNode(Phone *p){
  node * new = (node *)malloc(sizeof(node));
  new->phone = p;
  new->next = NULL;

  return(new);
}

node * root = NULL;
node * cur = NULL;
node * end = NULL;


void insertAtHead(Phone *phone){
  node * q = newNode(phone);
  q->next = root;
  root = q;
  cur = root;
}

void insertEnd(Phone *phone){
  node * new = newNode(phone);
  if(end==NULL){
    end = root = new;
  }
  else{
    new->next = end->next;
    end->next = new;
    end = new;
  }
}

void * insertNode(Phone *phone,node * p){
  //insert a phone into the position after node p
  node * q = newNode(phone);
  if(p->next==NULL){
    insertEnd(phone);
  }
  else{

    node * temp = p->next;
    p->next = q;
    q->next = temp;
  }
}



void displayNode(node * p){
  printf("%20s%10s%10.1f%10s\n", (p->phone)->model, (p->phone)->memory, (p->phone)->display, (p->phone)->price);
  return;
}

void displayList(){
  node * temp = (node *)malloc(sizeof(node));
  if(root == NULL) printf("The list is empty\n");
  else{
    temp = root;
    while(temp!=NULL){
      displayNode(temp);
      temp = temp->next;
    }
  }
}

void freeList(){
  if(root == NULL) printf("Free list process completed\n");
  else{
    node * temp = root;
    while(temp!=NULL){
      free(temp);
      temp = temp->next;
    }
  }
}
