typedef struct Boat{
   char canonical[5][5]; // mapa do barco 0 nada 1 barco 2barco com hit 3 barco sem hit
   enum{ 
      CARGUEIRO, //1
      COURACA,   //2
      CRUZEIRO,  //3
      SUBMARINO, //4
      DESTRUIDOR //5
   }ship;
   int rot;            // orientaçao
   int shot_count;     // contador hits sofridos
}Boat;


Boat* build_boat(int b,int rot);

void print_boat(Boat* barco_p1);