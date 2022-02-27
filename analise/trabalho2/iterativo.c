#include <math.h>
#include <stdio.h>

//funçao F(x)
double func(double x){return sin((double)pow(x, 2) + 1.1 - exp(-x));}

//Primeira derivda F'(x)
double funcLinha(double x){return 2 * x * cos((double)pow(x, 2)) + exp(-x);}

//Segunda derivada F''(x)
double funcLinhaLinha(double x){return -4*pow(x,2)*sin(pow(x,2))+2*cos(pow(x,2))-exp(-x);}

//Esta funçao e calculada isolando um x de F(x). tem o objetivo de determinar xn+1
double funcInteracao(double x){return -log(sin(pow(x,2))+1.1);}

//funçao que calcula a raiz atraves do metodo das bissessoes sucessivas
double bissessoes(double erro, double a, double b){
    double m = (a+b)/2;
    double n_erro=b-a;
    if(n_erro<0) erro*=-1;

    if(func(m)==0 || erro < 5 * (double)pow(10, -9)) return m;
    else{
        
        if(func(a)*func(m)<0) return bissessoes(n_erro, a, m);
        else return bissessoes(n_erro, m, b);
    }
}

//funçao que calcula a raiz atraves do metodo das ietraçoes simples
double i_simples(double raiz, double erro, double a, double b){
    double n_raiz, n_error, l;
    if (erro < 5 * (double)pow(10, -9)) return raiz;
    else{
        n_raiz = funcInteracao(raiz);
        l = fmax(funcLinha(a), funcLinha(b));
        if(l<0)l*=-1;
         n_error = l * erro;
         
        return i_simples(n_raiz, n_error, a, b);
       }
}

//funçao que calcula a raiz atraves do metodo de newton
double newton(double raiz, double erro, double a, double b){
    if (erro < 5 * (double)pow(10, -9)) return raiz;
    else{
    
    double term1=fmax(funcLinha(a),funcLinha(b));
    if(term1<0) term1*=-1;

    double term2=fmin(funcLinhaLinha(a),funcLinhaLinha(b));
    if(term2<0) term1*=-1;
    
    double m=0.5*(term1/term2);

    double n_erro=pow(erro,2)*m;
    double n_raiz=raiz-(func(raiz)/funcLinha(raiz));
  
    return newton(n_raiz, n_erro, a, b);
    }
}


int main(){
    
    double resposta3 = newton(-0.15, 5 * (double)pow(10, -1), -0.2, -0.1);
    double resposta2 = i_simples(-0.15, 5 * (double)pow(10, -1), -0.2, -0.1);
    double resposta = bissessoes(5 * (double)pow(10, -1), -0.2, -0.1);
    
    printf("bissessoes sussecivas: %.16lf\n", resposta);
    printf("iteracao simples: %.16lf\n", resposta2);
    printf("metodo de newton: %.16lf\n\n", resposta3);
    return 0;
}
