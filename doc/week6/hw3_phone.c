#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
typedef struct {
	char model[20];
	char memory[10];
	float display;
	char price[10];
} phone;

int main(){
	phone* list;
	list = (phone*)malloc(max*sizeof(phone));
	int choice;
	int count = 0;
	do{
		printf("\n1. Import DB from text file\n2. Read DB from binary file\n3. Print Nokia DB\n4. Search by model\n5. Quit\n\n ");
		printf("*Your choice: "); scanf("%d", &choice);
		switch(choice){
			case 1:{
				FILE* fr = fopen("phoneDB.txt", "r");
				if(fr==NULL){
					printf("Cannot open phoneDB.txt\n");
					return 1;
				}
				char s[80];
				
				while(fgets(s, 80, fr)!=NULL){
					sscanf(s,"%s%s%f%s",(list+count)->model, (list+count)->memory, &(list+count)->display, (list+count)->price);
					count++;
				}
				FILE* fw = fopen("phoneDB.dat", "w+b");
				if(fw==NULL){
					printf("Cannot open phoneDB.dat\n");
					return 1;
				}
				fwrite(list, sizeof(phone), count, fw);
				fclose(fr);
				fclose(fw);
				break;
			}
			case 2:{
				int vi_tri, so_phan_tu;
				FILE* fr = fopen("phoneDB.dat", "rb");
				if(fr==NULL){
					printf("Cannot open phoneDB.dat\n");
					return 1;
				}
				printf("Position to access file\n\tFrom the beginning: Press 1\n\tFrom the end: Press 2\n"); scanf("%d", &vi_tri);
				printf("Number of products: "); scanf("%d", &so_phan_tu);
				switch(vi_tri){
					case 1:{
						fread(list, sizeof(phone), so_phan_tu, fr);
						for(int i=0;i<so_phan_tu;i++){
							printf("%-20s%-10s%-10.1f%-10s\n",(list+i)->model,(list+i)->memory,(list+i)->display,(list+i)->price);
						}
						break;
					}
					case 2:{
						int c = 0 - so_phan_tu;
						fseek(fr,c*sizeof(phone), SEEK_END);
						fread(list, sizeof(phone), so_phan_tu, fr);
						for(int i=0;i<so_phan_tu;i++){
							printf("%-20s%-10s%-10.1f%-10s\n",(list+i)->model,(list+i)->memory,(list+i)->display,(list+i)->price);
						}
						break;						
					}
				}
				fclose(fr);
				break;
			}
			case 3:{
				FILE* fr = fopen("phoneDB.dat", "rb");
				if(fr==NULL){
					printf("Cannot open phoneDB.dat\n");
					return 1;
				}
				fread(list, sizeof(phone), count, fr);
				printf("\nNOKIA\n\n");
				for (int i = 0; i < count; i++)
				{
					if(strstr((list+i)->model, "Nokia")){
						printf("%-20s%-10s%-10.1f%-10s\n",(list+i)->model,(list+i)->memory,(list+i)->display,(list+i)->price);
					}
				}
				fclose(fr);
				break;
			}
			case 4:{
				FILE* fr = fopen("phoneDB.dat", "rb");
				if(fr==NULL){
					printf("Cannot open phoneDB.dat\n");
					return 1;
				}
				fread(list, sizeof(phone), count, fr);
				char search[20];
				printf("Enter product you want to find: "); scanf("%s", search);
				int dem = 0;
				for (int i = 0; i < count; i++)
				{
					if(strstr((list+i)->model, search)){
						printf("%-20s%-10s%-10.1f%-10s\n",(list+i)->model,(list+i)->memory,(list+i)->display,(list+i)->price);
						dem++;
					}
				}
				if(dem==0) printf("No result!!!\n\n");
				fclose(fr);
				break;				
			}
			case 5: break;
			default: printf("Try again\n");
		}
	}while(choice!=5);
	free(list);
	return 0;
}