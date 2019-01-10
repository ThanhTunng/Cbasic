#include <stdio.h>
#include <stdlib.h>
#include "stackLL.h"
#include <string.h>

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

int main(int argc, char*argv[])
{
  if(argc != 2){
    printf("Syntax Error!\n");
  }else{
    printf("The total is %d\n",posteval(argv[1]));
  }
  return 0;
}
