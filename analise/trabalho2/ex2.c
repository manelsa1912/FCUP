#include<stdio.h>
#include<math.h>

//funça F(x)
double func(double x){return pow(x,3)-pow(x,2)+8*x-8;}

//Derivada fe F(x)
double funcLinha(double x){ return 3*pow(x,2)-2*x+8; }

//as quatro funçoes iterativas do enunciado
double func_a(double x){return -pow(x,3)+pow(x,2)-7*x+8;} 

double func_b(double x){return (8-pow(x,3))/(8-x);} 

double func_c(double x){return -1*(1.0/10.0)*pow(x,3) + (1.0/10.0)*pow(x,2) + (1.0/5.0)*x +(4.0/5.0);} 

double func_d(double x){return (2*pow(x,3)-pow(x,2)+8)/(3*pow(x,2)-2*x+8);} 

//Funçao que calcula as iteraçoes
double i_simples(double raiz, double erro, double a, double b, int lim, char tipo){
   
    double n_raiz, n_error;
    //verifica se temos o erro necessario
    if ((erro < 5 * (double)pow(10, -12))||lim>25) return raiz;
    
    //seleciona a funçao iterativa escolhida no input
    else{   
        switch (tipo){
        case 'a':
            n_raiz = func_a(raiz);
            break;
        
        case 'b':
            n_raiz = func_b(raiz);
            break;
        
        case 'c':
            n_raiz = func_c(raiz);
            break;

        default:
            n_raiz = func_d(raiz);
            break;
        }
        
        //calculo da raiz e o erro
        n_error = n_raiz-raiz;
        if(n_error<0) n_error*=-1;
        n_error=fabs(n_error);
        printf("erro: %.16lf\n",n_error);
        printf("raiz: %.16lf\n\n",n_raiz);
        lim++;
        return i_simples(n_raiz, n_error, a, b,lim,tipo);
       
    }
}

int main(){
     //escolher a funçao iterativa
     char c;
     scanf("%c",&c);
     double resposta2 = i_simples(0.5, 5 * (double)pow(10, -1),0.5,func(0.5),1,c);
     printf("iteracao simples a) : %.20lf\n", resposta2);
    return 0;
}