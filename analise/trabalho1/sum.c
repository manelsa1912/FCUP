#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Esta é a fuçao que permite calcular o fatorial de um numero
double factorial(int n){
    if(n==0) return 1; //se n for zero, entao o fatorial é 1
    else return n*factorial(n-1); // senao multiplica n pelo fatorial de n-1
}

//Esta funçao calcula os expoentes 
double exponte(double b,int n){
   
    if(n==0) return 1;  // se o expoente for 0, retorna 1
    
    double a=b;
    for(int i=0;i<n-1;i++){ // multiplican n vezes a base
        a*=b;
    }
    return a;
}

//Esta funçao calcula a expressao que nos e dada
double sum(int k){
    double s=0;
    double cima;
    double baixo;

    for(int i=0;i<=k;i++){
        cima=exponte(2.0,i)*exponte(factorial(i),2);
        baixo=factorial(2*i+1);
        s+=cima/baixo;
    }
    return 2*s;
}

//funçao que calcula o n de termos precisos para obter um erro absoluto menor que input 
int erroabsoluto(double e){
  double s=10;
  int i=0;
  double cima, baixo;
  while(s>=e){
        cima=exponte(2.0,i)*exponte(factorial(i),2);
        baixo=factorial(2*i+1);
        s=2*(cima/baixo);
        printf("%.16lf\n",s);
        i++;
  }
  return i;
}

//esta funçao calcula o erro absoluto em relaçao ao valor exato de pi |pi - S|
double errpi(double s){
   double r=M_PI-s;
   if(M_PI-s>=0) return r;
   else return r * -1;
}

//funçao principal, recebe os dados e chama as funçoes acima
int main(){
    int err;
    scanf("%d",&err);
    double exp=1;
    for(int i=0;i<err;i++) exp/=10;
    int ntermos = erroabsoluto(exp);
    printf("n de termos = %d\n",ntermos);
    printf("S = %.16lf\n", sum(ntermos-1));
    printf("erro absoluto no calculo de pi = %.16lf\n",errpi(sum(ntermos-1)));

   
    return 0;
}