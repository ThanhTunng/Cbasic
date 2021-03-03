#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
  if(argc!=4) printf("There must be 4 arguments.\n");
  else{
    FILE * f1;
    FILE * f2;
    FILE * f3;
    if((f1=fopen(argv[1],"r"))==NULL) printf("Cannot open the file 1.\n");
    else if((f2=fopen(argv[2],"r"))==NULL) printf("cannot open the file 2.\n");
    else if((f3=fopen(argv[2],"r"))==NULL) printf("cannot open the file 3.\n");
    else{
      char buffer1[100]=fgets(f1),buffer2[100]=fgets(f2);
      while(buffer1!=NULL || buffer2!=NULL){
	fputs(buffer1,f3);
	fputs(buffer2,f3);
      }
      fclose(f1),fclose(f2),fclose(f3);
    }
  }
  return 0;
}
