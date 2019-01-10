#include <stdio.h>
#include <math.h>

int n,count;
int a[20];

//func to realize UCV
int UCVh(int j,int k){
  //UCVh takes value 1

  for(int i=1;i<k;i++){
    if((j==a[i]) || fabs(j-a[j]) == k-i) return 0;
  }

  return 1;
}

int ghiNhan(){
  count++;
  printf("%i. ",count);
  for(int i=1;i<=n;i++) printf("%i ", a[i]);
  printf("\n");
}

int Hau(int i){
  for(int j=1;j<=n;j++){
    if(UCVh(j,i)){
      a[i] = j;
      if(i==n) ghiNhan();
      else Hau(i+1);
    }
  }
}


int main(){
  printf("input n: ");
  scanf("%i", &n);

  count =0;
  Hau(1);

  if(count==0) printf("no solution\n");
  getchar();
}
