#include <stdio.h>
#include <stdlib.h>
typedef struct phone{
  char name[15];
  char number[12];
  char mail[30];
}phone;

int countLine(char *name){
  FILE * f = fopen(name,"r");
  char c;
  int count=0;
  while((c=fgetc(f))!=EOF){
    if(c == '\n') count++;
  }
  return count;
}

int main(){  
  int count = countLine("contact.txt");
  phone * list = (phone *)malloc(50*sizeof(phone));
  FILE * fr = fopen("contact.txt","r");
  FILE * fw = fopen("contact.dat","w+b");
  int c=0;
  char buffer[90];
  printf("%d\n", count);
  while(fgets(buffer,90,fr)!=NULL){
    sscanf(buffer, "%s%s%s", (list+c)->name, (list+c)->number, (list+c)->mail);
    c++;
  }
  fwrite(list, sizeof(list), count, fw);
  fclose(fr); fclose(fw);

  free(list);
  return 0;
  
}
