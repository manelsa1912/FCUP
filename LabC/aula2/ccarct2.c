#include<stdio.h>
#include<string.h>

int poiu(char str[]){
  int soma=0;
  for(int i=0; str[i]!='\0';i++){
    soma++;}

  return soma;
}


int main(int argc,char* argv[]) {
  for(int i=1;i!=argc;i++)
    printf("%d\n", poiu(argv[i]));
  return 0;
}
