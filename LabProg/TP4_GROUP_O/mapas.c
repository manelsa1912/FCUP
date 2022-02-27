#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"mapas.h"
#include"barcos.h"

Map* new_map(int n){

   Map* m = (Map*) malloc(sizeof(Map));
   m->tamanho = n;
   m->tabuleiro = (Cell*) malloc (n*n* sizeof(Cell));
   m->total_shotcount=0;
   for(int i=0,p=1;i<n*n;i++,p++){
     m->tabuleiro[i].ref_shot = '0';
     m->tabuleiro[i].barco_na_cell = NULL;
   }

return m;
}

void print_enemy_map(Map* m){               
   
   printf("Este e o mapa enimigo:\n\n");
   printf("\033[1;31m");
   printf("0-Espaço por disparar\n");

   printf("\033[1;34m");
   printf("2-Espaço Vazio\n");

   printf("\033[1;32m");
   printf("1-Barco inimigo\n");
   printf("\033[0m");

   printf("1-Barco enimigo afundado\n\n");

   int p,n=0;      //PARA AS COLUNAS
   printf("   ");

   for(p=0;p<m->tamanho;p++){
      if(p<10) printf("0%d ",p);
      else printf("%d ",p); 
   }
   printf("\n");
   
   for(int j=1,i=0;j <= m->tamanho; j++){
      
      // PARA LINHAS                                IMPORTANTE DOIS ESPACOS DEPOIS DO CARATER
      if(n<10) printf("0%d  ",n);
      else printf("%d  ",n); 
      n++;
      
      
      for(int k=0; k < m->tamanho; k++){
         
         switch (m->tabuleiro[i].ref_shot)
         {
         case '0':
            printf("\033[1;31m");
            printf("%c  ",'0');
            printf("\033[0m");  
            break;

         
         case '1':
            printf("\033[1;31m");
            printf("%c  ",'0');
            printf("\033[0m");  
            break;
         

         case '2':
            if(m->tabuleiro[i].barco_na_cell->shot_count!=0){
            printf("\033[1;32m");
            printf("%c  ",'1');
            printf("\033[0m");  
            }
            else printf("%c  ",'1');
            
            break; 
         
         
         case '3':
            printf("\033[1;34m");
            printf("%c  ",'2');
            printf("\033[0m");  
            break; 
         }
         
         i++;
      }
   printf("\n");
   }

}

void print_own_map(Map* m){               

   printf("\n");printf("\033[1;34m");
   printf("Este e o teu mapa:\n\n");
   printf("0-Espaço Vazio\n");

   printf("\033[0m");
   printf("3-Espaço Vazio atingido\n");

   printf("\033[1;32m");
   printf("1-Barco nao atingido\n");

   printf("\033[1;33m");
   printf("2-Barco atingido\n");

   printf("\033[1;31m");
   printf("2-Barco afundado\n");
   printf("\033[0m");
   int p,n=0;      //PARA AS COLUNAS
   printf("   ");

   for(p=0;p<m->tamanho;p++){
      if(p<10) printf("0%d ",p);
      else printf("%d ",p); 
   }
   printf("\n");
   
   
   for(int j=1,i=0;j <= m->tamanho; j++){
      
      // PARA LINHAS                                  IMPORTANTE DOIS ESPACOS DEPOIS DO CARATER
      if(n<10) printf("0%d  ",n);
      else printf("%d  ",n); 
      n++;
      
      
      for(int k=0; k < m->tamanho; k++){
         
         switch (m->tabuleiro[i].ref_shot)
         {
         case '0':
            printf("\033[1;34m");
            printf("%c  ",m->tabuleiro[i].ref_shot);
            printf("\033[0m");  
            break;

         
         case '1':
            printf("\033[0;32m");
            printf("%c  ",m->tabuleiro[i].ref_shot);
            printf("\033[0m");  
            break;
         

         case '2':
            
            if(m->tabuleiro[i].barco_na_cell->shot_count==0)
            printf("\033[1;31m");
            else
            printf("\033[1;33m");
            printf("%c  ",m->tabuleiro[i].ref_shot);
            printf("\033[0m");
              
            break; 


         case '3':
            printf("\033[0m");
            printf("%c  ",m->tabuleiro[i].ref_shot); 
            break; 

         }
         i++;
      }
   printf("\n");
   }
   
}

int shot(int x,int y,Map* mapa){

int pos_cell=(x*mapa->tamanho)+y;

   switch (mapa->tabuleiro[pos_cell].ref_shot)
   {
      case '0':
      mapa->tabuleiro[pos_cell].ref_shot='3';
      return 3;
      break;

      case '1':
         mapa->tabuleiro[pos_cell].ref_shot='2';
         mapa->tabuleiro[pos_cell].barco_na_cell->shot_count --;
         mapa->total_shotcount--;
         if(mapa->tabuleiro[pos_cell].barco_na_cell->shot_count==0) return 5;
         return 1;
         break;

      case '2':
         return 2;
         break;

      case '3':
         return 2;
         break;

      default:
         break;
   }
   return 0;
}