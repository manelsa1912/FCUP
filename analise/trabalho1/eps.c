#include<stdio.h>

double eps(double previo,int count){
    double atual=previo/10;
    printf("%.16lf\n", atual);
    if(atual+1==1) return count;
    else{
         count++;
         return eps(atual,count);
         
    }
}

int main(){
    int s=eps(1,1);
    printf("%d\n",s);
    return 0;
}