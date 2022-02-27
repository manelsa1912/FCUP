#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b){ 
    if (a == 0) 
        return b; 
    return mdc(b % a, a); 
} 

typedef struct frac{
  int sinal;
  int numerador;
  int denominador;
  int erro;
} FRAC;

int sin_al(int num,int den){
 if(((num>=0)&&(den>=0))||((num<0)&&(den<0))) return 1;
 else return -1;
}

int error(int den){
   if(den==0) return 1;
   else return 0;
}

FRAC build_frac(int n, int d){

FRAC f;

   f.numerador = n; 
   f.denominador = d;
   f.sinal = sin_al(n, d);
   f.erro = error(d);
return f;
}



void printfrac(FRAC f){

printf("sinal: %d\n", f.sinal);
printf("numerador: %d\n", f.numerador);
printf("denominador: %d\n", f.denominador);
printf("erro: %d\n", f.erro);
}


FRAC simp(FRAC f){

FRAC g = f;

   int a = f.numerador;
   int b = f.denominador;

g.numerador = a/mdc(a,b);
g.denominador = b/mdc(a,b);

return g;

}

FRAC soma(FRAC f,FRAC g){
FRAC h;
h.numerador = f.numerador + g.numerador;
h.denominador = f.denominador + g.denominador;
h.sinal= sin_al(h.numerador, h.denominador);
h.erro = error(h.denominador);

return h;
}

FRAC sub(FRAC f,FRAC g){
FRAC h;
h.numerador = f.numerador - g.numerador;
h.denominador = f.denominador - g.denominador;
h.sinal= sin_al(h.numerador, h.denominador);
h.erro = error(h.denominador);

return h;
}

FRAC mult(FRAC f,FRAC g){
FRAC h;
h.numerador = f.numerador * g.numerador;
h.denominador = f.denominador * g.denominador;
h.sinal= sin_al(h.numerador, h.denominador);
h.erro = error(h.denominador);

return h;
}

FRAC divide(FRAC f,FRAC g){
FRAC h;
h.numerador = f.numerador / g.numerador;
h.denominador = f.denominador / g.denominador;
h.sinal= sin_al(h.numerador, h.denominador);
h.erro = error(h.denominador);

return h;
}


int main(){
   int a,b;
   
   scanf("%d", &a);
   scanf("%d", &b);
   
   FRAC f = build_frac(a,b);
   
   printfrac(simp(f));

return 0;
}
