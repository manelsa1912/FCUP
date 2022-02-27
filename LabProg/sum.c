#include<stdio.h>

int sum(){
   
   int n,v,s=0;
   
   scanf("%d",&n);

   for(int i=0;i<n;i++){

      scanf("%d",&v);
      s+=v;
   }

   return s;
}

int main(){
 
 printf("%d",sum());

 return 0 ;
}