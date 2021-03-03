#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct data{
  int key;
}data;

void swap(data *a,data *b){
  int temp;
  temp = (*a).key;
  (*a).key = (*b).key;
  (*b).key = temp;
  return;
}
void quickSort(data arr[],int left,int right){
  int pivot = arr[left].key, i, j;
  if(left<right){
    i = left; j = right+1;
    pivot = arr[left].key;
  
    do{
      do i++; while(arr[i].key<=pivot);
      do j--; while(arr[j].key>pivot);
      if(i<j) swap(&arr[i],&arr[j]);
    }while(i<j);
    swap(&arr[left],&arr[j]);
    quickSort(arr,left,j-1);
    quickSort(arr,j+1,right);
  }
}

int main(){
  data a[5];
  srand(time(NULL));
  for(int i=0;i<5;i++){
    a[i].key = rand() %500;
   }
  quickSort(a,0,4);
  for(int i=0; i<5;i++) printf("%d\n", a[i].key);
}
