
typedef struct Player
{  
   QD_NODE* player_quadmap; // mapa do jogador
   Enemy* map_for_enemy;      //mapa do jogador que o adversario tem acesso
}Player;

Player* new_player(int size);