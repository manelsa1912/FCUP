#include<stdio.h>

int palindromo(char str[]){

int i = 0, j;

for(j=0;str[j]!='\0';j++);

while (i < j) {

  if(str[i]!=str[j]) return 0;
  i ++;
  j --;
}

return 1;


}

int main(){

char str[]= "123321";

printf("%s\n\n",str);

printf("%d\n",palindromo(str));

return 0;

}