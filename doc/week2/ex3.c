#include <stdio.h>

int main(int argc,char* argv[])
{
	if(argc!=2) printf("There must be 2 arguments.\n");
	else{
	FILE * f;
	if((f = fopen(argv[1],"r+"))==NULL) {
		perror("Cannot open the file.\n");
		return 1;
	}
	else{
	char c;
	while(c!=EOF){
		c = fgetc(f);
		if((c>='a')&&(c<='z')){
			c = c -32;
			fseek(f,-1,SEEK_CUR);
			fputc(c,f);
		}
	}
	fclose(f);
	return 0;
	}
	}
}