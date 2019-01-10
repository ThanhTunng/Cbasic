#include <stdio.h>
#define MAX 90
int main(int argc,char* argv[])
{
  if(argc!=3){
    printf("Error syntax!!\n");
    printf("Hint: cp 1.txt 2.txt");
  }
  else{
    FILE * f1;
    FILE * f2;
    if((f1=fopen(argv[1],"r"))==NULL) printf("Cannot open file.\n");
    else{
      if((f2=fopen(argv[2],"w"))==NULL) printf("cannot open file.\n");
      else{
	char buffer[MAX+1];
	int num;
	while(!feof(f1)){
	  num = fread(buffer,sizeof(char), MAX, f1);
	  buffer[num*sizeof(char)]='\0';

	  fwrite(buffer, sizeof(char), num, f2);
	}
      }
    }
  }
  return 0;
}
