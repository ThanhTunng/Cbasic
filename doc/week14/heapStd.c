#include <stdio.h>
#include "reserveword.h"
#include <string.h>
typedef struct {
  char name[50];
  char reversename[50];
}STD;

void getData(char *fin,STD arr[],int n){
  FILE *f = fopen(fin,"r");
  if(f == NULL){
    printf("cannot open the file!!");
    return;
  }else{
    

    for(int i=1;i<n;i++){
      
      fgets(arr[i].name,50,f);
      arr[i].name[strlen(arr[i].name)-1] = '\0';
      
      strcpy(arr[i].reversename,arr[i].name);
      reverseWord(arr[i].reversename);
      
    }
  }
  fclose(f);
  return;
}
int compare(char *s1, char *s2){

  if(strcmp(s1,s2) >  0){
    return 1;
  }else if(strcmp(s1,s2) < 0){
    return -1;
  }else return 0;
}

void adjust(STD arr[],int root,int n){
  int child;
  STD temp;

  temp = arr[root];
  child = 2*root;
  while(child <= n){

    if((child < n) && (compare(arr[child].reversename,arr[child+1].reversename) == -1)){
      child++;
    }
    if(compare(temp.reversename,arr[child].reversename) == 1) break;
    else{
      arr[child/2] = arr[child];
      child *=2;
    }
  }

  arr[child/2] = temp;
}
void heapSort(STD arr[], int n){
  int i,j;
  STD temp;

  for(i=n/2;i>0;i--) adjust(arr,i,n);

  for(i=n-2; i>0; i--){
    temp = arr[1];
    arr[1] = arr[i+1];
    arr[i+1] = temp;

    adjust(arr,1,i);
  }
}

      
int main()
{
  STD arr[15];
  getData("DSSV.txt",arr,15);
  for(int i=1;i<15;i++){
    printf("%s\n", arr[i].name);
  }
  heapSort(arr,15);
  printf("****************************\nThe sorted list is:\n");
  for(int i=1;i<15;i++){
    printf("%s\t%s\n", arr[i].name,arr[i].reversename);
  }
  return 0;
}
