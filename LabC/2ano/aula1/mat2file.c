#include<stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){

FILE * f;
f = fopen(argv[3],"w");

int i,j;
i=atoi(argv[1]);
j=atoi(argv[2]);

fprintf(f,"%d %d ",i,j);

int mat[i][j];

for(int a=0;a<i;a++){
 
 for(int b=0;b<j;b++){
 
 printf("Valor de mat[%d][%d]? \n", a, b);  
 scanf("%d", &mat[a][b]); 
 fprintf(f,"%d ",mat[a][b]);
  
  }
}

fclose(f);
printf("\nO ficheiro %s foi criado.\n",argv[3]);
return 0;
  
}