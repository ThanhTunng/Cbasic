#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char decodeChar(char ch, int gap) {
	char ch_decode;
	
	if (isalpha(ch)) {
		if (islower(ch))
			ch_decode = 97 + (ch - 97 - gap) % 26;
		else ch_decode = 65 + (ch - 65 - gap) % 26;
	} else
		ch_decode = ch - gap;
	
	return(ch_decode);
}

void decode(char *fn, int gap) {

	FILE *f = fopen(fn, "r+");

	if (f == NULL)
		printf("\nWarning! Can not open file!\n");
	else {
		char ch = fgetc(f);
		while (ch != EOF) {
			ch = decodeChar(ch, gap);
			fseek(f, -1, SEEK_CUR);
			fputc(ch, f);
			ch = fgetc(f);
		}
	}

	fclose(f);
	return;
}


int main(int argc, char *argv[]) {

	if (argc != 3)
		printf("\nWarning! systac error!\n");
	else
		decode(argv[1], atoi(argv[2]));
	
	return(0);
}