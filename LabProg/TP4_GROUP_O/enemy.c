#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "enemy.h"

Enemy *bulid_enemy(int mapsize)
{
   Enemy *new_enemy = (Enemy *)malloc(sizeof(Enemy));
   new_enemy->size = mapsize;
   new_enemy->tabuleiro = (char *)malloc(mapsize * mapsize * sizeof(char));
   for (int i = 0; i < new_enemy->size; i++)
   {
      for (int j = 0; j < new_enemy->size; j++)
      {
         int aux = (i * new_enemy->size) + j;
         new_enemy->tabuleiro[aux] = '0';
      }
   }
   new_enemy->total_shot_count = 0;
   return new_enemy;
}

void print_enemy_quadmap(Enemy* m){               
   
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

   for(p=0;p<m->size;p++){
      if(p<10) printf("0%d ",p);
      else printf("%d ",p); 
   }
   printf("\n");
   
   for(int j=1,i=0;j <= m->size; j++){
      
      // PARA LINHAS                                IMPORTANTE DOIS ESPACOS DEPOIS DO CARATER
      if(n<10) printf("0%d  ",n);
      else printf("%d  ",n); 
      n++;
      
      
      for(int k=0; k < m->size; k++){
         
         switch (m->tabuleiro[i])
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
           
            printf("\033[1;32m");
            printf("%c  ",'1');
            printf("\033[0m");  
           
            
            break; 
         
         case '3':
            
            printf("%c  ",'1');
            
            break; 
         
         case '4':
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