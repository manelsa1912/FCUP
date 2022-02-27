#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"mapas.h"
#include"barcos.h"
#include"util.h"

int place_boat(int x,int y, Map* mapa, Boat* barco){ 

   int aux_x1=x-2;
   for(int i=0;i<5;i++){
         int aux_y1=y-2;
         for(int j=0;j<5;j++){
             
             int pos_cell=(aux_x1*mapa->tamanho)+aux_y1;
            
               if(((aux_x1<0)||(aux_x1>=mapa->tamanho)||(aux_y1<0)||(aux_y1>=mapa->tamanho))&&(barco->canonical[i][j]=='1')){
                  
                  return 1;
                  }
            
               if((mapa->tabuleiro[pos_cell].barco_na_cell!=NULL)&&(barco->canonical[i][j]=='1')){   
                  return 2;
               }
            
            aux_y1++;
         }
      aux_x1++;
   }
   
   int c=x-2;
   for(int i=0;i<5;i++){
      
      int a=y-2;
      
         for(int j=0;j<5;j++){
            
            int act_fun=(c*mapa->tamanho)+a;
   
            if(barco->canonical[i][j]=='1'){
               mapa->tabuleiro[act_fun].barco_na_cell=barco;
               mapa->tabuleiro[act_fun].ref_shot='1';
               
            }
         a++;
         }
      c++;
   }  
   mapa->total_shotcount+= barco->shot_count;
return 0;
}



Map*build_automatic_map(int map_size,int n_boats){

   Map* m = new_map(map_size);

   int tipo_barco[5];
   Boat* barcos[n_boats];


   srand((unsigned) time(NULL));
   
   
  
   for(int i=0;i<5;i++) tipo_barco[i]=i+1;

      Boat* barco;
      for(int j=0;j<n_boats;j++){
      
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

   for(int i=0;i<n_boats;i++){
      
      int x = rand()% map_size;
      int y = rand()% map_size;

      int aux=place_boat(x,y,m,barcos[i]);

      while(aux!=0){

         x = rand()% map_size;
         y = rand()% map_size;

         
         while((x<0)||(x>map_size)||(y<0)||(y>map_size)){
            x = rand()% map_size;
            y = rand()% map_size;
         }
            
         aux=place_boat(x,y,m,barcos[i]);

      }

   }


return m;
}