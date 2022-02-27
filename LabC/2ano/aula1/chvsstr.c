#include <stdio.h>
#define SIZE 10

void show_vector(char*a, int n);

int main() {
  
  char v[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  show_vector(v, SIZE);
  
  return 0;
  
}

void show_vector(char*a, int n) {
  
  printf("\n");
  int i;
  a=&i;
  for (i=0; i<n; i++) { 
    printf("%p", *a);


  }
  printf("\n\n"); 
}
