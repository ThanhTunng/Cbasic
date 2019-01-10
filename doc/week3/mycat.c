#include <stdio.h>
#include <string.h>
#include <ctype.h>
void catToEnd(FILE *f){
	if(f==NULL) printf("Cannot open the file.\n");
    else{
			char c=fgetc(f);
      		while(c!=EOF){
				printf("%c", c);
				c=fgetc(f);
      		}
    	}
}

void catPageByPage(FILE *f){
	if(f==NULL) printf("Cannot open the file.\n");
	else{
		char c=fgetc(f);
		int count=0;
		while(c!=EOF && count<25){
			printf("%c", c);
			if(c=='\n') count++;
			c=fgetc(f);
		}
		if(count==25){
			fseek(f,-1,SEEK_CUR);
			printf("Press Enter to continue...");
			while(getchar()!='\n');

			catPageByPage(f);
		}	
	}
}

int main(int argc, char* argv[])
{
	if(argc==2){
		FILE * f = fopen(argv[1],"r");
		if(f==NULL) printf("Cannot open the file.\n");
		else{
			catToEnd(f);
			fclose(f);
		}
	}
	else if(argc==3 && (strcmp(argv[2],"-p"))==0){
		FILE * f = fopen(argv[1],"r");
		if(f==NULL) printf("Cannot open the file.\n");
		else{
			catPageByPage(f);
			fclose(f);
		}
	}
	return 0;
}