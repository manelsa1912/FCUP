typedef struct Cell
{
char ref_shot; // 0 sem barco, 1 barco nao atingido, 2 barco atingido, 3 barco afundado
struct Boat *barco_na_cell;

}Cell;


typedef struct Map {
   int tamanho;
   int total_shotcount; //   shot_count de todos os barcos
   struct Cell *tabuleiro ;

}Map;


Map* new_map(int n); //Cria um mapa

void print_enemy_map(Map* m); //printa mapa enimigo

void print_own_map(Map* m); //printa próprio mapa

int shot(int x,int y,Map* mapa); // altera ref_shot da coordenada
