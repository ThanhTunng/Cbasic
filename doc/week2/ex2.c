#include <stdio.h>
#include <string.h>
enum{success,fail};

void copy(FILE* fin,FILE* fout){
	char c;
	while((c=fgetc(fin))!= EOF){
		fputc(c,fout); //write to a file//
	}
}

int main(int argc, char * argv[])
{
	int reval=success;

	if(argc!=3) printf("There must be 3 arguments included 2 text file, original file and new file, respectively.\n");
	else{

		FILE * f1;
		FILE * f2;
		char ch1[1000],ch2[1000];
		strcpy(ch1,argv[1]); strcpy(ch2,argv[2]);
		if((f1 = fopen(ch1,"r"))==NULL){
			printf("Cannot open the first file.\n");
			reval=fail;
		}
		else if((f2 = fopen(ch2,"w"))==NULL){
			printf("Cannot open the second file.\n");
			reval=fail;
		}
		else{

			copy(f1,f2);
			fclose(f1); fclose(f2);
		}
	}
	return reval;
}