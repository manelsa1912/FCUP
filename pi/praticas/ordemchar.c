#include<stdio.h>
#include<ctype.h>
#include<string.h>

void apresentavec(int vec[],int n){

  printf("[%d", vec[0]);

  for(int i=1;i<n;i++){
    printf(", %d", vec[i]);}

  printf("]\n");
}




void ordenar(int vec[], int n){

  int i, j;

  for(i = 1;i< n; i++) {
    int x = vec[i];
    j = i-1;
    while(j>=0 && vec[j] > x) {
      vec[j+1] = vec[j];
      j--;
    }
    vec[j+1] = x;
  }
}

int main(){

  int vec[5] = {4,8,2,6,9};


  ordenar(vec, 5);

  apresentavec(vec, 5);

  return 0;
  
}
