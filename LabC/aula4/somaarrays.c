#include <stdio.h>
#include <stdlib.h>

int* readarray(int n){

  int i;
  int *v =(int*)malloc(n*sizeof(int));
  for (i=0; i<n; i++){
    scanf("%d", v+i);
}
  return v;

}

int* somaarrays(int*a, int*b, int n){
  
  int i, *a1=a, *b1=b;
  int *v =(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    v[i]=*a1+*b1;
    a1++;
    b1++;
     }
  
    return v;
}


void printarray(int*v, int n){

  int i;
  for(i=0;i<n;i++){
    printf("%d\n", *v);
  v++;
}

  return;
  }


int main(){

  int n;
  int*va, *vb, *vr;

  scanf("%d", &n);

  va=readarray(n);
  vb=readarray(n);
  vr=somaarrays(va, vb, n);

  printarray(va, n);
  printarray(vb, n);
  printarray(vr, n);

  return 0;
}
