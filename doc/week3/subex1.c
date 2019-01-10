#include <stdio.h>
#include <ctype.h>

void countChar(char *fn) {

	FILE *f = fopen(fn, "r");

	if (f == NULL)
		printf("\nCan not open file: %s!\n", fn);
	else {
		int charArr[100];
		char ch;
		int i;
		
		for (i = 32; i < 97; i++)
			charArr[i] = 0;
		
		while (ch != EOF) {
			ch = fgetc(f);

			if (isalpha(ch)) {
				ch = toupper(ch);
				charArr[ch]++;
			} else
				charArr[ch]++;
				
		}

		FILE *fout = fopen("sourcestats.txt", "w+");

		printf("\nCharacter - count\n");
		fprintf(fout, "\nCharacter - count\n");
		
		for (i = 32; i < 97; i++) {
			if (charArr[i] > 0) {
				printf("%c - %d\n", i, charArr[i]);
				fprintf(fout, "%c - %d\n", i, charArr[i]);
			}
		}
		
	}
	
	return;
}

int main(int argc, char *argv[]) {

	if (argc != 2)
		printf("\nWarning! systac error!\n");
	else
		countChar(argv[1]);
	return(0);
}