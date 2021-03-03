#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phoneaddress{
  char name[20];
  char tel[12];
  char email[25];
}phoneaddress;

int main()
{
  phoneaddress* phonebook;
  FILE * f;
  int n;
  if((f=fopen("phonebook.txt","r+b"))==NULL) printf("Cannot open the file.\n");
  else{
    phonebook = (phoneaddress *)malloc(2*sizeof(phoneaddress));
    if(phonebook==NULL) printf("memo allocation failed\n");
    else{
      if(fseek(f,1*sizeof(phoneaddress),SEEK_SET)!=0) printf("fseek failed.\n");
      else{
n = fread(phonebook,sizeof(phoneaddress),2,f);
	for(int i=0;i<2;i++){
	  printf("%s \n",phonebook[i].name);
	  printf("%s \n",phonebook[i].tel);
   	  printf("%s \n",phonebook[i].email);
	//modifying
	strcpy(phonebook[i].name,"thanh tung");
	strcpy(phonebook[i].tel,"654564");
	strcpy(phonebook[i].email,"debiuebciub");
	}


	fseek(f,1*sizeof(phoneaddress),SEEK_SET);
	fwrite(phonebook, sizeof(phoneaddress),2,f);
	fclose(f);
	
      }
    }
  }
}
