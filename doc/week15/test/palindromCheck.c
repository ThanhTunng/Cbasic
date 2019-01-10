#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void displayFile(char *fn) {
	
	printf("Nhap ten file va duogn dan : ");
	scanf(" %s", fn);
	
	FILE *f = fopen(fn, "r");
	if (f == NULL) {
		printf("Can not open file %s \n", fn);
		return;
	}

	char buff[1000];
	while (fgets(buff, 1000, f) != NULL) {
		printf("%s", buff);
	}

	fclose(f);
	return;
}

int isMatchingPair(char char1, char char2)
{
    if (char1 == '(' && char2 == ')')
        return 1;
    if (char1 == '{' && char2 == '}')
        return 1;
    if (char1 == '[' && char2 == ']')
        return 1;
    return 0;
}

void palindromCheck(char *fn) {

	FILE *f = fopen(fn, "r");
	if (f == NULL) {
		printf("Can not open file %s \n", fn);
		return;
	}

	char ch;
	
	stackNode *stack;
	stack_init(&stack);

	int line = 1;

	while ( (ch = fgetc(f)) != EOF ) {

		if (ch == '\n') {
			line ++;
		}
		
		if (ch == '(' || ch == '[' || ch == '{') {
			push(&stack, ch);
		}

		if (ch == ')' || ch == ']' || ch == '}') {
			if ( isEmptyStack(&stack) ) {
				printf("Loi thieu ngoac mo, loai : %c, line : %d\n", ch, line);
			}
			else if ( !isMatchingPair(pop(&stack), ch) ) {
				printf("Loi ngoac khong tuong dong : %c, line : %d\n", ch, line);
			}
		}
	}

	fclose(f);
	return;
}

int main() {

	int op;
	char fn[100];
	
	do {
		printf("---------------------------------------------------\n");
		printf("1. hien thi noi dung file \n");
		printf("2. Kiem tra cu phap\n");

		printf("Your option : ");
		scanf("%d", &op);

		printf("---------------------------------------------------\n");
		
		switch (op) {
		case 1: {
			displayFile(fn);
			break;
		}
		case 2: {
			palindromCheck(fn);
			break;
		}
		}
	} while(op != 2);

	return(0);
}
