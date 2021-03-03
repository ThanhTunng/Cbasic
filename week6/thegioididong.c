#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char model[20];
	char memory[10];
	float display;
	char price[10];
} phone;

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

void txt2binary(char *fnIn, char *fnOut, phone arr[], int n) {

	FILE *fi = fopen(fnIn, "r");
	FILE *fo = fopen(fnOut, "w+b");
	
	if (fi == NULL) {
		printf("Can not open file %s\n", fnIn);
		return;
	}

	int i;
	for (i = 0; i < n; i++) {
		fscanf(fi, "%s", arr[i].model);
		fscanf(fi, "%s", arr[i].memory);
		fscanf(fi, "%f", &arr[i].display);
		fscanf(fi, "%s", arr[i].price);
	}

	fwrite(arr, sizeof(phone), n, fo);

	fclose(fi);
	fclose(fo);
	return;
}

void readDataFromFileDat(char *fn, phone arr[], int n) {

	FILE *f = fopen(fn, "rb");

	if (f == NULL) {
		printf("Can not open file %s\n", fn);
		return;
	}

	fread(arr, sizeof(phone), n, f);

	fclose(f);
}

void printNokiaData(phone arr[], int n) {

	int i;
	int printed = 0;
	char ch;
	
	for (i = 0; i < n; i++) {
		if (strstr(arr[i].model, "Nokia") != NULL) {
			if (printed >= 10) {
				printf("Press any key + enter to see the next page !\n");
				printed = 0;
				scanf(" %c", &ch);
			} else {
				printf("%s %s %.1f %s\n", \
					   arr[i].model, \
					   arr[i].memory, \
					   arr[i].display, \
					   arr[i].price);
				printed ++;
			}
		}	
	}

	return;
}

void searchByModel(phone arr[], int n) {

	char model[10];
	int i;
	printf("What model do you want to search : ");
	scanf("%s", model);

	for (i = 0; i < n; i++) {
		if (strstr(arr[i].model, model) != NULL) {
			printf("%s %s %.1f %s\n", \
					   arr[i].model, \
					   arr[i].memory, \
					   arr[i].display, \
					   arr[i].price);
		}
	}
	return;
}

int main() {

	int n;
	int op;
	n = countLines("phoneDB.txt");

	phone *arr; /* list of phone */
	arr = (phone *)malloc(n * sizeof(phone));

	

	while (op != 5) {
		printf("There are 5 options : \n");
		printf("1 : convert txt file to binary file \n");
		printf("2 : read data from .dat file \n");
		printf("3 : print all Nokia database \n");
		printf("4 : search by model \n");
		printf("5 : exit \n");
		printf("Your option : ");
		scanf("%d", &op);
		
		switch (op) {
		case 1: {
			txt2binary("phoneDB.txt", "phoneDB.dat", arr, n);
			break;
		}
		case 2: {
			readDataFromFileDat("phoneDB.dat", arr, n);
			break;
		}
		case 3: {
			printNokiaData(arr, n);
			break;
		}
		case 4: {
			searchByModel(arr, n);
			break;
		}
		default: {
			printf("Please choose 1 in 5 option \n");
			break;
		}
		}
	}
	
	return(0);
}
