#include<stdio.h>
#include<math.h>

//funçoes usadas no 2 exercicio

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

//expressao an
double euler_a(double n){
    return exponte((1.0+(1.0/n)),n);
}

//expressao bn
double euler_b(double n){
    double s=0;
    for(int k=0;k<=n;k++){
        s+=1.0/factorial(k);
    }
    return s;
}

//funçao principal, recebe os dados e chama as funçoes acima
int main(){
    double i;
    scanf("%lf",&i);
        // double s=1.0/10.0;
   
    double s=euler_a(i);
    double s=euler_b(i);
    printf("%.16lf\n",s);
    return 0;
}