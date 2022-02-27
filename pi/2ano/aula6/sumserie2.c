#include<stdio.h>

double potencia (double base, int expoente){
  double x=1;
  if (expoente==0)
  return 1;
  for (int i=0; i<expoente; i++) {
    x=x*base;
  }
  return x;
}

double batatas (double base, int expoente)
{ double soma=0;
  for (int a=1; a<=expoente; a++ ){
    soma=soma + (potencia(-1,a+1)*(potencia (base, a))/a);
}
return soma;
}
int main (void)
{

  int i;
  float x;
  scanf ("%f", &x);
  scanf("%d", &i);

printf("A soma e: %f", batatas (x,i));
  return 0;
}