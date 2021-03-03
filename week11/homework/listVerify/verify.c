#include <stdio.h>

typedef struct dataType{
  int key;
  int val;
}type;

void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  return;
}

void insertionSort(type arr[],int n){
  for(int i=0;i<n;i++){
    int j=i;
    while(j>0 && arr[j].val<arr[j-1].val){
      swap(&arr[j].val,&arr[j-1].val);
      j--;
    }
  }
  return;
}

int binarySearch(type arr[],int size,int target){
  int mid;
  int lower=0,upper=size-1;
  while(lower<=upper){
    mid = (lower+upper)/2;
    if(arr[mid].val<target) lower = mid+1;
    else if(arr[mid].val>target) upper = mid-1;
    else return mid;
  }
  return -1;
}

int linearSearch(type arr[],int n,int target){
  for(int i=0;i<n;i++){
    if(arr[i].key == target) return i;
  }
  return -1;
}

void verification1(type arr1[],type arr2[],int n){
  for(int i=0;i<n;i++){
    int index = binarySearch(arr1,n,arr2[i].val);
    if(index==-1) printf("{%d,%d}\n", arr1[i].key, arr1[i].val);
  }
  return;
}

void verification2(type arr1[],type arr2[],int n){
  for(int i=0;i<n;i++){
    int index = binarySearch(arr2,n,arr1[i].val);
    if(index==-1) printf("{%d,%d}\n", arr2[i].key, arr2[i].val);
  }
  return;
}

void verification3(type arr1[],type arr2[],int n){
  for(int i=0;i<n;i++){
    int index = binarySearch(arr1,n,arr2[i].key);
    if(index!=-1 && arr1[index].val == arr2[index].val){
      printf("{%d,%d}--{%d,%d}\n", arr1[i].key, arr1[i].val,arr2[index].key, arr2[index].val);
    }
  }
  return;
}

int main(){
  type arr1[] = {
    {1,2}, {3,4}, {5,6}, {7,8}, {9,10}, {10,15}, {11,16}
  };
  type arr2[] = {
    {5,6}, {7,8}, {9,10}, {11,12}, {13,14}, {10,17}, {9,18}
  };
  insertionSort(arr1,7);
  insertionSort(arr2,7);
  int choice;
  do{
    printf("1.print all records found in list 1 but not in list2\n");
    printf("2.print all records found in list 2 but not in list1\n");
    printf("3.print all records found in list 1 and list 2 with the same key but different values\n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
    case 1:{
      verification1(arr1,arr2,7);
      break;
    }
    case 2:{
      verification2(arr1,arr2,7);
      break;
    }
    case 3:{
      verification3(arr1,arr2,7);
      break;
    }
    case 4:{
      printf("you've exit the application\n");
      break;
    }
    default:{
      printf("Try again!!\n");
      getchar();
      break;
    }
    }
  }while(choice!=4);
  return 0;
}
