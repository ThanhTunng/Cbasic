#include <stdio.h>
#include <math.h>
#include "stack.h"
#include "stack_float.h"

bool isDigit(char ch) {
	if (ch >= '0' && ch <= '9') return(true);
	return(false);
}

int prec(int ch) {
	switch (ch) {
	case '+':
	case '-':
		return(1);
	case '*':
	case '/':
		return(2);
	case '^':
		return(3);
	}
}

void infix2postfix(char exp[]) {

	stackNode *stack;
	stack_init(&stack);

	int i, k;
	for (i = 0, k = -1; exp[i]; i++) {
		if( isDigit(exp[i]) == true) {
			exp[++k] = exp[i];
		}
		else if (exp[i] == '(') {
			push(&stack, exp[i]);
		}
		else if (exp[i] == ')') {
			while (!isEmpty(&stack) && peak(&stack) != '(') {
				exp[++k] = pop(&stack);
			}

			if ( !isEmpty(&stack) && peak(&stack) != '(') {
				printf("Invalid exp!\n");
			} else {
				pop(&stack);
			}
		} else {
			while (!isEmpty(&stack) && prec(exp[i]) <= prec(peak(&stack))) {
				exp[++k] = pop(&stack);
			}
			
			push(&stack, exp[i]);
		}
	}

	while ( !isEmpty(&stack) ) {
		exp[++k] = pop(&stack);
	}

	exp[++k] = '\0';
	return;
}

float do_math(char op, float op1, float op2) {
	
	switch (op) {
	case '+':
		return(op1 + op2);
	case '-':
		return(op1 - op2);
	case '*':
		return(op1 * op2);
	case '/':
		return(op1 / op2);
	case '^':
		return( pow(op1, op2) );
	}
	
}

float postfix_eval(char exp[]) {

	int i;
	float operand1;
	float operand2;
	float result;

	stack_float *operand_stack;
	init_stack_float(&operand_stack);

	char token;

	for (i = 0; exp[i]; i++) {
		token = exp[i];
		if (isDigit(token)) {
			push_float(&operand_stack, (float)(token - '0'));
		} else {
			operand2 = pop_float(&operand_stack);
			operand1 = pop_float(&operand_stack);
			result = do_math(token, operand1, operand2);
			push_float(&operand_stack, result);
		}
	}

	result = pop_float(&operand_stack);
	
	return(result);
}

int main() {

	char exp[] = "(5+2)*2";
	infix2postfix(exp);
	printf("%s\n", exp);
	
	return(0);
}
