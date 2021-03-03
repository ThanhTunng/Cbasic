#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

int main(){
  FILE * f = fopen("phoneDB.txt","r");
  if(f==NULL) return -1;
  else{
    while(!feof(f)){
      node * temp = (node *)malloc(sizeof(node));
      fscanf(f, "%s", temp->element->name);
      fscanf(f, "%s", temp->element->memory);
      fscanf(f, "%f", &temp->element->display);
      fscanf(f ,"%s", temp->element->price);

      insertLast(temp);
      free(temp);
    }
    displayList();
    return 0;
  }
}

