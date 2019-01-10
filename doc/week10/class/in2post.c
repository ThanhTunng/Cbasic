#include <stdio.h>
#include <stdlib.h>
#include "stackLL.h"
#include <string.h>

int priority(char s)
{
  if(s == '+' || s == '-')
    return 0;
  else
    return 1;
}

char* infix(char* s)
{
  stack st;
  st.top = NULL;
  char *result = (char*)malloc(100*sizeof(char));
  int cnt =0;
  for(int i=0;i<strlen(s);i++){
    if(s[i] == ' '){
      result[cnt] = s[i];
      cnt++;
    }else if(s[i] >= '0' && s[i] <= '9'){
      result[cnt] = s[i];
      cnt++;
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
	  type new;
	  new.ch =s[i];
	  push(new,&st);
	}else{
	  result[cnt] = tmp.ch;
	  cnt++;
	  while(!isEmpty(st)){
	    tmp = pop(&st);
	    result[cnt] = tmp.ch;
	    cnt++;
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
      while(!isEmpty(st)){
	type tmp = pop(&st);
	if(tmp.ch != '('){
	  result[cnt] = tmp.ch;
	  cnt++;
	}else if(tmp.ch == '(')
	  break;
      }
    }
  }
  while(!isEmpty(st)){
    type tmp1 = pop(&st);
    result[cnt] = tmp1.ch;
    cnt++;
  }
  result[cnt] ='\0';
  return result;
}

int main(int argc, char*argv[])
{
  if(argc != 2){
    printf("Syntax Error!\n");
  }else{
    printf("The total is %s\n",infix(argv[1]));
  }
  return 0;
}
