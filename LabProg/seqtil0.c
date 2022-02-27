#include<stdio.h>

void seq(){

int n,ultimo,penultimo;

scanf("%d",&penultimo);
scanf("%d",&ultimo);

scanf("%d",&n);

while(n!=0){ 
   
   ultimo=penultimo;
   penultimo=n;

   scanf("%d",&n);
  }
   printf("%d,%d\n",penultimo,ultimo);

}


int main(){

seq();

return 0;
}