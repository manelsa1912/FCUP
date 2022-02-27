#include<stdio.h>
#define C 110

int main(){

int a, b, c;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  
  if((a==b)&&(a==c)) printf("equilatero\n");
  if(((a==b)&&(b!=c))||((a==c)&&(b!=c))||((b==c)&&(b!=a))) printf("isosceles\n");
  if((a!=b)&&(a!=c)&&(b!=c)) printf("escaleno\n");
  
  return 0;
  }
