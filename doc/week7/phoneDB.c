#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

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
	int found = 0;
	
	while (temp != NULL) {
		
		fwrite(temp->info, sizeof(phone), 1, f);
		temp = temp->next; 
	}
	
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
int main() {

	singleLinkedList list;

	init_list(&list);

	int op;

	do {
		printf("\n-------------------------------------------\n");
		printf("There are 7 options : \n");
		printf("1 . Import from text\n");
		printf("2 . Import from Dat\n");
		printf("3 . Display all phone\n");
		printf("4 . Search phone by model\n");
		printf("5 . Search phone by price\n");
		printf("6 . Export to Dat\n");
		printf("7 . Exit\n");

		printf("\n-------------------------------------------\n");
		printf("Your option : ");
		scanf("%d", &op);
		
		printf("\n-------------------------------------------\n");
		switch (op) {
		case 1: {
			readDataFromTextFile("phoneDB.txt", &list);
			break;
		}
		case 2: {
			readDataFromDatFile("phoneDB.dat", &list);
			break;
		}
		case 3: {
			printList(&list);
			break;
		}
		case 4: {
			searchByModel(&list);
			break;
		}
		case 5: {
			searchByPrice(&list);
			break;
		}
		case 6: {
			exportData("phoneDB.dat", &list);
			break;
		}
		}
	} while (op != 7);

	return(0);
}
