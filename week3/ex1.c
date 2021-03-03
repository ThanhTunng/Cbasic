#include <stdio.h>
#define alphabet_length 26
int main(int argc, char* argv[])
{
	if(argc!=2) printf("There must be 2 arguments.\n");
	else{
		FILE * f;
		if((f = fopen(argv[1],"r"))==NULL) printf("Cannot open the file.\n");
		else{
			int i = 0;
			int count[alphabet_length] = {0};
			int c;
			while((c = fgetc(f)) !=EOF && c >= 0){
				if(c >='a' || c <= 'z')
					count[c-'a']++;
				if(c >= 'A' || c <= 'Z')
					count[c-'A']++;
			}
			fclose(f);
			FILE * f1=fopen("sourcestats.txt","w+");
			for(i=0;i<alphabet_length;i++){
				if(count[i]==1)
					printf("The letter '%c' appears 1 time.\n", 'a'+i);
					fprintf(f1, "The letter '%c' appears 1 time.\n", 'a'+i);
				if(count[i]>1)
					printf("The letter '%c' appears %d times.\n", 'a'+i, count[i]);
					fprintf(f1, "The letter '%c' appears %d times.\n", 'a'+i, count[i]);
			}
				fclose(f1);
		}
		return 0;
	}
}