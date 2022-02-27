#include<stdio.h>

int main(int argc,char *argv[]){

char c='a', *cptr;
cptr = &c;

printf("tamanho de um char: %lu\n", sizeof(c));
printf("tamanho do endereço de um char: %lu\n", sizeof(&c));
printf("tamanho de um apontador para um char: %lu\n", sizeof(cptr));
printf("tamanho do conteúdo apontado por um apontador para um char: %lu\n",sizeof(*cptr));
printf("Os valores apontados pelos endereços '%p' e '%p' são '%c' e '%c'\n", &c,cptr, c, *cptr);

return 0;
  
}