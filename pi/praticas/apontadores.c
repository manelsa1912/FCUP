#include<stdio.h>

int main(){

  int i=0, a=1, b=2;
  int *p, *q;

  p=&a; q=&b;
  
  p=q;

  printf("valor de i:%d, de endereco %p\n", i, &i);
  printf("pointer p:%p, aponta para%d\n", p,*p);
  printf("pounter q:%p, aponta para %d\n", q, *q);

  return 0;
}

  

  
