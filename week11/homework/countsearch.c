#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elementype{
  char name[20];
  int count;
} elementype;

typedef struct Node{
  elementype *element;
  struct Node *next;
} Node;
typedef struct linkedlist{
  Node* root;
  Node* last;
}linkedlist;
void init_list(linkedlist *list){
  list->root = NULL;
  list->last = NULL;
}
Node *makeNode(elementype *element){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->element = element;
  newNode->next = NULL;
  return newNode;
}
void insertLast(linkedlist *list,elementype *element){
  Node* newNode = makeNode(element);
  if(list->root == NULL){
    list->root = list->last = newNode;
    return;
  }else{
    list->last->next = newNode;
    list->last = newNode;
    return;
  }
}
void displayNode(Node *node){

  printf("%s(%d)\n", node->element->name, node->element->count);

  return;
}
void traversingList(linkedlist *list){
  Node* temp;
  temp = list->root;
  while(temp != NULL){
    displayNode(temp);
    temp = temp->next;
  }
  return;
}


void getDataFromtxt(char *fin,linkedlist *list){

  FILE *f = fopen(fin,"r");
  if(f == NULL) printf("Cannot open the file. Please check again!\n\n");
  else{

    while( !feof(f) ){
      elementype *temp = (elementype *)malloc(sizeof(elementype));
      fscanf(f, "%s", temp->name);
      insertLast(list, temp);
    }
      fclose(f);
  }
}
void deleteCur(linkedlist *list, Node* target){

  if(target == list->root){
    list->root=list->root->next;
    return;
  }

  Node* cur = list->root;
  Node* pre = NULL;
  
  while(cur != NULL && cur != target){
    pre = cur;
    cur = cur->next;
  }

  if(cur == NULL){
    printf("Node is not on the list\n");
  return;
  }

  if(cur == list->last){
    pre->next = NULL;
    list->last = pre;
    return;
  }

  pre->next = cur->next;
  free(cur);
  return;
}
void change(Node* p1,Node* p2){
  Node* temp;
  temp->element = p1->element;
  p1->element = p2->element;
  p2->element = temp->element;
}
void countSearch(linkedlist *list){

  printf("What model: ");

  char model[20];
  scanf("%s", model);
  int found = 0;
  Node* temp = list->root;
   while( temp != NULL){

    if(strcmp(temp->element->name, model) == 0){
      temp->element->count = temp->element->count+1;
      displayNode(temp);
      found = 1;

    }
    temp=temp->next;
  }
   if(!found) printf("cannot find\n");
}
void sort(linkedlist *list){
  Node* i;Node* j;
  for(i = list->root; i != list->last; i = i->next){
    for(j = i->next; j != NULL; j = j->next){
      if(i->element->count < j->element->count){
	change(i,j);
      }
    }
  }
}
int searchCount(linkedlist *list,char name[]){
  Node* current =  list->root;
  Node* prev = NULL;
  int found = 0;
  while(current != NULL){
    if(strcmp(current->element->name, name) == 0){
      current->element->count = current->element->count +1;
      displayNode(current);
      found = 1;
      if(current != list->root){
	Node* temp = list->root;
	Node* temp_prev = NULL;

	while(current->element->count < temp->element->count){
	  temp_prev = temp;
	  temp = temp->next;
	}
	if(current != temp){
	  prev->next = current->next;
	  current->next = temp;

	  if(temp == list->root) list->root = current;
	  else temp_prev->next = current;
	}
      }
      return 1;
    }
    prev = current;
    current = current->next;
  }
  if(!found) printf("Cannot find!!!\n");
  return 0;
}
int main()
{
  linkedlist list;
  init_list(&list);
  int op;
  do{
    printf("1. Import from PhoneDB.txt\n");
    printf("2. Display\n");
    printf("3. Count search\n");
    printf("4. Exit\n");
    printf("Your option is: ");
    scanf("%d", &op);
    switch(op){
    case 1:{
      getDataFromtxt("data.txt",&list);
      deleteCur(&list,list.last);
      break;
    }
    case 2:{
      
      traversingList(&list);
      break;
    }
    case 3:{
      char name[20];
      printf("Name: ");
      scanf("%s", name);
      searchCount(&list,name);
      break;
    }
    }
  }while(op!=4);
    
  return 0;
}
