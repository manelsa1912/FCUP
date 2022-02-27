#include<stdio.h>
#include<ctype.h>
#include<string.h>

void normalizar(char str[]){

  int i, j;

  for(i=0,j=0;str[i]!='\0';i++){

    if(isalpha(str[i])){

      str[j]=tolower(str[i]);
      j++;
    }
  }
  str[j]='\0';
}

int main(){
