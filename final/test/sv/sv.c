#include <stdio.h>
#include "BST.h"

int countLines(){
  FILE * f = fopen("sinhvien.txt", "r");
  char c;
  int count = 0;
  while((c=fgetc(f))!=EOF){
    if(c=='\n') count++;
  }
  fclose(f);
  return count;
}

void getData(BSTnode **root,int n){
  FILE * fr = fopen("sinhvien.txt","r");
  if(fr==NULL){
    printf("cannot open file\n");
    return;
  }
  BSTtype temp[20];
  for(int i=1;i<=n;i++){
    fscanf(fr,"%s%s%f",temp[i].userName,temp[i].passWord,&temp[i].mark);
    BSTinsertNode(root,temp[i]);
  }

  return;
}

int main(){
  BSTnode *root;
  BST_initial(&root);
  int n = countLines();
  getData(&root,n);
  inOrder(root);
  int choice;
  do{
    printf("\n1.Log in\n");
    printf("2.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
    case 1:{
      int opt;
      printf("\n1.Student\n");
      printf("2.Admin\n");
      printf("You are: ");
      scanf("%d",&opt);

      switch(opt){
      case 1:{
	char logIn[20];
	char pass[20];
	int count=0;
	do{
	  count++;
	  if(count>3){
	    printf("3 times failed... Exit\n");
	    return 0;
	  }
	
	  printf("Enter account: ");
	  scanf("%s",logIn);
	  printf("Enter password (at least 6 characters): ");
	  scanf("%s",pass);
	  //logIn[strlen(logIn)-1] = '\0';
	  // pass[strlen(pass)-1] = '\0';
	}while(search(root,logIn,pass)==NULL);

	int option;
	do{
	  printf("1.Result\n");
	  printf("2.Change password\n");
	  printf("3.Update to server and exit\n");
	  printf("Option: ");
	  scanf("%d",&option);

	  switch(option){
	  case 1:{
	    BSTnode *temp = search(root,logIn,pass);
	    printf("%-10s%-10s\n","Name","Mark");
	    printf("%-10s%-10.1f\n",temp->data.userName,temp->data.mark);
	    break;
	  }
	  case 2:{
	    char newPass1[10]; char newPass2[10];
	    do{
	      printf("Enter old pass: ");
	      scanf("%s",newPass1);
	      printf("Enter old pass again: ");
	      scanf("%s",newPass2);
	    }while(strcmp(newPass1,newPass2)!=0);

	    char newPass3[10];
	    printf("Enter new password: ");
	    scanf("%s",newPass3);
	    
	    BSTtype temp = search(root,logIn,pass)->data;
	    strcpy(temp.passWord,newPass3);
	    BSTinsertNode(&root,temp);
	    printf("\nPassword changed successfully\n");
	    break;
	  }
	  case 3:{
	    inOrderPrintFile(root,"sinhvien.txt");
	    break;
	  }
	  default :{
	    printf("try again!!");
	    getchar();
	    break;
	  }
	  }	
	}while(option!=3);
	break;
      } //done student

      case 2:{
	break;
      }//done admin
	
      default:{
	printf("try again!!\n");
	getchar();
	break;
      }
      } // done big switch
    }
    }
  }while(choice!=2);
  return 0;
}
