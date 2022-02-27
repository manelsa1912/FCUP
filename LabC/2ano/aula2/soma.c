#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
   int s=0;
   
   for(int i=1;i<argc;i++){
      
      int v= atoi(argv[i]);
      s+=v;
   }
   
   printf("%d\n", s);
   return 0;
}