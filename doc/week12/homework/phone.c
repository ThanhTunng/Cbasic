#include <stdio.h>
#include "binaryTree.h"


typedef struct phoneAddr{
  char name[30];
  char tel[12];
  char email[30];
}phone;

int counting(char *file){
  int count=0;
  FILE *f = fopen(file,"r");
  char c;
  while(c=fgetc(f)!= EOF){
    if(c=='\n') count++;
  }
  return count;
}

void readDataFromText(char *file,int count){
  FILE *fr =fopen(file,"r");
  if(fr==NULL){
    printf("Cannot open file\n");
    return;
  }
  while(!feof(fr)){
    
  }
}

int main(){
  
}
