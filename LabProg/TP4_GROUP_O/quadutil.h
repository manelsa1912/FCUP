
int insert_point_in_leaf(Point *p, Cell2 *v, QD_NODE *node, Enemy *enemy_map);

int insert_boat(Boat *b, int x, int y, QD_NODE *root, Enemy *enemy_map);

int quad_shot(int x, int y, Enemy *enemy_map, QD_NODE *root);

void print_my_quadmap(int size, QD_NODE *root, Enemy *enemymap);

Player*build_automatic_quadmap(int map_size,int n_boats);