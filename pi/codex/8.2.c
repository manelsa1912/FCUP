#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ordenada(int vec[], int size){
  int i;

 for(i=0;i<size;i++){

   if(vec[i]>vec[i+1]){
      break;
      return 0;
    }
 }
 return 1;
}

int main(){

  int i, p;

  p=ordenada(i);

  scanf("%d", &i);
  printf("d", p);

  return 0;

}

 

  
