#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void byChar(FILE * fin,FILE * fout){
	char c = fgetc(fin);
	while(c!=EOF){
		fputc(c,fout);
		c = fgetc(fin);
	}
	return;
}

void byLine(FILE * fin,FILE * fout){
	char *buffer;
	buffer = (char *)malloc(90 *sizeof(char));
	fgets(buffer,100,fin);
	while(!feof(fin)){
		fgets(buffer,90,fin);
		fputs(buffer,fout);
	}	
	return;
}

void byBlock(FILE * fin,FILE * fout,int size){
	char *buffer;
	buffer = (char *)malloc(size* sizeof(char));
	while(!feof(fin)){
		fread(buffer,sizeof(char),size,fin);
		fwrite(buffer,sizeof(char),size,fout);
	}
	return;
}

int main(int argc, char *argv[])
{
	if(argc!=3) printf("syntax error!!\n");
	else{
			FILE * fin = fopen(argv[1],"r");
			FILE * fout = fopen(argv[2],"w+");
			int opt;
			do{
				printf("\n\n");
				printf("Enter the way to copy you want: \n");
				printf("1.By char\n");
				printf("2.By line\n");
				printf("3.By block\n");
				printf("4.Exit\n");
				scanf("%d", &opt);
				switch(opt){
					case 1:{
						if(fin==NULL) printf("cannot open file.\n");
						else{
							clock_t start,end;
							start = clock();
							byChar(fin,fout);
							end = clock();

							double total = (double)(end-start);
							printf("Total runtime: %.3lf\n", total);
						}
						break;
					}
					case 2:{
						if(fin==NULL) printf("cannot open file.\n");
						else{
							clock_t start,end;
							start = clock();
							byLine(fin,fout);
							end = clock();

							double total = (double)(end-start);
							printf("Total runtime: %.3lf\n", total);
						}
						break;
					}
					case 3:{
						if(fin==NULL) printf("cannot open file.\n");
						else{
							int n;
							printf("Enter the size figure you want: ");
							scanf("%d", &n);
							clock_t start,end;
							start = clock();
							byBlock(fin,fout,n);
							end = clock();

							double total = (double)(end-start);
							printf("Total runtime: %.3lf\n", total);
						}
						break;
					}
					case 4:{
						printf("You've exit application.\n");
						break;
					}
					default:{
						printf("Try again!!\n");
						getchar();
						break;
					}
				}
			}while(opt!=4);
	}
	return 0;
}