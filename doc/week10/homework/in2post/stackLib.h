#include <stdio.h>
#include <ctype.h>
#include "stack_linkedlist.h"
#include <string.h>

void clear_buffer(){
	int c;
	while((c = getchar())!='\n'&& c!= EOF);
}

int check_prec(char c){
	if (c=='+'|| c=='-') return 1;
	else if(c=='*'|| c=='/') return 2;
	else if(c=='^') return 3;
	else return -1;
}

void In_to_Post(char* s, char* at){
	node* oper;
	Init(&oper);
	int i = 0;
	int j = 0;
	for(i=0;i<strlen(s);i++){
		if(isdigit(s[i])|| isalpha(s[i])) {
			printf("%c", s[i]);
			at[j] = s[i];
			j++;
		}
		if(s[i] =='(') oper = push(oper, s[i]);
		if(s[i] ==')') {
			char c = pop(&oper);
			while( c != '('){
				printf(" %c ", c);
				at[j] = ' '; j++;
				at[j] = c; j++;
				at[j] = ' '; j++;
				c = pop(&oper);
			}
		}
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
			if(isEmpty(&oper)) oper = push(oper, s[i]);
			else{
				if(check_prec(s[i]) > check_prec(viewtop(oper))) oper = push(oper, s[i]);
				else{
					while(!isEmpty(&oper)){
						if(check_prec(s[i]) <= check_prec(viewtop(oper))) {
							char n = pop(&oper);
							printf(" %c ", n);

							at[j] = ' '; j++;
							at[j] = n; j++;
							at[j] = ' '; j++;					
						}
						else break;
					}
				oper = push(oper, s[i]);
				
				}
			}
		}
		if(s[i]==' ') {
			printf(" ");
			at[j] = ' ';
			j++;
			}	 
	}
	if(isEmpty(&oper)) printf("\n");
	else{
		while(!isEmpty(&oper)) {
			char m = pop(&oper);
			printf(" %c ", m);
			at[j] = ' '; j++;
			at[j] = m; j++;
			at[j] = ' '; j++;
		}
	}
	printf("\n");

}

void Calculate(char* s){
  node* digit;
  Init(&digit);
  int n1, n2;

  char* ss;
  ss = strtok(s, " ");
  while(ss!=NULL){
 //   printf("%s\n", ss);
    if (strcmp(ss, "+")==0){
      if(!isEmpty(&digit))
        n2 = pop(&digit);
      else{
        printf("Wrong expression\n");
        exit(0);
      } 
      if(!isEmpty(&digit))
        n1 = pop(&digit);
      else{
        printf("Wrong expression\n");
        exit(0);
      } 
      digit = push(digit, n1 + n2);
    }
    else if(strcmp(ss, "-")==0){
      if(!isEmpty(&digit))
        n2 = pop(&digit);
      else{
        printf("Wrong expression\n");
        exit(0);
      } 
      if(!isEmpty(&digit))
        n1 = pop(&digit);
      else{
        printf("Wrong expression\n");
        exit(0);
      }     
      digit = push(digit, n1 - n2);
    }
    else if(strcmp(ss, "*")==0){
      if(!isEmpty(&digit))
        n2 = pop(&digit);
      else{
        printf("Wrong expression\n");
        exit(0);
      }
      if(!isEmpty(&digit))
        n1 = pop(&digit);
      else{
        printf("Wrong expression\n");
        exit(0);       
      }  
      digit = push(digit, n1 * n2);
    }
    else if(strcmp(ss, "/")==0){
      if(!isEmpty(&digit))
        n2 = pop(&digit);
      else{
        printf("Wrong expression\n");
        exit(0);
      }  
      if(!isEmpty(&digit))
        n1 = pop(&digit);
      else{
        printf("Wrong expression\n");
        exit(0);      
      }
      digit = push(digit, n1 / n2);
    }
    else digit = push(digit, atoi(ss));
    ss = strtok(NULL, " ");
  }
  int result  = pop(&digit);
  if(!isEmpty(&digit)) {
    printf("Wrong expression\n");
    freeStack(&digit);
  }  
  else printf("\n* RESULT = %d\n", result); 
}

int main(){
	int option;
	char s[100];
	char post[100];
	do{
		printf("\n================MENU===============\n\n");
		printf("-> 1.Enter an infix expression(operand\nand operator are separated by one space)\n");
		printf("-> 2.Convert into postfix expression\n");
		printf("-> 3.Value\n");
		printf("-> 4.Exit\n\n");
		printf("---------------------------------------\n");
		printf("Your choice: "); scanf("%d", &option);
		clear_buffer();
		switch(option){
			case 1:{
				printf("Enter an infix expression(operand and operator are separated by one space)\n"); scanf("%[^\n]s", s);
				break;
			}
			case 2:
				if(strlen(s)==0) printf("Please input expression in infix form \n");
				else {
					printf("Expression in postfix form:\n");
					In_to_Post(s, post);
				}
				break;
			case 3:
				if(strlen(post)==0) {
					printf("Please input expression\n");
					break;
				}
				Calculate(post);
				break;
			case 4: break;
			default: printf("Again!!!\n");
		}
	}while (option!=4);
	return 0;
}*/
#include <stdlib.h>

typedef enum { false, true } bool;

typedef char type;

typedef struct stackNode{
  struct stackNode *next;
  type data;
}stackNode;


typedef struct stack{
  stackNode *top;
}stack;

void initial(stack *s){
  (*s).top=NULL;
  return;
}

int isEmpty(stack *s){
  if((*s).top==NULL) return 1;
  return 0;
}

type readNode(){
  type new;
  printf("Enter the value: ");
  scanf("%c", &new);
  return new;
}

stackNode *newNode(type n){
  stackNode *new = (stackNode *)malloc(sizeof(stackNode));
  if(new == NULL){ 
   printf("no memo available error\n"); 
   return NULL;
  }

  (*new).data = n;
  new->next = NULL;

  return new;
  
}

void push(stack *s,type n){
  stackNode *temp = newNode(n);

  if((*s).top==NULL){
    (*s).top = temp;
    return;
  }
  
  temp->next = (*s).top;
  (*s).top = temp;
  
  return; 
}

type pop(stack *s){
  if(isEmpty(s)){
    printf("Empty stack\n");
  }
  else{
    stackNode *temp = (*s).top;

    type value = (*s).top->data;

    (*s).top = (*s).top->next;

    free(temp);
    return value;
  }
}


void displayStack(stack *s){
  stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
  temp = s->top;
  if(s->top==NULL){
    printf("Empty stack\n");
    return;
  }
  
  while(temp!=NULL){
    printf("%c", (*temp).data);
    temp = temp->next;
  }
  free(temp);
  return;
}

void freeStack(stack *s){
  
  stackNode *cur = (*s).top;
  while(cur!=NULL){
    stackNode *temp = cur;
    cur = cur->next;
    free(temp);
  }
  s->top = NULL;
  return;
}
