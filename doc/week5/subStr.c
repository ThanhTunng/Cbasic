#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* subStr(char* s1,int offset,int number)
{
  char* subS;
  subS=(char*)malloc(number);
  if(number >= strlen(s1+offset)){
    for(int i=0;i<(strlen(s1)-offset);i++){
      subS[i]=s1[offset+i];
    }
    return subS;
  }else{
    for(int i=0;i<number;i++){
      subS[i]=s1[offset+i];
    }
    return subS;
  }
}

int main(int argc, char*argv[])
{
  if(argc != 4){
    printf("Syntax Error!!\n");
    printf("Form : subStr string offset number\n");
  }else if(atoi(argv[3]) <= 0){
    printf("Error!!The length of the substring must be greater than 0!!\n");
    return 1;
  }else if((atoi(argv[2]) < 0) || (atoi(argv[2]) > strlen(argv[1]))){
    printf("Error!! 0 < offset < length of string!\n");
    return 1;
  }else{
    char* sub;
    sub = (char*)malloc(atoi(argv[3]));
    sub = subStr(argv[1],atoi(argv[2]),atoi(argv[3]));
    printf("The substring that you need is :\n");
    printf("%s\n",sub);
    free(sub);
  }
  return 0;
}
