#include<stdio.h>


int main(){

 float l,w,h,v;

printf("L=?"); scanf("%f", &l);
   printf("W=?"); scanf("%f", &w);
   printf("H=?"); scanf("%f", &h);
   v = l*w*h; // cálculo do volume

   printf("LxWxH: %f*%f*%f (cm)\n", l,w,h);
   printf("Volume: %f (cm^3)\n", v);
 return 0;
}
