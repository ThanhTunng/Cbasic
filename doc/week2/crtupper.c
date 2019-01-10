#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc,char* argv[])
{
	if(argc!=2) perror("There must be 2 arguments.\n");
	FILE * f1;
	char ch[100];
	char str[1000];
	strcpy(ch,argv[1]);
	if((f1=fopen(ch,"r"))==NULL){
		printf("Cannot open the file.\n");
		return 1;
	}
	// FILE * f2 = fopen("temp.txt","w+");
	char c;
	int i=0;
	while((c=fgetc(f1))!=EOF){
		if(islower(c)) c = toupper(c);
		str[i] = c;
		i++;
	}
	fputs(str,f1);
	 fclose(f1); //fclose(f2);
	// rename("temp.txt",argv[1]);
	return 0;

} 