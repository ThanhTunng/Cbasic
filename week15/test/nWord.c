#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTWord.h"

void getData(char *fn, BSTNode **root) {

	FILE *f = fopen(fn, "r");
	if (f == NULL) {
		printf("Can not open file %s \n", fn);
		return;
	}

	word currWord;

	while (fscanf(f, " %s", currWord.content) != EOF) {
		BSTNode *searchNode = search(*root, currWord);
		if (searchNode == NULL) {
			currWord.n = 1;
			insertBST(root, NULL, currWord);
		}
		else {
			searchNode->data.n ++;
		}
	}
	
	fclose(f);
	return;
}

void displayAllFile(char *fn) {

	FILE *f = fopen(fn, "r");
	if (f == NULL) {
		printf("Can not open file %s \n", fn);
		return;
	}

	char buff[1000];
	while ( fgets(buff, 100, f) != NULL ) {
		printf("%s", buff);
	}
	
	fclose(f);
	return;
}

void getWordFrequency(BSTNode *root) {

	word searchWord;
	printf("Nhap mot tu ban muon tim kiem : ");
	scanf(" %s", searchWord.content);

	BSTNode *searchNode = search(root, searchWord);
	if (searchNode == NULL) {
		printf("%s khong co trong file !\n", searchWord.content);
	}
	else {
		printf("%s xuat hien %d lan trong file .\n",
			   searchNode->data.content,
			   searchNode->data.n
			   );
	}
	return;
}


void freeBST(BSTNode *root) {

	if (root == NULL) return;
	
	freeBST(root->left);
	freeBST(root->right);
	free(root);
}


int main(int argc, char *argv[]) {

	int op;

	BSTNode *root;
	BST_init(&root);
	
	if (argc != 2) {
		printf("Syntac error!\n");
		return(0);
	}
	else {
		getData(argv[1], &root);
	}
	
	do {
		printf("---------------------------------------------------\n");
		printf("1. In noi dung\n");
		printf("2. Tm kien\n");
		printf("3. Thong ke\n");
		printf("4. Exit !\n");
		
		printf("Your option : ");
		scanf("%d", &op);

		printf("---------------------------------------------------\n");
		
		switch (op) {
		case 1: {
			displayAllFile(argv[1]);
			break;
		}
		case 2: {
			getWordFrequency(root);
			break;
		}
		case 3: {
			printf("%-20s%s\n", "Tu", "So lan xuat hien");
			iterateBST(root);
			break;
		}
		case 4: {
			freeBST(root);
			break;
		}
		}
	} while(op != 4);

	return(0);
}
