#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void cat_io(){
  char c;
  while((c=getchar())!=EOF){
    putchar(c);
  }
}

void cat_fil(char *name){
  
  FILE *fptr;
  fptr = fopen(name,"r");

  char c;
  
  while ((c = fgetc(fptr))!= EOF)   printf ("%c", c);  

  fclose(fptr);
}


int exists(const char *fname){
    
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}




int main(int argc, char* argv[]){

int opt;

  
   if((argc==1)||((argc==2)&&(argv[1][0]=='-'))) cat_io();
   
   
   for(int i=1;argv[1]=="\0";i++){
     
     if(exists(argv[1])==1) cat_fil(argv[1]);
     else printf("%s : no such file or directory.\n", argv[1]);
     
     }
   
  
  
   /*while((opt = getopt(argc,argv, "nbs:") > 0)){

   switch(opt){

      case 'n': 
      */


  
  
  return 0;
}
