#include <stdio.h>
#include <stdlib.h>
#define max 1000
typedef struct 
{
	char vn[30];
	char eng[50];
}word;

int main(){
	word* w;
	w = (word*)malloc(100000*sizeof(word));  
	if(w==NULL){
		printf("Memory allocation failed!\n");
		return 1;
	}  
	FILE* fr = fopen("vnedict.txt","r");
	if(fr==NULL){
		printf("Cannot open vnedict.txt\n");
		return 1;
	}
	FILE* fw = fopen("vn.dat","w+b");
	if(fw==NULL){
		printf("Cannot open vn.dat\n");
		return 1;
	}

	int count =0;

	char s[80];
	while(fgets(s, 80, fr)!=NULL){
		sscanf(s,"%[^:]%[^\n]", (w+count)->vn,(w+count)->eng);
		count++;
	}
	fwrite(w, sizeof(word), count,fw);

	fclose(fr);
	fclose(fw);

	int begin, end;
/*	word* w;
	w = (word*)malloc(max*sizeof(word));  
	if(w==NULL){
		printf("Memory allocation failed!\n");
		return 1;
	}  */
	FILE* f = fopen("vn.dat", "rb");
	printf("Begin: "); scanf("%d", &begin);
	printf("End: "); scanf("%d", &end);
	if(end < begin||begin > count){
		printf("Oops\n");
	}
	else if(begin==1){
		fread(w, sizeof(word), end - begin +1 , f);
		for (int i = 0; i < end - begin +1 ; ++i)
		{
			printf("%s%s\n",(w+i)->vn,(w+i)->eng);
		}
	}
	else{
		fseek(f,(begin-1)*sizeof(word), SEEK_SET);
		fread(w, sizeof(word), end - begin +1 , f);
		for (int i = 0; i < end - begin +1 ; ++i)
		{
			printf("%s%s\n",(w+i)->vn,(w+i)->eng);
		}
	}
	fclose(f);
	free(w);

	return 0;
}