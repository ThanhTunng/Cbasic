#include <stdio.h>
#include <stdlib.h>
//count the number of words
int count(FILE *f){
	int n;
	char c;
	while((c=fgetc(f))!=EOF){
		if(c=='\n') n++;
	}
	return n;
}

void text2Binary(char *str1,char *str2){
		FILE * f1 = fopen(str1,"r");
		FILE * f2 = fopen(str2,"w+b");

		if(f1==NULL) printf("Cannot open file .txt\n");
		else{
			if(f2==NULL) printf("cannot open file .dat\n");
			else{
				char *buffer;
				buffer =(char *)malloc(91*sizeof(char));
				int num;
				while(!feof(f1)){
					num = fread(buffer,sizeof(char),90,f1);
					buffer[num*sizeof(char)-1] = '\0';
					fwrite(buffer,sizeof(char),90,f2);
				}

				free(buffer);
				fclose(f1); fclose(f2);
		
		}	
	return;
}

void printRequest(char *str1,int start,int end){
	FILE * f= fopen(str1,"r");
	if(f==NULL) printf("cannot open file");
	else{
		char buffer[100];
		int i;
		for(i=0;i<start;i++)
			fgets(buffer,100,f);
		for(i=start;i<end;i++){
			fgets(buffer,100,f);
			printf("%s", buffer);
		}
	}
	return;
}

int main(int argc,char *argv[])
{
	if(argc!=3) printf("Syntax error!!\n");
	else{
		int start,end;
		text2Binary(argv[1],argv[2]);
		printf("Input the number to start and end: ");
		scanf("%d %d", &start, &end);
		printRequest(argv[1],start,end);
	}
	return 0;
}