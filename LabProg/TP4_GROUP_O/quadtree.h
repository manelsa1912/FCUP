typedef struct Cell2
{
   char ref_shot; // 0 sem barco, 1 barco nao atingido, 2 barco atingido
   struct Boat *barco_na_cell; //apontador para o barco

} Cell2;

typedef struct Point //coordenadas
{
   float x;
   float y;
} Point;

typedef enum
{
   qdinternal_node,
   qdleaf
} node_type;

typedef struct QD_Node_
{
   node_type type; // defines the type of node (internal node or leaf)
   float largura;
   Point *point_center;   //ponto central de um no

   union {

      struct QD_Node_ *quadrants[4]; // internal node

      struct
      {
         int flag_point;  // verifica se a folha ja tem um ponto la

         struct Cell2 *value; // VALUE --  board cell ou pointer para board cell?

         struct Point *point; // coords of the board cell

      } leaf; //  almost a board cell together with its coordinates

   } node;

} QD_NODE;


QD_NODE* build_new_node(float mapsize);

void build_leafs(QD_NODE *int_node);

QD_NODE* search_point(int x, int y, QD_NODE *n);

