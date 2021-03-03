#include <stdio.h>
#include "stackLib.h"


int main(){
  
  stackList *s = (stackList *)malloc(sizeof(stackList));

  initialList(s);
    printf("1\n");  
    push(s,readNode());
    push(s,readNode());

  displayStack(s);
  return 0;
}
