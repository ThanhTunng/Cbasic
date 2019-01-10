#include <stdio.h>

typedef struct {
	char name[30];
	char id[10];
	float grade;
} grade;

void mergeFile(char *fIn1, char *fIn2, char *fO) {

	FILE *fi1 = fopen(fIn1, "rb");
	FILE *fi2 = fopen(fIn2, "rb");

	if (fi1 == NULL || fi2 == NULL) {
		printf("Can not open file\n");
		return;
	}

	FILE *fo = fopen(fO, "w+b");

	grade temp;

	fread(&temp, sizeof(grade), 1, fi1);
	while ( !feof(fi1) ) {
		fwrite(&temp, sizeof(grade), 1, fo);
		fread(&temp, sizeof(grade), 1, fi1);
	}

	fread(&temp, sizeof(grade), 1, fi2);
	while ( !feof(fi2) ) {
		fwrite(&temp, sizeof(grade), 1, fo);
		fread(&temp, sizeof(grade), 1, fi2);
	}
	
	fclose(fi1);
	fclose(fi2);
	fclose(fo);
	return;
}

int main(int argc, char *argv[]) {

	if (argc != 4) {
		printf("Syntac error !\n");
	} else {
		mergeFile(argv[1], argv[2], argv[3]);
	}
	
	return(0);
}
