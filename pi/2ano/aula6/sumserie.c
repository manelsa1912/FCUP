#include <stdio.h>

double potencia(double n, int a){

double x=1;

  if(a==0) return 1;

    for(int i=0;i<a;i++) x=x*n;

return x;
}

double serie_log(double x, int n){

double sum=0;

for (int i = 1; i <= n; i++) {


sum+=(potencia(-1,i+1)*(potencia(x,i)/i));

}

return sum;

}


int main(){

float n;
int i;

scanf("%f",&n);
scanf("%d",&i);


printf("%f\n",serie_log(n,i));

return 0;
}
