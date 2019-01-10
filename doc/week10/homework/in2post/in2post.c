#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "stackLib.h"

void clear_buffer(){
  int c;
  while((c=getchar())!='\n'&& c!=EOF);
}

int priority(char c){
  if(c=='+' || c == '-') return 1;
  else if(c=='*' || c == '/') return 2;
  else return 0;
}

int isANum(char c){
  if(c>='0'&&c<='9') return 1;
  return 0;
}

int isOperator(char c){
  if(c=='+'||c=='-'||c=='*'||c=='/') return 1;
  return 0;
}

void infix2postfix(stack *s,char str[]){
  int i,k;
  int count=0;
  for(i=0,k=-1; i<strlen(str);i++){
 
    if(isANum(str[i])==1){
      str[++k] = str[i];//output if char is a num
      str[++k] = ' ';
    }
    else if(str[i]==' ') break;
    else if(str[i] == '(') push(s,str[i]);//push into stack if is '('

    else if(str[i] == ')'){
      while(isEmpty(s) !=1){
	type temp = pop(s);
	if(temp!='('){
	  str[++k] = ' '; 
	  str[++k]=temp;
	  str[++k]=' ';
	  
	}
        else if(temp == '(') break;
      }
            
    }
    
    else if(isOperator(str[i])==1){//when operator encountered
      if(isEmpty(s)==1) push(s,str[i]);
      else{
	type temp = pop(s);
	if(priority(str[i])>=priority(temp)){
	  push(s,temp);
	  push(s,str[i]);
	}
	else if(temp == '('){
	  push(s,temp);
	  push(s,str[i]);
	}
	else{
	  str[++k]=' ';
	  str[++k]=temp;
	  while(isEmpty(s)!=1){
	    temp = pop(s);
	    str[++k] = ' ';
	    str[k++]=temp;
	  }
	  push(s,str[i]);
	}
      }
    }
    
    
  }

  //pop all operators from stack
  while(isEmpty(s)!=1){
    str[++k] = ' ' ;
    str[++k] = pop(s);
  }
  str[++k] = '\0';

  return;
}

float doMath(char c,float a,float b){
  if(c=='+') return (a+b);
  if(c=='-') return (a-b);
  if(c=='*') return (a*b);
  if(c=='/') return (a/b);
}

float cal(char str[]){
  char c;
  float a; float b;
  float result=0;
  stack *s=(stack *)malloc(sizeof(stack));
  initial(s);
  
  for(int i=0;i<strlen(str);i++){
    c = str[i];
    if(isANum(c)==1) push(s,c);
    else{
      b = pop(s);
      a = pop(s);
      result = (c,a,b);
      push(s,result);
    }
  }
  result = pop(s);
  return result;
}

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
  stack *s=(stack *)malloc(sizeof(stack));
  initial(s);
  char str[100];
  int choice;
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
      infix2postfix(s,str);
      printf("The postfix expression: %s\n", str);
      break;
    }
    case 3:{
      printf("Result: %.3lf\n", cal(str));
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
