#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cpyByChar(char *fnIn, char *fnOut) {

	FILE *fi = fopen(fnIn, "r");
	FILE *fo = fopen(fnOut, "w+");

	if (fi == NULL) {
		printf("Can not open file %s\n", fnIn);
		return;
	}

	char ch = fgetc(fi);

	while (ch != EOF) {
		fputc(ch, fo);
		ch = fgetc(fi);
	}

	fclose(fi);
	fclose(fo);
	return;
}


void cpyByLine(char *fnIn, char *fnOut) {

	FILE *fi = fopen(fnIn, "r");
	FILE *fo = fopen(fnOut, "w+");

	if (fi == NULL) {
		printf("Can not open fil %s\n", fnIn);
		return;
	}

	char buff[100];

	while ( !feof(fi) ) {
		fgets(buff, 100, fi);
		fputs(buff, fo);
	}

	fclose(fi);
	fclose(fo);
	return;
}

void cpyByBloc(char *fnIn, char *fnOut, int size) {

	FILE *fi = fopen(fnIn, "r");
	FILE *fo = fopen(fnOut, "w+b");

	if (fi == NULL) {
		printf("Can not open fil %s\n", fnIn);
		return;
	}

	char *buff;
	buff = (char *)malloc(size * sizeof(char));
	
	while ( !feof(fi) ) {
		fread(buff, sizeof(char), size, fi);
		fwrite(buff, sizeof(char), size, fo);
	}

	fclose(fi);
	fclose(fo);
	return;
}

int main() {

	int op;
	
	printf("Choose 1 in 3 opption: \n");
	printf("1 : copy by char \n");
	printf("2 : copy by line \n");
	printf("3 : copy by bloc \n");
	printf("your option : ");
	scanf("%d", &op);

	switch (op) {
	case 1: {	
		clock_t begin = clock();
		cpyByChar("test.txt", "test_1.txt");
		clock_t end = clock();

		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Runtime : %.4lf\n", time_spent);
		break;
	}
	case 2: {	
		clock_t begin = clock();
		cpyByLine("test.txt", "test_1.txt");
		clock_t end = clock();

		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Runtime : %.4lf\n", time_spent);
		break;
	}
	case 3: {	
		clock_t begin = clock();
		cpyByBloc("test.txt", "test_1.txt", 10000);
		clock_t end = clock();
		
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Runtime : %.4lf\n", time_spent);
		break;
	}
	}
	
	return(0);
}
