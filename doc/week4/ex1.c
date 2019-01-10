#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, n, *p;
	printf("How many numbers do you want to enter?\n");
	scanf("%d", &n);

	//allocate an int array of the proper size//
	p = (int *)malloc(n * sizeof(int));
	if(p==NULL){
		printf("memory allocates failed\n");
		return 1;
	}
	//get the num from user
	for(int i=0;i<n;i++){
		scanf("%d", &p[i]);
	}
	//display in inverse
	for(int i=n-1;i>=0;i--)
		printf("%d\n", p[i]);
	p = (int *)realloc(p,3);
	for(int i=0;i<n+4;i++){
	  scanf("%d", &p[i]);
	}
	for(int i=0;i<n+4;i++){
	  printf("%d\n", p[i]);
	}
	//free the allocated space
	free(p);
}
