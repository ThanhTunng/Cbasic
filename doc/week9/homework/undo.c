#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "stack_history.h"

void undo(stackHistory **historyStack) {

	history data = popHistory(historyStack);
	printf("%s \n", data.str);
	return;
}

history creatHistory(char str[]) {

	history his;
	strcpy(his.str, str);

	return(his);
}

int main() {

	int op;

	stackNode *stack;
	stack_init(&stack);

	stackHistory *historyStack;
	stackHistory_init(&historyStack);
	
	do {
		printf("-------------------------------\n");
		printf("1. Push an int to stack\n");
		printf("2. print Peak\n");
		printf("3. pop! \n");
		printf("4. undo\n");
		printf("5. Exit!\n");

		printf("Option : ");
		scanf("%d", &op);
		printf("-------------------------------\n");

		switch(op) {
		case 1: {
			int n;
			printf("Which's interger : ");
			scanf("%d", &n);
			push(&stack, n);

			char messeage[20] = "push ";
			messeage[5] = '0' + n;
			pushHistory(&historyStack, creatHistory(messeage));
			break;
		}
		case 2: {
			printf("%d \n", peak(&stack));
			break;
		}
		case 3: {
			int popped = pop(&stack);

			char messeage[20] = "pop ";
			messeage[4] = '0' + popped;
			pushHistory(&historyStack, creatHistory(messeage));

			printf("%d have been poppped ! \n", popped);
			break;
		}
		case 4: {
			undo(&historyStack);
			break;
		}
		}
	} while (op != 5);
	return(0);
}
