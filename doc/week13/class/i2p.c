#include "BST.h"
#include "stackLL.h"

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

int main(){
  char arr[100];
  stack st;
  
  printf("Enter the expression: ");
  clear_buffer();
  fgets(arr, 100, stdin);

  char str[100];
  strcpy(str,infix(arr));
  for(int i=0;i<strlen(str);i++){
    if(str[i]>='0' || str[i]<= '9'){
      Node *temp;
      temp->data = str[i];
      push(temp,)
    }
  }
  
  
  
}


