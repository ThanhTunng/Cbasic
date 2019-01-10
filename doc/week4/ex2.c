#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  char *str;
  //initial memory allocation
  str = (char *)malloc(15);
  strcpy(str,"tutorialspoint");
  printf("String = %s, Address = %p\n",str, str);

  //reallocate memory
  str=(char *)realloc(str,25);
  strcat(str,".com");
  printf("String = %s, Address = %p\n", str, str);
  //re-reallocate :))//
  str=(char *)realloc(str,20);
  strcat(str," is crashed.");
    printf("String = %s, Address = %p\n", str, str);
  free(str);
  return 0;
}
