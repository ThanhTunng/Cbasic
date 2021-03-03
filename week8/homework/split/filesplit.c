#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[30];
	char id[10];
	float grade;
} grade;

void splitFile(char *fin, int size, int n, char *fno1, char *fno2) {

	if (n > size) {
		printf("n Can not larger than the number of student in file\n");
		return;
	}
	
	FILE *fi = fopen(fin, "rb");

	if (fi == NULL) {
		printf("Can not open file \n");
		return;
	}

	FILE *f1 = fopen(fno1, "w+b");
	FILE *f2 = fopen(fno2, "w+b");

	grade temp;
	for (int i = 0; i < n; i++) {
		fread(&temp, sizeof(grade), 1, fi);
		fwrite(&temp, sizeof(grade), 1, f1);
	}

	fread(&temp, sizeof(grade), 1, fi);	
	while ( !feof(fi) ) {
		fwrite(&temp, sizeof(grade), 1, f2);
		fread(&temp, sizeof(grade), 1, fi);
	}

	fclose(fi);
	fclose(f1);
	fclose(f2);
	return;
}
int main(int argc, char *argv[]) {

	if (argc != 5) {
		printf("Systac error! \n");
		return(-1);
	}

	splitFile(argv[1], 10, atoi(argv[2]), argv[3], argv[4]);
	return(0);
}
