#include <stdio.h>
#include <stdlib.h>
typedef struct phoneaddress{
  char name[20];
  char tel[12];
  char email[25];
}phoneaddr;

int main(int argc,char* argv[])
{
  if(argc!=3) printf("Error syntax!!\n ");
  else{
    phoneaddr phone[20];
    int n=atoi(argv[1]); //the num of contacts
    int num; // to return code
    /* printf("Howmany /\* contacts do you want add more?\n"); *\/ */
    /*  /\* scanf("%d", &n); *\/ */
    for(int i=0;i<n;i++){
      printf("contact %d: \n",i+1);
      printf("Enter the name: ");
      scanf(" ");
      fgets(phone[i].name,20,stdin);
      printf("Enter the phone: ");
      scanf(" ");
      fgets(phone[i].tel,12,stdin);
      printf("Enter the email: ");
      scanf(" ");
      fgets(phone[i].email,25,stdin);
    }
    FILE * f;
    if((f=fopen(argv[2],"w+b"))==NULL) printf("Cannot open the file.\n");
    else{
      //write the entire array into the file
      fwrite(phone, sizeof(phoneaddr), n, f);
      fclose(f);

      f = fopen(argv[2],"rb");
      fread(phone, sizeof(phoneaddr), n, f);
	fclose(f);
    }
    
  }
    return 0;
}
