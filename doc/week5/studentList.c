#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  char stt[3];
  char ID[10];
  char name[40];
  char number[10];
  double grade;
}student;

student List[90];
int main(int argc, char*argv[])
{
  if(argc != 2){
    printf("Syntax Error!!\n");
    printf("Form : studentlist student\n");
    return 1;
  }else{
    FILE * f,*f1;
    f=fopen(argv[1],"r");
    if(f == NULL){
      printf("Cannot open file %s !\n",argv[1]);
      return 1;
    }else{
      int tabIndex[3];
      char line[100];
      int stuCnt=0;
      while((fgets(line,100,f)) != NULL){
	int cnt=0;
	for(int i=0;i<strlen(line);i++){
	  if(line[i] == '\t'){
	    tabIndex[cnt]=i;
	    cnt++;
	  }
	}
	strncpy(List[stuCnt].stt,line,tabIndex[0]);
	strncpy(List[stuCnt].ID,line+tabIndex[0]+1,(tabIndex[1]-tabIndex[0]-1));
	strncpy(List[stuCnt].name,line+tabIndex[1]+1,(tabIndex[2]-tabIndex[1]-1));
	strncpy(List[stuCnt].number,line+tabIndex[2]+1,strlen(line+tabIndex[2]+1)-1);
	stuCnt++;
      }
      f1=fopen("grade","w+");
      fprintf(f1,"%-3s\t%-8s\t%-25s\t%-10s\t%-5s\n","STT","ID","Name","Phone","Grade");
      printf("Enter the grade of student :\n");
      for(int i=0;i<stuCnt;i++){
	printf("%s : ",List[i].name);
	scanf("%lf",&List[i].grade);
	fprintf(f1,"%-3s\t%-8s\t%-25s\t%-10s\t%g\n",List[i].stt,List[i].ID,List[i].name,List[i].number,List[i].grade);
      }
    }
    fclose(f);
    fclose(f1);
  }
  return 0;
}
