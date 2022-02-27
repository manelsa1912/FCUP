#include <stdio.h>

int mdc(int a, int b)
{
  int s=0;
   while (a != b) {
     
     if(a > b)
         a = a - b;
      
      else{
         b = b - a;
      }
         s++;     
         printf("mdc(%d,%d) = ", a, b);

          
   }

   printf("%d\n",a);
   printf("%d iteracoes\n", s);
   return a; // a, b são iguais
}


int main(){

  int a, b;

scanf("%d",&a);
scanf("%d",&b);

mdc(a,b);

return 0 ;

}

