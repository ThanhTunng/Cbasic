#include <stdio.h>
#include <string.h>
#include "BST.h"

int readData(char *fn, dataType arr[]) {

	FILE *f = fopen(fn, "r");
	if (f == NULL) {
		printf("Can not open file : %s", fn);
		return(-1);
	}
	
	int i = 0;
	char buff[50];
	while ( !feof(f) ) {
		fgets(arr[i].name, 50, f);
		fgets(arr[i].tel, 50, f);
		fgets(arr[i].email, 50, f);
		fgets(buff, 50, f);		
		i++;
	}

	fclose(f);
	return(i);
}

int main() {

	dataType arr[100];
	int n = readData("infoList.txt", arr);

	Node *root = NULL;
	
	for (int i = 0; i < n; i++) {
	  insertNode(&root, arr[i]);
	}

	deleteMin(&root);
	
	inOrder(root);

	return(0);
}
