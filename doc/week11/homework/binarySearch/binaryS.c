#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int arr[100];
  int target;
  int index = -1;
  int lower = 0;
  int upper = 99;
  int mid;
  int compare=0;  
  for(int i=0;i<100;i++){
    arr[i] = i+1;
    // printf("%d\n", arr[i]);
  }
  printf("Input the number you want to search for: ");
  scanf("%d", &target);

  while(lower<=upper){
    mid = (lower+upper)/2;
    if(arr[mid]>target){
      upper = mid - 1;
      compare++;
    }
    else if(arr[mid]<target){
      lower = mid + 1;
      compare++;
    }
    else{
      index =  mid;
      break;
    }
  }  

  if(index == -1){
    printf("The number is not at the array\n");
    return 1;
  }
    printf("The number %d is at index %d and %d comparisions processed\n", target,index,compare);
    

    return 0;
}

