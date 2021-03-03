#include <stdio.h>
#include <string.h>
#include <ctype.h>

void replace_filthyWord(char* file,char* filthy[], int n, char rpl){
	//rpl : character to replace
	//n : number of filthy word
	FILE * f;
	if((f=fopen(file, "r+"))==NULL) printf("cannot open the file.\n");
	else{
		char buffer[100];
		fscanf(f,"%s",buffer); //scan lines one by one
		while(!feof(f)){
			for(int i=0;i<n;i++){
				if(strcasecmp(buffer,filthy[i]) ==0){ //check
					size_t strLen = strlen(filthy[i]);
					fseek(f, -strLen, SEEK_CUR); //current pointer
					for(int j=0;j<strLen;j++){
						fputc(rpl,f);
					}
				}
			}
			fscanf(f,"%s",buffer);
		}
	fclose(f);
	return;
	}
}

int  main(int argc, char* argv[])
{
	char* filthyword[]={
		"shit",
		"cut",
		"damn",
		"fuck",
		"bitch",
		"bullshit"

	};
	int n = sizeof(filthyword)/ sizeof(filthyword[0]);
	if(argc!=3) {printf("There must be 3 arguments.\n");}
	else{
		char rpl = *argv[2];
		replace_filthyWord(argv[1],filthyword,n,rpl);
		printf("Finished!\n");
	}
	return 0;
}