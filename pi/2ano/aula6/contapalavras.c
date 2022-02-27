#include <stdio.h>

int palavra(char n){

if ((n==' ')||(n=='\t')||(n=='\n')) {

  return 0;
 }

  else return 1;
}


int main(){

int p=0, flag=0;
char n;

 while (n!=EOF) {

  n=getchar();

  if(flag==0) {

  if(palavra(n)==1){
  flag=1;
  }
}

  if(flag==1){

    if(palavra(n)==0){
    flag=0;
    p++;
    }
  }

}

printf("%d\n",p);

return 0;

}
