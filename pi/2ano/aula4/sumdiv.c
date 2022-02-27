#include<stdio.h>

int sumdiv(int n){

 int sum=0;

  for(int i=1;i<n;i++){
    
    if((n%i)==0) sum=sum+i;
    
  }

return sum;

}

int main(){

int n;
scanf("%d",&n);

printf("%d", sumdiv(n));

return 0;

}
