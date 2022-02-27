#include<stdio.h>
#include<stdlib.h>


int abre_fich(char* fich){
        fopen(fich, "r");}

int palavra(FILE *f){

  
    






int main(int argc, char*argv[]){
  FILE *fich;
  char *pal;

  if(argc!=2){
    mensagem("Uso: ./palavras ficheiro");

  }

  fich = abre_fich(argv[1]);
  while((pal=palavra(fich)) !=NULL){
    printf(" %s\n", pal);
    free(pal);
   }
}
