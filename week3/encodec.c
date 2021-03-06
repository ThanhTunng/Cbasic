#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encode(FILE *SOURCE, int n){
  int c;
  while((c = fgetc(SOURCE)) != EOF){
    if(c >= 'a' && c <= 'z'){
      if ( c + n > 'z'){
	c = c + n - 'z' + 'a' - 1;
      }
      else c = c + n;
    }
    else if(c >= 'A' && c <= 'Z'){
      if ( c + n > 'Z') c = c + n - 'Z' + 'A' - 1;
      else c = c + n;
    }
    else if(c+n > 127) c = c + n - 127 - 1;
    else {
      c = c + n;
    }
    fseek(SOURCE, -1, SEEK_CUR);
    fputc(c, SOURCE);
  }
}

int main(int argc, const char* argv[]){
  if(argc == 3){
    FILE *SOURCE;
    char source_file[100];
    int encode_num = atoi(argv[2]);
    strcpy(source_file, argv[1]);
    if((SOURCE = fopen(source_file, "r+")) == NULL){
	printf("Cannot open the source file\n");
    }
    else{
      encode(SOURCE, encode_num);
      fclose(SOURCE);
    }
  }
  else printf("The program take 3 argument 'program input_file number'\n");
}