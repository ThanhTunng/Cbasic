#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char model[20];
	char storage[10];
	float display;
	char price[10];
}phoneDB;


//func count number of phones
int count(char *fin){
	FILE * f=fopen(fin,"r");
	int n;
	char c = fgetc(f);
	while(c!=EOF){
		if(c=='\n') n++;
		c=fgetc(f);
	}
	fclose(f);
	return n;
}

//import to Database from text
void text2Data(char * fin,char *fout,phoneDB *phone,int n){
	FILE * f1;
	FILE * f2;
	if((f1 = fopen(fin,"r"))==NULL) printf("cannot open file .txt\n");
	else{
			char buffer[90];
			for(int i=0;i<n;i++){
				sscanf(buffer, "%s%s%f%s",
								(phone+i)->model,
								(phone+i)->storage,
								&(phone+i)->display,
								(phone+i)->price);
			}
		if((f2 = fopen(fout,"w+b"))==NULL) printf("cannot open file .dat");
		else{
			fwrite(phone, sizeof(phoneDB),n,f2);
		}
		
		fclose(f1); fclose(f2);
	}
	return;
}


// //read from dataBase
void ImportFromDB(char *str2,phoneDB *phone){
	FILE * f = fopen(str2,"rb");
	if(f==NULL) printf("cannot open file\n");
	else{
		int num;
		int position;
		printf("Choose position to access file: \n");
		printf("1.From the beginning\n");
		printf("2.From the end\n");
		scanf("%d", &position);
		printf("Input the number of models you want: ");
		scanf("%d", &num);
		switch(position){
			case 1:{
				fread(phone,sizeof(phoneDB),num,f);
				for(int i=0;i<num;i++){
					printf("%-20s%-10s%-10.1f%-10s\n",
							(phone+i)->model,
							(phone+i)->storage,
							(phone+i)->display,
							(phone+i)->price);
				}
				break;
			}
			case 2:{
				fseek(f,-num,SEEK_END);
				fread(phone,sizeof(phoneDB),num,f);
				for(int i=0;i<num;i++){
					printf("%-20s%-10s%-10.1f%-10s\n",
							(phone+i)->model,
							(phone+i)->storage,
							(phone+i)->display,
							(phone+i)->price);
				}
				break;
			}
		}
		fclose(f);
	}

	return;
}


//print out data
void printOut(char *str2,phoneDB *phone,int n){
	FILE * f =fopen(str2,"rb");
	if(f==NULL) printf("cannot open file\n");
	else{
		fread(phone,sizeof(phoneDB),n,f);
		for(int i=0;i<n;i++){
			if(strstr((phone+i)->model, "Nokia")){
				for(int i=0;i<n;i++){
					printf("%-20s%-10s%-10.1f%-10s\n",
							(phone+i)->model,
							(phone+i)->storage,
							(phone+i)->display,
							(phone+i)->price);
				}
			}
		}
		fclose(f);

	}
	return;
}

void search(char *str2,phoneDB *phone,int n){
	FILE * f = fopen(str2,"rb");
	if(f==NULL) printf("cannot open file\n");
	else{
		char search[20];
		printf("Enter the model you want to search for: ");
		scanf("%s", search);
		fread(phone,sizeof(phoneDB),n,f);
		for(int i=0;i<n;i++){
			if(strstr((phone+i)->model,search)){
				printf("%-20s%-10s%-10.1f%-10s\n",
							(phone+i)->model,
							(phone+i)->storage,
							(phone+i)->display,
							(phone+i)->price);
			}
		}
		fclose(f);
	}
	return;
}


int main(int argc,char *argv[])
{
	if(argc!=3){
		 printf("Syntax error!!\n");
		return 1;
	}
	else
	{
		int opt;
		do{
			int n = count(argv[1]); //count number of phones
			phoneDB *phone;
			phone = (phoneDB *)malloc(n*sizeof(phoneDB));
			printf("\n\n");
			printf("1.Import DB from text\n");
			printf("2.Import from DB\n");
			printf("3.Print out all a kind of smartphone database\n");
			printf("4.Search for model\n");
			printf("5.Exit\n");
			printf("Enter your option: ");
			scanf("%d", &opt);
			switch(opt){
				case 1: {
					text2Data(argv[1],argv[2],phone,n);
					break;
				}
				case 2: {
					ImportFromDB(argv[2],phone);
					break;
				}
				case 3: {
					printOut(argv[2],phone,n);
					break;
				}
				case 4: {
					search(argv[2],phone,n);
					break;
				}
				case 5: {
					printf("You've exit the application\n");
					break;
				}
				default:{
					printf("Try again!!\n");
					getchar();
					break;
				}
			}
		}while(opt!=5);
	}

	return 0;
}