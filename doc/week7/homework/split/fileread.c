#include <stdio.h>

typedef struct {
	char name[30];
	char id[10];
	float grade;
} grade;

int main(int argc, char *argv[]) {

	if (argc != 2) {
		printf("Syntac error! \n");
		return(-1);
	}
	
	FILE *f = fopen(argv[1], "rb");

	if (f == NULL) {
		printf("Can not open file %s \n", argv[1]);
		return(-1);
	}

	grade temp;

	fread(&temp, sizeof(grade), 1, f);
	
	while ( !feof(f) ) {
		printf("%-20s%-10s%.1f\n", temp.name, temp.id, temp.grade);
		fread(&temp, sizeof(grade), 1, f);
	}
	
	fclose(f);
	return(0);
}
