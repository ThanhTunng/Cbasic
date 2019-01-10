#include <stdio.h>
#include <stdlib.h>
#include "stackLL.h"
#include <string.h>

void clear_buffer(){
  int c;
  while((c=getchar())!='\n' && c!=EOF);
}

int priority(char s)
{
  if(s == '+' || s == '-')
    return 0;
  else
    return 1;
}
/////////////////////////////////////////////////////
char* infix(char* s)
{
  stack st,op;
  st.top = op.top = NULL;
  char *result = (char*)malloc(260*sizeof(char));
  int cnt =0;
  for(int i=0;i<strlen(s);i++){
    if(s[i] == ' '){
      if(isEmpty(op) == 0){
	stack rv;
	rv.top = NULL;
	while(!isEmpty(op))
	  push(pop(&op),&rv);
	while(!isEmpty(rv)){
	  type p = pop(&rv);
	  result[cnt] = p.ch;
	  cnt++;
	}
	result[cnt] = ' ';
	cnt++;
      }
    }else if(s[i] >= '0' && s[i] <= '9'){
      type tmp;
      tmp.ch = s[i];
      push(tmp,&op);
    }else if(s[i] == '+' || s[i] == '*' || s[i] == '-' || s[i] == '/'){
      if(isEmpty(st)){
	type new;
	new.ch =s[i];
	push(new,&st);
      }else{
	type tmp = pop(&st);
	if(priority(s[i]) >= priority(tmp.ch)){
	  push(tmp,&st);
	  type new;
	  new.ch =s[i];
	  push(new,&st);
	}else if(tmp.ch == '('){
	  push(tmp,&st);
	  type new;
	  new.ch =s[i];
	  push(new,&st);
	}else{
	  result[cnt] = tmp.ch;
	  result[cnt+1] = ' ';
	  cnt+=2;
	  while(!isEmpty(st)){
	    tmp = pop(&st);
	    result[cnt] = tmp.ch;
	    result[cnt+1] = ' ';
	    cnt+=2;
	  }
	  type new;
	  new.ch =s[i];
	  push(new,&st);
	}
      }  
    }else if(s[i] == '('){
      type tmp;
      tmp.ch = s[i];
      push(tmp,&st);
    }else if(s[i] == ')'){
      if(isEmpty(op) == 0){
	stack rv;
	rv.top = NULL;
	while(!isEmpty(op))
	  push(pop(&op),&rv);
	while(!isEmpty(rv)){
	  type p = pop(&rv);
	  result[cnt] = p.ch;
	  cnt++;
	}
	result[cnt] = ' ';
	cnt++;
      }
      while(!isEmpty(st)){
	type tmp = pop(&st);
	if(tmp.ch != '('){
	  result[cnt] = tmp.ch;
	  result[cnt+1] = ' ';
	  cnt+=2;
	}else if(tmp.ch == '(')
	  break;
      }
    }
  }
  if(isEmpty(op) == 0){
	stack rv;
	rv.top = NULL;
	while(!isEmpty(op))
	  push(pop(&op),&rv);
	while(!isEmpty(rv)){
	  type p = pop(&rv);
	  result[cnt] = p.ch;
	  cnt++;
	}
	result[cnt] = ' ';
	cnt++;
      }
  while(!isEmpty(st)){
    type tmp1 = pop(&st);
    result[cnt] = tmp1.ch;
    result[cnt+1] = ' ';
    cnt+=2;
  }
  result[cnt] ='\0';
  return result;
}
/////////////////////////////////////
int posteval(char* s)
{
  stack st,op;
  st.top = op.top = NULL;
  for(int i = 0;i<strlen(s);i++){
    if(s[i] == ' '){
      if(isEmpty(op) == 0){
	type tmp;
	tmp.num = 0;
	int c=1;
	while(!isEmpty(op)){
	  type p = pop(&op);
	  tmp.num += p.num*c;
	  c = c*10;
	}
	push(tmp,&st);
      }
    }
    else if(s[i] >= '0' && s[i] <= '9'){
      type tmp;
      tmp.num = (int)(s[i] -'0');
      push(tmp,&op);
    }else if(s[i] == '+'){
      type a = pop(&st);
      type b = pop(&st);
      type sum;
      sum.num = a.num + b.num;
      push(sum,&st);
    }else if(s[i] == '*'){
      type a = pop(&st);
      type b = pop(&st);
      type mul;
      mul.num = a.num*b.num;
      push(mul,&st);
    }else if(s[i] == '-'){
      type a = pop(&st);
      type b = pop(&st);
      type subtract;
      subtract.num = b.num - a.num;
      push(subtract,&st);
    }else if(s[i] == '/'){
      type a = pop(&st);
      type b = pop(&st);
      type divide;
      divide.num = b.num /a.num;
      push(divide,&st);
    }
  }
  type total = pop(&st);
  return total.num;
}

int main(){
  int choice;
  char str[100];
  do{
    printf("\n1.Enter the expression\n2.Infix to Postfix\n3.Calculate\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1:{
      printf("Enter the infix expression: ");
      clear_buffer();
      fgets(str,100,stdin);
      break;
    }
    case 2:{
      printf("The postfix expression: %s\n", infix(str));
      break;
    }
    case 3:{
      printf("Result: %d\n", posteval(infix(str)));
      break;
    }
    case 4:{
      printf("You've exit the application\n");
      break;
    }
    default:{
      printf("Try again!!\n");
      getchar();
      break;
    }
    }
  }while(choice!=4);
  return 0;
}
