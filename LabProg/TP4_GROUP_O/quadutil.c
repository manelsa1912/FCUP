#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"barcos.h"
#include"quadtree.h"
#include"enemy.h"
#include"player.h"
#include"quadutil.h"

int insert_point_in_leaf(Point *p, Cell2 *v, QD_NODE *node, Enemy* enemy_map)
{
   if (search_point(p->x, p->y, node) != NULL)
      return 1;
   if (node->largura == 0)
      return 2;

   if (node->type == qdinternal_node)
   {

      if (p->x < node->point_center->x && p->y < node->point_center->y)
         insert_point_in_leaf(p, v, node->node.quadrants[0], enemy_map);

      if (p->x < node->point_center->x && p->y >= node->point_center->y)
         insert_point_in_leaf(p, v, node->node.quadrants[1], enemy_map);

      if (p->x >= node->point_center->x && p->y < node->point_center->y)
         insert_point_in_leaf(p, v, node->node.quadrants[2], enemy_map);

      if (p->x >= node->point_center->x && p->y >= node->point_center->y)
         insert_point_in_leaf(p, v, node->node.quadrants[3], enemy_map);
   }

   else
   {
      if (node->node.leaf.flag_point == 0) // Nao tem ponto no nó
      {
         //printf("a largura do no de centro %f %f = %f\n",node->point_center->x,node->point_center->y,node->largura);
         node->node.leaf.point = p;
         node->node.leaf.value = v;
         node->node.leaf.flag_point = 1;
         enemy_map->total_shot_count++;
         //printf("meti o ponto %.2f %.2f num o nó de centro %.2f %.2f \n\n", node->node.leaf.point->x, node->node.leaf.point->y, node->point_center->x, node->point_center->y);
      }

      else
      {
         //printf("N posso por o %.2f %.2f. Tenho ja um ponto no nó de centro %.2f %.2f\n\n",p->x,p->y,node->point_center->x,node->point_center->y);
         Point *p_temp = node->node.leaf.point;
         Cell2 *v_temp = node->node.leaf.value;
         enemy_map->total_shot_count--;
         //printf("auxiliar do refShot %c\n",node->node.leaf.value->ref_shot);
         //remove_point(node);
         build_leafs(node);

         if (p_temp->x < node->point_center->x && p_temp->y < node->point_center->y)
            insert_point_in_leaf(p_temp, v_temp, node->node.quadrants[0], enemy_map);

         if (p_temp->x < node->point_center->x && p_temp->y >= node->point_center->y)
            insert_point_in_leaf(p_temp, v_temp, node->node.quadrants[1], enemy_map);

         if (p_temp->x >= node->point_center->x && p_temp->y < node->point_center->y)
            insert_point_in_leaf(p_temp, v_temp, node->node.quadrants[2], enemy_map);

         if (p_temp->x >= node->point_center->x && p_temp->y >= node->point_center->y)
            insert_point_in_leaf(p_temp, v_temp, node->node.quadrants[3], enemy_map);

         insert_point_in_leaf(p, v, node, enemy_map);
      }
   }
   return 0;
}

int insert_boat(Boat *b, int x, int y, QD_NODE *root, Enemy *enemy_map)
{
   int x1 = x - 2;
   int y1 = y - 2;

   
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         //printf("o ponto do mapa é %d %d\n",x1,y1);
         //printf("a canonica do barco e %c\n\n",b->canonical[i][j]);
             if (x1 < 0 || x1 >= root->largura)
         {
            if(b->canonical[i][j]=='1'){
            return 3;
            }
         }

         if (y1 < 0 || y1 >= root->largura)
         {
             if(b->canonical[i][j]=='1'){
               return 3;
             }
         }
            
            if (search_point(x1, y1, root) != NULL)
            {
               if(b->canonical[i][j]=='1') return 1;
            }
            
            y1++;
      }
      y1 = y - 2;
      x1++;
   }
   
   x1 = x - 2;
   y1 = y - 2;

   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         if (b->canonical[i][j] == '1')
         {
            Cell2 *cell_b = (Cell2 *)malloc(sizeof(Cell2));
            cell_b->ref_shot = '1';
            cell_b->barco_na_cell = b;
            Point *p = (Point *)malloc(sizeof(Point));
            p->x = x1;
            p->y = y1;
            
            insert_point_in_leaf(p, cell_b, root, enemy_map);
            
         
            int aux = (x1 * enemy_map->size) + y1;
            enemy_map->tabuleiro[aux] = search_point(x1, y1, root)->node.leaf.value->ref_shot;
           
            if (insert_point_in_leaf(p, cell_b, root, enemy_map) == 2){
               return 2;
            }
         }
         y1++;
      }
      y1 = y - 2;
      x1++;
   }
   return 0;
}



int quad_shot(int x, int y, Enemy *enemy_map, QD_NODE *root)
{
   if (x < 0 || x >= enemy_map->size)
   {
      printf("Posiçao fora do mapa\n");
      return 1;
   }

   if (y < 0 || y >= enemy_map->size)
   {
      printf("Posiçao fora do mapa\n");
      return 1;
   }

   int pos_char = (x * enemy_map->size) + y;

   if (enemy_map->tabuleiro[pos_char] == '2' || enemy_map->tabuleiro[pos_char] == '4')
   {
      
      return 2;
   }

   QD_NODE *temp = search_point(x, y, root);
   //printf(" o ref e %c\n",temp->node.leaf.value->ref_shot);

   if (temp == NULL)
   {  
      printf("Falhaste!\n");
      enemy_map->tabuleiro[pos_char] = '4';
   }

   else
   {

      if (temp->node.leaf.value->ref_shot == '1')
      {

         search_point(x, y, root)->node.leaf.value->barco_na_cell->shot_count--;
         enemy_map->total_shot_count--;
         search_point(x, y, root)->node.leaf.value->ref_shot = '2';

         if (temp->node.leaf.value->barco_na_cell->shot_count == 0){
            printf("Afundaste um barco!\n");
            Boat* barco_temp=search_point(x,y,root)->node.leaf.value->barco_na_cell;
            enemy_map->tabuleiro[pos_char] = '2';
   
            for(int a=(x-4);a<(x+4);a++){
               
               for(int b=(y-4);b<(y+4);b++){
                  
                  int temp_aux=(a*enemy_map->size)+b;
                  if(enemy_map->tabuleiro[temp_aux]=='2'||enemy_map->tabuleiro[temp_aux]=='1'){
                     if(search_point(a,b,root)->node.leaf.value->barco_na_cell==barco_temp){
                        
                        enemy_map->tabuleiro[temp_aux] = '3';
                     }
                  }
               }
            }
         }
         else{
            printf("Acertaste num barco\n");
            enemy_map->tabuleiro[pos_char] = '2';
         }
      }
   }
   return 0;
}



void print_my_quadmap(int size, QD_NODE *root, Enemy *enemymap)
{

   printf("\n");
   printf("\033[1;34m");
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
   int p, n = 0; //PARA AS COLUNAS
   printf("   ");

   for (p = 0; p < size; p++)
   {
      if (p < 10)
         printf("0%d ", p);
      else
         printf("%d ", p);
   }
   printf("\n");

   for (int j = 0; j < size; j++)
   {

      // PARA LINHAS                                  IMPORTANTE DOIS ESPACOS DEPOIS DO CARATER
      if (n < 10)
         printf("0%d  ", n);
      else
         printf("%d  ", n);
      n++;

      for (int k = 0; k < size; k++)
      {
         if (search_point(j, k, root) == NULL)
         {  

            int aux=(j*size)+k;
            //printf("vazio no tabuleiro[%d] ",i);
            if (enemymap->tabuleiro[aux] == '4')
            {
               printf("\033[0m");
               printf("3  ");
            }
            else
            {
               printf("\033[1;34m");
               printf("0  ");
               printf("\033[0m");
            }
         }

         else
         {
            switch (search_point(j, k, root)->node.leaf.value->ref_shot)
            {

            case '1':
               printf("\033[0;32m");
               //printf("tabuleiro[%d] tem barco inteiro");
               printf("%c  ", search_point(j, k, root)->node.leaf.value->ref_shot);
               printf("\033[0m");
               break;

            case '2':

               if (search_point(j, k, root)->node.leaf.value->barco_na_cell->shot_count == 0)
                 // printf("tabuleiro[%d] tem barco afundado");
                  printf("\033[1;31m");
               else
                  printf("\033[1;33m");
               //printf("tabuleiro[%d] tem barco destruido");
               printf("%c  ", search_point(j, k, root)->node.leaf.value->ref_shot);
               printf("\033[0m");

               break;
            }
         }

      }
      printf("\n");
   }
}




Player*build_automatic_quadmap(int map_size,int n_boats){

   
   Player* m = new_player(map_size);
   QD_NODE* auxquad=build_new_node(map_size);
   Enemy* auxenemy=bulid_enemy(map_size);
   
   int tipo_barco[5];
   Boat* barcos[n_boats];

   srand((unsigned) time(NULL));
   
   
  
   for(int a=0;a<5;a++){ tipo_barco[a]=a+1;}

      
      for(int j=0;j<n_boats;j++){
         Boat* barco;
         
         int rot = rand()% 5 + 1;
         switch (rot)
         {
         case 1:
            barco=build_boat(tipo_barco[j], 0);
            break;
         
         case 2:
            barco=build_boat(tipo_barco[j], 90);
            break;
         case 3:
            barco=build_boat(tipo_barco[j], 180);
            break;
         case 4:
            barco=build_boat(tipo_barco[j], 270);
            break;
         
         case 5:
            barco=build_boat(tipo_barco[j], 360);
            break;
         
         default:
            break;
         }
         barcos[j] = barco;
         
      }

      
   for(int b=0;b<n_boats;b++){
      
      
      int x = rand()% map_size;
      int y = rand()% map_size;
      

      int aux=insert_boat(barcos[b],x,y,auxquad,auxenemy);
      
      while(aux!=0){

         x = rand()% map_size;
         y = rand()% map_size;

         
         while((x<0)||(x>map_size)||(y<0)||(y>map_size)){
            x = rand()% map_size;
            y = rand()% map_size;
         }
            
         aux=insert_boat(barcos[b],x,y,auxquad,auxenemy);

      }
      
      m->player_quadmap=auxquad;
      m->map_for_enemy=auxenemy;
      insert_boat(barcos[b],x,y,m->player_quadmap,m->map_for_enemy);

   }

return m;
}
