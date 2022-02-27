#include<stdio.h>
#include<ctype.h>
#include<string.h>


void esp(char *s){

  while(*s!='\0'){
  if ((isalpha(*s)==0)&&(isdigit(*s)==0)) *s=' ';
  s++;}
 return;
}

int main(int argc, char *argv[]){
  
  for(int i=1; i<argc; i++){
    esp(argv[i]);
    printf("%s", argv[i]);
  }

  return 0;
}
