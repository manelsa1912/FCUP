#include <stdio.h>
int main(){
  int i=42, *p;
  p=&i;
  *p=43;
   printf("endereço de i: %d\n",i);
  return 0;
}
