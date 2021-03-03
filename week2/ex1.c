#include <stdio.h>
#include <string.h>
void replace(char * o_string, char * s_string, char * r_string);
int main(int argc, char* argv[])
{
	if(argc!=4) printf("There must be 4 arguments!!\n");
	else{
		replace(argv[1],argv[2],argv[3]);
		printf("%s\n", argv[1]);
	}	
	return 0;
}

void replace(char * o_string, char * s_string, char * r_string) {
      //a buffer variable to do all replace things
      char buffer[1000];
      //to store the pointer returned from strstr
      char * ch;
 
      //first exit condition
      if(!(ch = strstr(o_string, s_string)))
              return;
 
      //copy all the content to buffer before the first occurrence of the search string
      strncpy(buffer, o_string, ch-o_string);
 
      //prepare the buffer for appending by adding a null to the end of it
      buffer[ch-o_string] = 0;
 
      //append using sprintf function
      sprintf(buffer+(ch - o_string), "%s%s", r_string, ch + strlen(s_string));
 
      //empty o_string for copying
      o_string[0] = 0;
      strcpy(o_string, buffer);
      //pass recursively to replace other occurrences
      return replace(o_string, s_string, r_string);
 }
