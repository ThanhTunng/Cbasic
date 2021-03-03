#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct {
	int order;
	char id[10];
	char name[30];
	char tel[15];
	float grade;
}Student;

void Text2Data(char *str1, char *str2,Student *student){
	FILE * f1;
	FILE * f2;

	if((f1 = fopen(str1,"r"))==NULL) printf("cannot open file txt\n");
	else{
		if((f2=fopen(str2,"w+b"))==NULL) printf("cannot open file dat\n");
		else{
			char buffer[90];
			int i=0;
			while(fgets(buffer,90,f1)!=NULL){
				sscanf(buffer,"%d%s%[^0-9]%s%f", 
					&(student+i)->order,
					(student+i)->id,
					(student+i)->name,
					(student+i)->tel,
					&(student+i)->grade);
				i++;
			}
			int write = fwrite(student,sizeof(Student),MAX,f2);
			printf("\tWrite = %d\n", write);

			fclose(f1); fclose(f2);
		}
	}
	return;
}

void DisplayDat(char *str2,Student *student){
	FILE * f;
	if((f = fopen(str2,"rb"))==NULL) printf("Cannot open file dat\n");
	else{
		int read = fread(student,sizeof(Student),20,f);
		printf("\tGRADE TABLE\n");
		for(int i=0;i<20;i++)
			printf("%-10d%-10s%-30s\t%-10.2f\n",(student+i)->order,(student+i)->id, (student+i)->name, (student+i)->grade);
	}
	fclose(f);
}

void SearchUpdate(char *str2,Student *student){
	FILE * f = fopen(str2,"rb");
	if(f==NULL) printf("cannot open file dat\n");
	else{
		int read = fread(student,sizeof(Student),MAX,f);
		char new[10];
		printf("Input id need updating: ");
		scanf("%s", new);
		for(int i=0;i<MAX;i++){
			if(strcmp(new,student[i].id)==0){
				printf("New grade: ");
				scanf("%f", &(student+i)->grade);
			}

		}
		fclose(f);
		f = fopen(str2,"w+b");
		if(f==NULL) printf("cannot open file dat\n");
		else{
			fwrite(student,sizeof(Student),MAX,f);
			fclose(f);
		}
	}
}

int main(int argc,char *argv[])
{
	if(argc!=3) printf("Syntax error!!\n");
	else{
		int opt;
		do{
			Student *student;
			student = (Student *)malloc(MAX*sizeof(Student));
			printf("\n\n");
			printf("1.Text2Data\n");
			printf("2.Display Data file\n");
			printf("3.Search and update\n");
			printf("4.Exit\n");
			printf("Enter your option: ");
			scanf("%d", &opt);
			switch(opt){
				case 1:{
					Text2Data(argv[1],argv[2],student);
					break;
				}
				case 2:{
					DisplayDat(argv[2],student);
					break;
				}
				case 3:{
					SearchUpdate(argv[2],student);
					break;				
				}
				case 4:{
					printf("YOu've exit the application\n");
					break;
				}
				default:{
					printf("Try again!!\n");
					getchar();
					break;				
				}
			}
			free(student);
		}while(opt!=4);
	}

	return 0;
}
