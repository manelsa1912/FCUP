#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
   
   for(int i=1;i<argc;i++){
      int t=strlen(argv[i]);
      printf("%d\n", t);
      }
   
   return 0;
}