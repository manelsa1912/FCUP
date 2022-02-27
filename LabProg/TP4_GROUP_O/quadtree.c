#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "quadtree.h"


QD_NODE *build_new_node(float mapsize)
{
   QD_NODE *node = (QD_NODE *)malloc(sizeof(QD_NODE));
   node->type = qdleaf;

   //node->node.leaf.value = (Cell )malloc(sizeof(Cell));

   node->node.leaf.point = (Point *)malloc(sizeof(Point));
   node->node.leaf.point->x = -1;
   node->node.leaf.point->y = -1;

   node->node.leaf.value = (Cell2 *)malloc(sizeof(Cell2));

   node->node.leaf.flag_point = 0;
   node->largura = mapsize;

   node->point_center = (Point *)malloc(sizeof(Point));
   node->point_center->x = mapsize / 2;
   node->point_center->y = mapsize / 2;
   return node;
}


void build_leafs(QD_NODE *int_node)
{
   int_node->type = qdinternal_node;

   float c = int_node->largura / 2;
   for (int i = 0; i < 4; i++)
   {
      int_node->node.quadrants[i] = build_new_node(c);
      int_node->node.quadrants[i]->largura = c;
   
   }

   int_node->node.quadrants[0]->point_center->x = int_node->point_center->x - (c / 2);
   int_node->node.quadrants[0]->point_center->y = int_node->point_center->y - (c / 2);

   int_node->node.quadrants[1]->point_center->x = int_node->point_center->x - (c / 2);
   int_node->node.quadrants[1]->point_center->y = int_node->point_center->y + (c / 2);

   int_node->node.quadrants[2]->point_center->x = int_node->point_center->x + (c / 2);
   int_node->node.quadrants[2]->point_center->y = int_node->point_center->y - (c / 2);

   int_node->node.quadrants[3]->point_center->x = int_node->point_center->x + (c / 2);
   int_node->node.quadrants[3]->point_center->y = int_node->point_center->y + (c / 2);
}

QD_NODE *search_point(int x, int y, QD_NODE *n)
{

   if (n->type == qdinternal_node)
   {
      //printf("o no de centro %f %f nao é folha\n",n->point_center->x,n->point_center->y);
      //printf("ponto central do nó em que estou: %f %f\n",n->point_center->x,n->point_center->y);
      if (x < n->point_center->x && y < n->point_center->y)
      {
         //printf("fui para o quad[0]\n");
         return search_point(x, y, n->node.quadrants[0]);
      }

      if (x < n->point_center->x && y >= n->point_center->y)
      {
         // printf("fui para o quad[1]\n");
         return search_point(x, y, n->node.quadrants[1]);
      }
      if (x >= n->point_center->x && y < n->point_center->y)
      {
         // printf("fui para o quad[2]\n");
         return search_point(x, y, n->node.quadrants[2]);
      }
      if (x >= n->point_center->x && y >= n->point_center->y)
      {
         //printf("fui para o quad[3]\n");
         return search_point(x, y, n->node.quadrants[3]);
      }
   }
   else
   {
      //printf("o no de centro %f %f que tem o ponto %f %f e uma folha\n",n->point_center->x,n->point_center->y,n->node.leaf.point->x,n->node.leaf.point->y);
      if (n->largura == 0)
         return NULL;
      if (n->node.leaf.point->x == -1 && n->node.leaf.point->y == -1)
         return NULL;
      //printf("este no de centro %f %f tem o ponto: %2.f %2.f\n",n->point_center->x,n->point_center->y, n->node.leaf.point->x, n->node.leaf.point->y);
      if ((x == n->node.leaf.point->x) && (y == n->node.leaf.point->y))
      {
         return n;
      }
   }
   return 0;
}




