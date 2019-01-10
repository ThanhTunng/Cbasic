#include <stdio.h>
#include <string.h>

void replace(char* origin, char* substr, char* replstr);

int main(int argc, char* argv[])
{
	if(argc!=4)
		printf("There must be 4 arguments!!!");
	else{
		replace(argv[1],argv[2],argv[3]);
		printf("%s\n", argv[1]);
	}
	return 0;
}

void replace(char* origin, char* substr, char* replstr){
	char buff[1000];
	char *ch;
	if(!(ch=strstr(origin,substr))) return ;
	strncpy(buff, origin, ch-origin);
	buff[ch-origin]=0;
	sprintf(buff+(ch-origin),"%s%s", replstr, ch + strlen(substr));
	origin[0]=0;
	strcpy(origin,buff);
	return replace(origin, substr, replstr); 
}