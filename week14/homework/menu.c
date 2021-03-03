#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct data{
  int key;
}data;

void swap(data a,data b){
  data temp;
  temp = a;
  a = b;
  b = temp;
  return;
}

void insertionSort(int arr[],int n){
  /*
  for(int i=0;i<n;i++){
    int buff = arr[i];
    for(int j=i-1;j>=0 && buff<arr[j];j--){
      arr[j+1] = arr[j];
      arr[j] = buff;
    }
    }
    return;*/
}

void selectionSort(int arr[],int n){
  /* int min;
  for(int i=0;i<n-1;i++){
    min = i;
    for(int j=i+1;j<n;j++){
      if(arr[min]>arr[j]) min = j;
    }
    swap(&arr[i],&arr[min]);
  }
  return;*/
}

void bubbleSort(int arr[],int n){
  /*
  do{
    int newn = 0;
    for(int i=1;i<n;i++){
      if(arr[i-1]>arr[i]){
	swap(&arr[i-1],&arr[i]);
	newn = i;
      }
    }
    n = newn;
  }while(n!=0);
  return;*/
}

void printData(data arr[],int n){
  for(int i=0;i<n;i++){
    printf("%d\n", arr[i].key);
  }
  return;
}

void adjust(int arr[],int root, int n){
  /* int child;
  int temp = arr[root];
  child = 2*root;
  while(child<=n){
    if((child<n)
       && (arr[child] < arr[child+1]))
      child++;
    if(temp > arr[child]) break;
    else{
      arr[child/2] = arr[child];
      child *=2;
    }
  }
  arr[child/2] = temp;*/
}

void heapSort(int arr[],int n){
  /* for(int i = n/2;i>0;i--)
    adjust(arr,i,n);
  for(int i = n-2;i>0;i--){
    swap(&arr[1],&arr[i+1]);
    adjust(arr,1,i);
  }
  return;*/
}
  /*
void adjust(int list[], int root, int n){
  int child;
  int temp;
  temp=list[root];
  
  child=2*root;
  while (child <= n) {
    if ((child < n) &&(list[child] < list[child+1]))
      child++;
    if (temp > list[child]) break;
    else {
      list[child/2] = list[child];
      child *= 2;
    }
  }
  list[child/2] = temp;
}
void heapSort(int list[], int n){
  int i;
  int temp;
  for (i=n/2; i>0; i--) adjust(list, i, n);
  for (i=n-2; i>0; i--){
    temp = list[1];
    list[1] = list[i+1];
    list[i+1] = temp;
    adjust(list, 1, i);
  }
  }*/

void quickSort(data arr[],int left,int right){
  int pivot = arr[10].key, i, j;
  if(left<right){
    i = left; j = right+1;
    pivot = arr[left].key;
  
    do{
      do i++; while(arr[i].key<=pivot);
      do j--; while(arr[j].key>pivot);
      if(i<j) swap(arr[i],arr[j]);
    }while(i<j);
    swap(arr[left],arr[j]);
    quickSort(arr,left,j-1);
    quickSort(arr,j+1,right);
  }
}

int main(){
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  data arr[2000000];
  int choice;
   do{
     printf("\n1.Regenerate data\n");
     printf("2.Insertion\n");
     printf("3.Selection\n");
     printf("4.Bubble sort\n");
     printf("5.Heap sort\n");
     printf("6.Quick sort\n");
     printf("7.Exit\n");
     printf("Enter your choice: ");
     scanf("%d", &choice);
     switch(choice){
     case 1:{
       for(int i=1;i<n+1;i++){
	 arr[i].key = rand() %5000000;
       }
       break;
     }
     case 2:{
       /*  clock_t begin = (double)clock();
       insertionSort(arr,n);
       clock_t end = (double)clock();
       printData(arr,n);
       printf("\nTIME: %lf (s)\n", (double)(end-begin)/CLOCKS_PER_SEC);*/
       break;
     }
     case 3:{/*
       clock_t begin = (double)clock();
       selectionSort(arr,n);
       clock_t end = (double)clock();
       printData(arr,n);
       printf("\nTIME: %lf (s)", (double)(end-begin)/CLOCKS_PER_SEC);
	     */break;
     }
     case 4:{/*
       clock_t begin = (double)clock();
       bubbleSort(arr,n);
       clock_t end = (double)clock();
       printData(arr,n);
       printf("\nTIME: %lf (s)\n", (double)(end-begin)/CLOCKS_PER_SEC);
	     */break;
     }
     case 5:{/*
       clock_t begin = (double)clock();
       heapSort(arr,n+1);
       clock_t end = (double)clock();
       printData(arr,n);
       printf("\nTIME: %lf (s)", (double)(end-begin)/CLOCKS_PER_SEC);
	     */break;
     }
     case 6:{
       clock_t begin = (double)clock();
       quickSort(arr,1,n);
       clock_t end = (double)clock();
       printData(arr,n);
       printf("\nTIME: %lf (s)", (double)(end-begin)/CLOCKS_PER_SEC);
       break;

       break;
     }
     case 7:{
       printf("you've exit the application\n");
       break;
     }
     default:{
       printf("Try again!!\n");
       getchar();
       break;
     }
     }
   }while(choice!=7);
   return 0;
}
