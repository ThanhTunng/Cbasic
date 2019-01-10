#include <stdio.h>

void reverse(char *begin, char *end){
  char temp;

  while(begin < end){
    temp = *begin;
    *begin = *end;
    *end = temp;
    begin++;
    end--;
  }
  return;
}

void reverseWord(char *s){
  char *beginW = s;
  char *temp = s;

  while( *temp != '\0' ){
    temp++;
    if( *temp == '\0'){

      reverse(beginW,temp-1);
    
    }else if( *temp == ' '){
      
      reverse(beginW,temp-1);
      
      beginW = temp+1;
    }
  }

  reverse(s,temp -1);
  return;
}
