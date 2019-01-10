#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[])
{
  if(argc!=3) printf("Error!!There must be 3 argument.\n");
  else{
    FILE *f;
    if((f=fopen(argv[1],"w"))==NULL) printf("Cannot open the file.\n");
       else{
	 char c[1000];
	 FILE *f1=fopen(argv[2],"w+");
	 while(fgets(c,1000,f)!=NULL){
	   fprintf(argv[2],"&d %s",strlen(c)-1,c);
	   printf("%s", c);
	   }
	 fclose(f1);fclose(f);
	 }
       }
  return 0;
}
