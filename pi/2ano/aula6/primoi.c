#include<stdio.h>

int primo(int n){
  int s=0;
  for(int i=1;i<=n;i++){

    if((n%i)==0) s ++;
  }
  if(s==2) return 1;
  else return 0;
}


int main(){
  
int a,b;

scanf("%d",&a);
scanf("%d",&b);

  int s=0;
  if(a==b) return 0;
  
  
  if(a<b){
    
    for(int i=a;i<=b;i++){
     if(primo(i)==1) s++;

    }
  }

  if(b<a){

    for(int i=b;i<=a;i++){
     if(primo(i)==1) s++;

    }
  }
printf("\nnumero de primos entre o intevalo: \n %d\n", s);
return 0;

}