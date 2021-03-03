#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void inSort(int list[], int n)
{
  int i, j;
  int next;
  for (i=1; i<n; i++) {
    next= list[i];
    for (j=i-1;j>=0 && next< list[j];j--)
      list[j+1] = list[j];
    list[j+1] = next;
  }
}
void secSort(int arr[],int n){
  for(int i = 0;i<n;i++){
    int min = i;
    for(int j = i+1;j<n-1;j++){
      if(arr[j] < arr[min]){
	min = j;
      }
      int tmp = arr[i];
      arr[i] = arr[min];
      arr[min] = tmp;
    }
  }
}

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
}

void bubble(int arr[], int n){
  int temp,i,j;
  int check ;
  for(i=0;i<n-1;i++){

    check =0;

    for(j=0;j<n-1-i;j++){

      if(arr[j] > arr[j+1]){

	temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp;

	check = 1;
      }
    }
    if(check == 0) break;
  }
  return;
}
int main()
{
  int arr[2000000],op;
  time_t t;
  srand((unsigned) time(&t));
  for(int i=0;i<2000000;i++){
    arr[i] = rand() % 10000000;
  }
  do{
    printf("[************************]\nSorting option\n");
    printf("1. InSort.\n");
    printf("2. SecSort.\n");
    printf("3. HeapSort.\n");
    printf("4. BubbleSort\n");
    printf("5. Exit.\n");
    printf("Please choose your option: ");
    scanf("%d", &op);
    switch(op){
    case 1:{
      clock_t tic = clock();
      inSort(arr,2000000);
      clock_t toc = clock();
      for(int i=1;i<2000000;i++){
	printf("%d ", arr[i]);
      }

      printf("\n");
      printf("Time: %f seconds\n", (double)(toc-tic)/CLOCKS_PER_SEC);
      break;
    }
    case 2:{
      clock_t tic = clock();
      secSort(arr,2000000);
      clock_t toc = clock();
      for(int i=1;i<2000000;i++){
	printf("%d ", arr[i]);
      }

      printf("\n");
      printf("Time: %f seconds\n", (double)(toc-tic)/CLOCKS_PER_SEC);
      break;
    }
      case 3:{
      clock_t tic = clock();
      heapSort(arr,2000000);
      clock_t toc = clock();

      for(int i=1;i<2000000;i++){
	printf("%d ", arr[i]);
      }

      printf("\n");
      printf("Time: %f seconds\n", (double)(toc-tic)/CLOCKS_PER_SEC);

      break;
    }
	case 4:{
	  clock_t tic = clock();
	  bubble(arr,2000000);
	  clock_t toc = clock();

	  for(int i=1;i<2000000;i++){
	    printf("%d ", arr[i]);
	  }

	  printf("\n");
	  printf("Time: %f seconds\n", (double)(toc-tic)/CLOCKS_PER_SEC);
	  break;
	}
    }
  }while(op != 5);
 
  
  
  return 0;
}
