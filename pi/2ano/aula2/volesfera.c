#include<stdio.h>
#include<math.h>


int main(){

 int r;
 float v;
 
printf("raio=?"); scanf("%d", &r);
  
   v=(r*r*r*M_PI*4)/3;
   
   printf("Volume: %f\n", v);
 
 return 0;
}
