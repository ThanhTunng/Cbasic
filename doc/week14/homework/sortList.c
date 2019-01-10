#include <stdio.h>
#include <string.h>
#include "reverseword.h"

typedef struct list{
  char name[50];
  char reverseName[50]; 
}list;

void swap(list a,list b){
  list temp;
  temp = a;
  a = b;
  b = temp;
  return;
}

int countLine(){
  FILE * fr = fopen("DSSV.txt","r");
  if(fr==NULL){
    printf("Cannot open file\n");
    return 0;
  }
  int count=0;
  char c;
  while((c=getc(fr))!=EOF){
    if(c == '\n') count++; 
  }
  return count;
}

void getData(list arr[],int n){
  FILE * fr = fopen("DSSV.txt","r");
  if(fr==NULL){
    printf("Cannot open file\n");
    return ;
  }
  
  for(int i=1;i<n+1;i++){
    
    fgets(arr[i].name,50,fr);
    arr[i].name[strlen(arr[i].name)-1] = '\0';
    
    strcpy(arr[i].reverseName,arr[i].name);
    reverseWord(arr[i].reverseName);
  }
  fclose(fr);
  return ;
}

void adjust(list arr[],int root, int n){
  int child;
  list temp;
  temp = arr[root];
  child = 2*root;
  while(child<=n){
    if((child<n)
       && (strcmp(arr[child].reverseName,arr[child+1].reverseName)<0))
      child++;
    if(strcmp(temp.reverseName,arr[child].reverseName)>0) break;
    else{
      arr[child/2] = arr[child];
      child *=2;
    }
  }
  arr[child/2] = temp;
}

void heapSort(list arr[],int n){
  for(int i = n/2;i>0;i--)
    adjust(arr,i,n);
  for(int i = n-2;i>0;i--){
    list temp;
    temp = arr[1];
    arr[1] = arr[i+1];
    arr[i+1] = temp;
    adjust(arr,1,i);
  }
}
  

void quickSort(list arr[],int left,int right){
  list pivot;

  int i, j;
  if(left<right){
    i = left; j = right+1;
    pivot = arr[left];
  
    do{
      do i++; while(strcmp(arr[i].reverseName,pivot.reverseName)<0);
      do j--; while(strcmp(arr[j].reverseName,pivot.reverseName)>0);
      if(i<j){
	list temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
      };
    }while(i<j);
    list temp = arr[left];
	arr[left] = arr[j];
	arr[j] = temp;

    quickSort(arr,left,j-1);
    quickSort(arr,j+1,right);
  }
}

int main(){
  list arr[20];
  int n = countLine();
  printf("%d\n", n);
  
  getData(arr,n);

  for(int i=1;i<n+1;i++){
    printf("%s\n", arr[i].name);
  }
  
   quickSort(arr,1,n);
  // heapSort(arr,n+1);
  printf("*************Sorted List*************\n");
  for(int i=1;i<n+1;i++){
    printf("%s\n", arr[i].name);
    
  }
  return 0;
}

