typedef struct Enemy
{
   int size;
   char *tabuleiro;  //matriz do mapa
   int total_shot_count; // contador que determina o fim do jogo
} Enemy;

Enemy *bulid_enemy(int mapsize);

void print_enemy_quadmap(Enemy* m);