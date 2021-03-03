#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedList.h"

void clear_buffer(){
  int c;
  while((c=getchar()) !='\n' && c!=EOF);
}

int countLines(char *fn) {

	FILE *f = fopen(fn, "r");

	if (f == NULL) {
		printf("Can not open file %s\n", fn);
		return(0);
	}

	int nLines = 1;
	char ch;
	
	while ( (ch = fgetc(f)) != EOF  ) {
		if (ch == '\n')
			nLines ++;
	}

	fclose(f);
	return(nLines);
}

void readDataFromTextFile(char *fn, singleLinkedList *list) {

	FILE *f = fopen(fn, "r");

	if (f == NULL) {
		printf("Can not open file %s\n", fn);
		return;
	}

	while ( !feof(f) ) {
		phone *temp = (phone *)malloc( sizeof(phone) );
		fscanf(f, "%s", temp->name);
		fscanf(f, "%s", temp->memory);
		fscanf(f, "%f", &(temp->display));
		fscanf(f, "%s", temp->price);

		insertLast(list, temp);
	}

	fclose(f);
	return;
}

void readDataFromDatFile(char *fn, singleLinkedList *list) {

	FILE *f = fopen(fn, "rb");

	if (f == NULL) {
		printf("Can not open file %s\n", fn);
		return;
	}

	while ( !feof(f) ) {
		phone *temp = (phone *)malloc( sizeof(phone) );
		fread(temp, sizeof(phone), 1, f);
		insertLast(list, temp);
	}

	fclose(f);
	return;
}

void exportData(char *fn, singleLinkedList *list) {

	FILE *f = fopen(fn, "wb");

	if (f == NULL) {
		printf("Can not open file %s\n", fn);
		return;
	}

	node *temp = list->root;
	
	while (temp != NULL) {
		
		fwrite(temp->info, sizeof(phone), 1, f);
		temp = temp->next; 
	}
	fclose(f);
	return;
}

void searchByModel(singleLinkedList *list) {
	
	printf("\nWhat is the model do you want ro search : ");
	char model[20];
	scanf("%s", model);

	int found = 0;
	node *temp = list->root;
	while (temp != NULL) {
		if (strstr(temp->info->name, model) != NULL) {
			displayNode(temp);
		}
		temp = temp->next;
	}
	
	if ( !found )
		printf("We don't have the model %s \n", model);
	
	return;
}

void searchByPrice(singleLinkedList *list) {
	
	printf("\nWhat is the model do you want ro search : ");
	float price;
	scanf("%f", &price);

	node *temp = list->root;
	int found = 0;

	while (temp != NULL) {
		if (atof(temp->info->price) < price) {
			displayNode(temp);
			found = 1;
		}
		temp = temp->next;
	}
	
	if ( !found )
		printf("We don't have the model you want \n");
	
	return;
}

void moveToFront(singleLinkedList *list, char *s){
  node *temp = list->root;
  node *prev = NULL;
  node *after = NULL;
	while (temp != NULL) {
	  prev = temp;
		if (strstr(temp->info->name,s) != NULL) {
		  insertAtHead(list,temp->info);
		  after = temp->next;
		  prev->next = after;
		  free(temp);
		  return;
		}
		temp = temp->next;
	} 
}

int main() {

	singleLinkedList list;
	init_list(&list);

	node *current = list.last;
	int op;

	do {
		printf("\n-------------------------------------------\n");
		printf("Enter your option : \n");
		printf("1 . Import from .dat \n");
		printf("2 . Display \n");
		printf("3 . Add new phone first/last \n");
		printf("4 . Add new phone at position\n");
		printf("5 . Delete at position \n");
		printf("6 . Delete first \n");
		printf("7 . Delete current \n");
		printf("8 . Search and Update \n");
		printf("9 . Divide and Extract \n");
		printf("10 . Reverse list \n");
		printf("11 . Save to File \n");
		printf("12 . Move to Front\n");
		printf("13 . Exit\n");

		printf("\n-------------------------------------------\n");
		printf("Your option : ");
		scanf("%d", &op);
		
		printf("\n-------------------------------------------\n");
		switch (op) {
		case 1: {
			readDataFromDatFile("phoneDB.dat", &list);
			break;
		}
		case 2: {
			printList(&list);
			break;
		}
		case 3: {
			printf("1 . Insert first \n");
			printf("2 . Insert last \n");
			printf("Your option :  ");

			int op1;
			scanf("%d", &op1);
			switch (op1) {
			case 1: {
				insertBefore(&list, list.root, getInfo());
				break;
			}
			case 2: {
				insertLast(&list, getInfo());
				break;
			}
			}
			break;
		}
		case 4: {
			printf("The position you want to insert : ");
			int pos;
			scanf("%d", &pos);
			insertAtPosition(&list, pos, getInfo());
			break;
		}
		case 5: {
			printf("The position you want to delete : ");
			int pos;
			scanf("%d", &pos);
			deleteAtPosition(&list, pos);
			break;
		}
		case 6: {
			delete(&list, current);
			break;
		}
		case 7: {
			deleteFirst(&list);
			break;
		}
		case 8: {
		  searchByModel(&list);
			break;
		}
		case 9: {
		  int cc = countLines("phoneDB.txt");
		  int div =0;
		  printf("Enter the number of phones you want to divide: ");
		  scanf("%d", &div);
		  splitFile("phoneDB.dat",cc,div,"phoneDB1.dat","phoneDB2.dat");
		  printf("List 1\n*--------------*\n");
		  fileRead("phoneDB1.dat");
		  printf("*--------------*\n");
		  printf("List 2\n*--------------*\n");
		  fileRead("phoneDB2.dat");
			break;
		}
		case 10: {
			reverseList(&list);
			break;
		}
		case 11: {
			exportData("phoneDB.dat", &list);
			break;
		}
		case 12: {
		  printf("Enter the model you want to move to Front: ");
		  char *s;
		  clear_buffer();
		  fgets(s,20,stdin);
		  moveToFront(&list,s);
		  break;
		}
	      }
	} while (op!= 13);

	return(0);
}

