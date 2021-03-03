#include <stdio.h>
#include <time.h>
#include "BST.h"

void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  return;
}

void selectionSort(int arr[],int n){
  int min;
  for(int i=0;i<n-1;i++){
    min = i;
    for(int j=i+1;j<n;j++){
      if(arr[min]>arr[j]) min = j;
    }
    swap(&arr[i],&arr[min]);
  }
  return;
}

void insertionSort(int arr[],int n){
  
  for(int i=0;i<n;i++){
    int buff = arr[i];
    for(int j=i-1;j>=0 && buff<arr[j];j--){
      arr[j+1] = arr[j];
      arr[j] = buff;
    }
    }
  return;
}

void selfThinkingSort(int arr[],int n){
  
  for(int i=0;i<200000;i++){
    for(int j=0;j<i;j++){
      if(arr[i]<arr[j]) swap(&arr[i],&arr[j]);
    }
    }
  return;
}
/*
void pushDown(int arr[],int first, int last){
  if(first == last || first> (last-1)/2) return;

  if(last == 2*first +1){
    if(arr[first] > arr[last])
      swap(&arr[first],&arr[last]);
    //first = last
    return;
  }
  else{
    if((arr[first] > arr[2*first+1]) &&
       (arr[2*first+1]) <= arr[2*first+2]){
      swap(arr[first],arr[2*first+1]);
      pushDown(arr,2*first+1,last);
    }
    else{
      if(arr[first] > arr[2*first+2] &&
	 (arr[2*first+2] > arr[2*first+1])){
	swap(&arr[first],&arr[2*first+2]);
	pushDown(arr,2*first+2,last);
      }
      else return; //first == last
    }
    return;
  }
  }*/

void adjust(int arr[],int root, int n){
  int child;
  int temp = arr[root];
  child = 2*root;
  while(child<=n){
    if((child<n) && (arr[child] < arr[child+1]))
      child++;
    if(arr[root] > arr[child]) break;
    else{
      arr[child/2] = arr[child];
      child *=2;
    }
  }
  arr[child/2] = temp;
}

void heapSort(int arr[],int n){
  for(int i = n/2;i>0;i--)
    adjust(arr,i,n);
  for(int i = n-1;i>0;i--){
    swap(&arr[0],&arr[i]);
    adjust(arr,1,i);
  }
  return;
}



int main(){
  int arr[200000];
  
  for(int i=0;i<20;i++){
    arr[i] = rand() %20000;
  }

  clock_t begin = (double)clock();
  // insertionSort(arr,20);
  // selectionSort(arr,200000);
  heapSort(arr,20);
  clock_t end = (double)clock();

  for(int i=0;i<20;i++){
    printf("%d\n",arr[i]);
  }
   printf("\ntime: %lf (s)\n", (double)(end-begin)/CLOCKS_PER_SEC);
   return 0;
}
