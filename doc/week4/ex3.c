#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat(char s1[],char s2[]){
  char *str;
  int len1=strlen(s1);
  int len2=strlen(s2);
  str = (char *)malloc(len1+len2+1);
  if(str==NULL){
    printf("allocation failed!!Check memory!!\n");
    return NULL;
  }
  strcat(s1,s2);
  strcpy(str,s1);
  return str;
  free(str);
}

int main()
{
  char s1[100],s2[100];
  printf("Enter the first string: ");
  scanf(" ");
  fgets(s1,50,stdin);
  printf("Enter the second string: ");
  scanf(" ");
  fgets(s2,50,stdin);
  s1[strlen(s1)-1]='\0';
  printf("%s", my_strcat(s1,s2));
  return 0;
}
