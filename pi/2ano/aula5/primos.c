#include <stdio.h>

int primo(int n)
{
   int d;
   if(n <= 1) return 0;
   for (d = 2; d*d <= n; d++) {
     if (n%d == 0)   // d divide n
       return 0;
    }
   return 1;
}


int main() {

int v;

scanf("%d", &v);

for(int i=1;i<v;i++){

  if (primo(i)==1) {
    printf("%d\n",i);
}

}
  return 0;
}
