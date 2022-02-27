#include<stdio.h>

int main(){
  char c, *ptrc;
    c='.';
  ptrc=&c;
  printf("tamanho: %lu\n", sizeof(c));
  printf("tamanho do endereco: %lu\n", sizeof(&c));
  printf("tamanho do apontador:%lu\n", sizeof(ptrc));
  printf("tamanho do valor apontado: %lu\n", sizeof(*ptrc));
  printf("Valores '%p', '%p', '%c' e '%c'\n\n", &c, ptrc, c, *ptrc);


  int a=3, *ptra;
  ptra=&a;
  
  printf("tamanho: %lu\n", sizeof(a));
  printf("tamanho do endereco: %lu\n", sizeof(&a));
  printf("tamanho do apontador:%lu\n", sizeof(ptra));
  printf("tamanho do valor apontado: %lu\n", sizeof(*ptra));
  printf("Valores '%p', '%p', '%d' e '%d'\n\n", &a, ptra, a, *ptra);

  float b=6.9, *ptrb;
  ptrb=&b;
  
  printf("tamanho: %lu\n", sizeof(b));
  printf("tamanho do endereco: %lu\n", sizeof(&b));
  printf("tamanho do apontador:%lu\n", sizeof(ptrb));
  printf("tamanho do valor apontado: %lu\n", sizeof(*ptrb));
  printf("Valores '%p', '%p', '%f' e '%f'\n\n", &b, ptrb, b, *ptrb);



  return 0;
}
