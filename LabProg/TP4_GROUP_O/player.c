#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "quadtree.h"
#include "enemy.h"
#include "player.h"


Player* new_player(int size){
   
   Player* player = (Player *) malloc(sizeof(Player));
   player->player_quadmap = (QD_NODE*) malloc(sizeof(QD_NODE));
   player->map_for_enemy = (Enemy*) malloc(sizeof(Enemy));
   player->map_for_enemy->size=size;

   return player;
}