#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
   
   for(int i=1;i<argc;i++){
      int s=0;
      while (argv[i]!='\0') s++;

      printf("%d\n", s);
      }
   
   return 0;
}