#include<stdio.h>
#include<stdlib.h>

int main(int argc, const char* argv[]) {
  int soma=0;
 for(int i=1;i!=argc;i++){
   soma+=atoi(argv[i]);
 }
 printf("%d\n",soma);

  return 0;
}
  
