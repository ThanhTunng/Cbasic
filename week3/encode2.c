#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char encodeChar(char ch, int gap) {
	char ch_encode;
	
	if (isalpha(ch)) {
		if (islower(ch))
			ch_encode = 97 + (ch - 97 + gap) % 26;
		else ch_encode = 65 + (ch - 65 + gap) % 26;
	} else
		ch_encode = ch + gap;
	
	return(ch_encode);
}

void encode(char *fn, int gap) {

	FILE *f = fopen(fn, "r+");

	if (f == NULL)
		printf("\nWarning! Can not open file!\n");
	else {
		char ch = fgetc(f);
		while (ch != EOF) {
			ch = encodeChar(ch, gap);
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
		printf("\nWarning! syntax error!\n");
	else
		encode(argv[1], atoi(argv[2]));
	 
	return(0);
}