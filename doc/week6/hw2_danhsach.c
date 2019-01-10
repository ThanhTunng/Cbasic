#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define max 100
typedef struct 
{
	int order;
	char id[10];
	char name[30];
	char tel[15];
	float grade;
}student;

int main(){
	student *stu;
	stu = (student*)malloc(max*sizeof(student));
	int choice;
	printf("1. Grade.dat\n2. Display grade.dat file\n3. Search and update\n4. Quit\n\n");
	do{
		printf("Enter your choice: "); scanf("%d", &choice);
		switch(choice){
			case 1:{
				FILE* fr1 = fopen("bang_diem.txt", "r");
				if(fr1==NULL){
					printf("Cannot open bang_diem.txt\n");
					return 1;
				}
				FILE* fw1 = fopen("grade.dat", "w+b");
				if(fw1==NULL){
					printf("Cannot open grade.dat\n");
					return 1;
				}
			//	int read = fread(stu, sizeof(student), 20, fr1);
				char s[80];
    			int count = 0;
    			while(fgets(s,80,fr1)!=NULL){
        			sscanf(s,"%d%s%[^0-9]%s%f",&(stu+count)->order, (stu+count)->id, (stu+count)->name, (stu+count)->tel,&(stu+count)->grade);
        			count++;
    			}
				int write  = fwrite(stu, sizeof(student), 20, fw1);
				printf("\tWrite = %d\n", write);
				fclose(fr1);
				fclose(fw1);
				break;
			}

			case 2:{
				FILE* fr2 = fopen("grade.dat", "rb");
				if(fr2==NULL){
					printf("Cannot open grade.dat\n");
					return 1;
				}
				int read = fread(stu, sizeof(student), 20, fr2);
				printf("Read = %d\n",read);
				printf("\tBANG DIEM\n\n");
				for(int i=0;i<20;i++){
					printf("%-30s\t%-10.2f\n",(stu+i)->name, (stu+i)->grade);
				}
				fclose(fr2);
				break;
			}
			case 3:{
				int mark;
				FILE* fr3 = fopen("grade.dat", "rb");
				if(fr3==NULL){
					printf("Cannot open grade.dat\n");
					return 1;
				}
				int read = fread(stu, sizeof(stu), 20,fr3);
				char new_id[10];
				printf("Enter id need to update:"); scanf("%s", new_id);
				for (int i = 0; i < 20; i++)
				{
					if(strcmp(new_id,(stu+i)->id)==0){
						printf("New grade: "); scanf("%f", &(stu+i)->grade);
						mark = i;
					}
				}
				fclose(fr3);
				FILE* fw3 = fopen("grade.dat", "wb");
				if(fw3==NULL){
					printf("Cannot open\n");
				}
				else{
					
					fwrite(stu, sizeof(stu), 20, fw3);
				}
				fclose(fw3);

				break;
			}
			case 4: break;
		}
	}while(choice!=4);
	free(stu);
} 
