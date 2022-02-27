#include<stdio.h>

/*int shift(int str[],int n){







}*/



void lastdif(){

   int n,k,v,nd=0;
   int vec[n],str[k];

   for(int i=0;i<n;i++){

      scanf("%d",&v);
      vec[i]=v;
   
      for(int j=i;j!=0;j--){

         if(vec[j]!=vec[i]){
         
            if(nd!=k){

               str[nd]=vec[i];
               nd++;
            } 
//            else shift(str, vec[i]);     
         }
      }
   }

   printf("%s",str);
}


int main(){

lastdif();

return 0;
}