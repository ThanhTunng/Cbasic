#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef enum { false, true } bool;

typedef int dataType;

typedef struct {
	dataType storage[MAX];
	dataType top;
} Stack;

void stack_inti(Stack *stack) {
	stack->top = 0;
	return;
}

bool isEmpty(Stack *stack) {
	return( stack->top == 0 );
}

bool overload(Stack *stack) {
	return( stack->top > MAX - 1 );
}

void push(Stack *stack, dataType data) {

	if (overload(stack)) {
		printf("Stack is FULL ! \n");
		return;
	} else {
		stack->storage[ stack->top ] = data;
		stack->top ++;
	}

	return;
}

dataType pop(Stack *stack) {

	dataType data;
	if (isEmpty(stack)) {
		printf("Empty Stack");
		return(0);
	} else {
		data = stack->storage[ stack->top ];
		stack->top --;
	}
	return(data);
}

dataType peak(Stack *stack) {
	return(stack->storage[ stack->top ]);
}


int main() {
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack_inti(stack);

	push(stack, 1);
	push(stack, 1);
	push(stack, 1);
	push(stack, 1);
	push(stack, 1);

	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);


	if (isEmpty(stack)) {
		printf("Empty Stack ! \n");
	} else {
		printf("%d", peak(stack));
	}
	return(0);
}
