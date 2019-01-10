#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist_.h"

student arr[] = {
	{"Dao Ngoc Thanh", "20160001" , 10},
	{"Chu The Chuong", "20160002", 8},
	{"Nguyen Quang Linh", "20160007", 7}
	{"Nguyen Duc Dung", "20160003", 6},
	{"Tran Bich Ngoc", "20160004", 4},
	{"Vu Thanh Tung", "20160005", 2},
	{"Tran Duc Phung", "20160006", 0}
};

void createExampleSortedList(singleLinkedList *list) {

	int n = sizeof(arr) / sizeof(arr[0]);

	for(int i = 0; i < n; i++) {
		insertLast(list, &arr[i]);
	}
	return;
}

void add(singleLinkedList *list) {

	student *info = getInfo();
	node *curr = list->root;
	while (curr->info->grade > info->grade && curr != NULL) {
		curr = curr->next;
	}

	if (curr == NULL) {
		insertLast(list, info);
		return;
	}
	insertBefore(list, curr, info);
	return;
}

node *searchById(singleLinkedList *list, char *id){

	node *curr = list->root;
	
	while (curr != NULL) {
		if (strcmp(curr->info->id, id) == 0) {
			return(curr);
		}

		curr = curr->next;
	}

	printf("Node not found!\n");
	return(NULL);
}


void deleteById(singleLinkedList *list, char *id) {

	node *p = searchById(list, id);
	delete(list, p);
	return;
}


int main() {

	singleLinkedList *list = (singleLinkedList *)malloc(sizeof(singleLinkedList));
	init_list(list);

	int op;
	while (op != 6) {
		printf("---------------------------------------------------\n");
		printf("1. create example sorted list in decrease order ! \n");
		printf("2. Print List\n");
		printf("3. Add new student in right order\n");
		printf("4. Search student by id\n");
		printf("5: Delete student by id\n");
		printf("6. Exit\n");
		printf("---------------------------------------------------\n");

		printf("Option : ");
		scanf("%d", &op);
		clear_buffer();
		
		switch (op) {
		case 1: {
			createExampleSortedList(list);
			break;
		}
		case 2: {
			printList(list);
			break;
		}
		case 3: {
			add(list);
			break;
		}
		case 4: {
			char id[10];
			printf("Enter an ID : ");
			scanf("%s", id);
			clear_buffer();
			node *p = searchById(list, id);
			displayNode(p);
			break;
		}
		case 5: {
			char id[10];
			printf("Enter an ID : ");
			scanf("%s", id);
			clear_buffer();
			deleteById(list, id);
			break;
		}
			
		}
	}
	return(0);
}
