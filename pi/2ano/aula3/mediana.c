#include<stdio.h>


int main(){

int a, b, c,mediana;

  scanf("%d", &a);
  
  scanf("%d", &b);
  
  scanf("%d", &c);
  
  if(((b>=a)&&(b<=c))||((b>=c)&&(b<=a))) mediana=b;
  if(((a<=b)&&(a>=c))||((a<=c)&&(a>=b))) mediana=a;
  if(((c>=a)&&(c<=b))||((c>=b)&&(c<=a))) mediana=c;
 

  printf("mediana: %d\n",mediana);
  
  return 0;
  }
