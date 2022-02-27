#include<stdio.h>

int main(){

int a, b, c, max;

 scanf("%d", &a);
 max = a;
 scanf("%d", &b);
 scanf("%d", &c);
 
  if(b>=a&&b>=c) max = b;
  if(c>=a&&c>=b) max = c;
  
  printf("%d\n", max);
  
  return 0;
}
