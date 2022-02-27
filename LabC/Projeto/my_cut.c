#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

void cut_io(){

  char c;
  int a=0;

  while(c!=EOF){

    a++;
    if(c=='\n') a=0;



    putchar(c);

  }
}

void cut_file(argv[]){

  char c;
  int a=0;


  fopen(argv)
  putchar(c);

  }


int main(int argc, char* argv[]){

  int opt;

  printf("argc=%d/n",argc);
  
    while((opt = getopt(argc,argv, "dbf:") > 0)){

   switch(opt){

      case 'b':
      

  




  return 0;
}


