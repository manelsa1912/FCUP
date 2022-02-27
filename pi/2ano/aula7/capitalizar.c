#include<stdio.h>
#include<ctype.h>

void capitalizar(char vec[]){

for(int i=0;vec[i]!='\0';i++){

vec[i]=toupper(vec[i]);

}
}

int main(){

char str[]= "Teste123";

printf("%s\n\n",str);

capitalizar(str);

printf("%s\n",str);
return 0;

}