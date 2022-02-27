#include<stdio.h>


int main(){

int a, b, c,max,min,amp;

  scanf("%d", &a);
  max=a;
  scanf("%d", &b);
  min=b;
  scanf("%d", &c);
  
  if((b>=a)&&(b>=c)) max=b;
  if((a<=b)&&(a<=c)) min=a;
  if((c>=a)&&(c>=b)) max=c;
  if((c<=a)&&(c<=b)) min=c;
  
  amp=max-min;
  
  printf("max: %d\n",max);
  printf("min: %d\n",min);
  printf("amp: %d\n",amp);
  
  
  return 0;
  }
