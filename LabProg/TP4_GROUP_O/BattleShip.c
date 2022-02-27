#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"mapas.h"
#include"barcos.h"
#include"util.h"



//-----------------------------------------------------------------------------------------------------------------------------


Map*build_own_map(int map_size,int n_barcos){

   Map* nm = new_map(map_size);
   int aux_tipo=5;  // Auxiliar de verificaçao de todos os barcos colocados
   
   while(aux_tipo!=0){ 
      
     Map* m = new_map(map_size);
     
     system("clear"); //IMPORTANTE  
      
      int aux_barcos=n_barcos; //Contador de Barcos restantes a colocar
      int tipo_barco[5]; // Verificador de cada tipo de barco 0 existe 1 nao existe
      for(int i=0;i<5;i++) tipo_barco[i]=1;

     
   

      for(int i=0;i<n_barcos;i++){

         printf("Faltam colocar %d barcos",aux_barcos );
         print_own_map(m);

         printf("\nSeleciona o numero do tipo de barco para colocar no mapa\n");
         printf("1-Cargueiro\n");
         printf("2-Couraça\n");
         printf("3-Cruzeiro\n");
         printf("4-Submarino\n");
         printf("5-Destruidor\n");
         
         int num_boat;
         scanf("%d",&num_boat);
         
         while((num_boat!=1)&&(num_boat!=2)&&(num_boat!=3)&&(num_boat!=4)&&(num_boat!=5)){
            printf("Nao e um barco.\n");
            scanf("%d",&num_boat);
         }


         printf("selecione uma rotacao(de 90 em 90 graus):\n");

         int rot;
         scanf("%d",&rot);

         while((rot!=0)&&(rot!=90)&&(rot!=180)&&(rot!=270)&&(rot!=360)){
            
            if((rot!=0)&&(rot!=90)&&(rot!=180)&&(rot!=270)&&(rot!=360)){
               printf("nao e uma opcao.\n");
               scanf("%d",&rot);
            }
         }

         system("clear"); //IMPORTANTE 


         Boat* barco_p1 = build_boat(num_boat, rot);


         print_boat(barco_p1);
         printf("\nSeleciona a coordenada central do barco(linha e coluna):\n");
         print_own_map(m);

         int x,y;
         scanf("%d",&x);
         scanf("%d",&y);
         
         while((x<0)||(x>map_size)||(y<0)||(y>map_size)){
            printf("nao e possivel\n");
            scanf("%d",&x);
            scanf("%d",&y);
         }
         
         system("clear"); //IMPORTANTE

         int aux=place_boat(x,y,m,barco_p1);
         while(aux!=0){
            if(aux==1){
               
               print_boat(barco_p1);
               printf("\nPosicao fora do mapa.Insere outra coordenada\n");
               print_own_map(m);

               scanf("%d",&x);
               scanf("%d",&y);
               
               while((x<0)||(x>map_size)||(y<0)||(y>map_size)){
                  printf("nao e possivel\n");
                  scanf("%d",&x);
                  scanf("%d",&y);
                  
               }
               aux=place_boat(x,y,m,barco_p1);
            }
         
            if(aux==2){
               print_boat(barco_p1);
               printf("\nJa existe um barco aqui.Insere outra coordenada\n");
               print_own_map(m);
               
               scanf("%d",&x);
               scanf("%d",&y);
               
               while((x<0)||(x>map_size)||(y<0)||(y>map_size)){
                  printf("nao e possivel\n");
                  scanf("%d",&x);
                  scanf("%d",&y);
               
               }
               aux=place_boat(x,y,m,barco_p1);
            }
         }  
         tipo_barco[num_boat-1]=0;
         aux_barcos--;
      }
      
      aux_tipo=0;
      for(int l=0;l<5;l++) aux_tipo+=tipo_barco[l];
      if(aux_tipo!=0){ 
         printf("Nao existe pelo menos um barco de cada tipo.\nPor favor reconstrua o mapa.\n");
         printf("'n' para criar novo mapa\n");
         char conf=' ';
         while (conf!='n') scanf("%c",&conf);
      }

      nm=m;
   }
   system("clear");
   return nm;
}



void turn(Map* own_map, Map* enemy_map){
  
   char r = ' ';
   printf("\nAntes de atacar,Ver proprio mapa?\n'y' ou 'n'\n");
  
   
   while ((r!='y')&&(r!='n')){
      scanf("%c",&r);
      char r1 = r;
      if((r1!='y')&&(r1!='n')){
         printf("Nao e uma opcao.\n");
         scanf("%c",&r);
      }  
      else{
         r=r1;
      }
   }

   if(r=='y'){ print_own_map(own_map);
   r =' ';
   printf("Continuar 'y'\n");

   while(r!='y') scanf("%c",&r);
   }

   system("clear");

   print_enemy_map(enemy_map);
   printf("Selecione uma coordenada para disparar\n");
   int shot_x,shot_y;
   scanf("%d",&shot_x);
   scanf("%d",&shot_y);

   int aux_shot=shot(shot_x,shot_y,enemy_map);
  
   while (aux_shot==2){
          
         printf("Essa coordenada ja foi atingida\n");
         scanf("%d",&shot_x);
         scanf("%d",&shot_y);

          aux_shot=shot(shot_x,shot_y,enemy_map);
      
   }

   system("clear");
   
   print_enemy_map(enemy_map);
   
   if(aux_shot==5) printf("Afundaste um Barco!\n");
   if(aux_shot==1) printf("Acertaste num Barco!\n");
   if(aux_shot==3) printf("Falhaste\n");

}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||MAIN||||||||||||||||||||||||||||||||||||||||||||||||||


int main(){

   system("clear"); //IMPORTANTE
   printf("\n\n\n\n\n\n\n\n\n\n");
   printf ("\033[1;33m"); 
   printf ("           ██████████████████████x█X█x███████████████████████\n");
   printf ("            \\\\                                            //\n");
   printf ("\033[1;32m");
   printf ("     █████   ████  ██████ ██████ ██     ██████  █████ ██  ██ ██ ████\n");
	printf ("     ██  ██ ██  ██   ██     ██   ██     ██     ██     ██  ██ ██ ██  ██\n");
	printf ("     █████  ██  ██   ██     ██   ██     ████    ████  ██████ ██ ████\n"); 
	printf ("     ██  ██ ██████   ██     ██   ██     ██         ██ ██  ██ ██ ██\n");
	printf ("     █████  ██  ██   ██     ██   ██████ ██████ █████  ██  ██ ██ ██\n");
   printf ("\033[1;33m");
   printf ("            //                                            \\\\ \n");
   printf ("           ██████████████████████x█X█x███████████████████████\n\n");
   printf ("\033[0;31m");
   printf ("                             by 201805273\n\n");
   printf ("\033[0m");
   printf ("\n\n                          Press enter to play\n\n");
   char a;
   while(a!='\n')scanf("%c",&a);


   system("clear"); //IMPORTANTE


   printf("                          Insere o Tamanho do Mapa\n                               (entre 20 e 40)\n\n\n");

   int map_size;
   while((map_size>40)||(map_size<20)){
      scanf("%d",&map_size);
      if((map_size>40)||(map_size<20))  printf("Nao e possivel.\n");
   }



   system("clear"); //IMPORTANTE
   int max_barcos=(map_size*map_size)/25;
   printf("Insere o numero de barcos por jogador (minimo 5 e maximo %d):\n",max_barcos);
   int n_barcos;


   while ((n_barcos<5)||(n_barcos>max_barcos)){
   scanf("%d", &n_barcos);
      if((n_barcos<5)||(n_barcos>max_barcos)){
         printf("Nao e possivel\n");
         
      }
   }

   system("clear"); //IMPORTANTE
   
   int i;                                      
   Map* plyr_1_map;


   printf("Construir Mapa: Jogador 1\n\n");
   printf("Colocar Navios:\n\n\n automatico(tecla 1)        manual(tecla 2)\n\n");
   
   while((i!=1)&&(i!=2)){
  
   scanf("%d",&i);
  
   if(i==1){
       plyr_1_map = build_automatic_map(map_size,n_barcos);
       printf("Selecionado Colocacao Automatica\ny' para confirmar\n");
   }
    else{
       
         if(i==2){
            plyr_1_map = build_own_map(map_size,n_barcos);
            printf("Selecionado Colocacao Manual\ny' para confirmar\n");
         } 
         else printf("nao e uma opçao\n");
            scanf("%d",&i);
         }
   }

   char ready_1;
   while (ready_1!='y'){
      if(ready_1!='y') scanf("%c", &ready_1);   
   }

   system("clear");

   print_own_map(plyr_1_map);

   printf("\n\n'y'para continuar\n");
   char confirm_1;
   while (confirm_1!='y'){
      if(confirm_1!='y') scanf("%c", &confirm_1);
   }

   system("clear");


   printf("Construir Mapa: Jogador 2\n\n'y' para confirmar\n");
   ready_1=' ';
   while (ready_1!='y'){
      if(ready_1!='y') scanf("%c", &ready_1);   
   }

   system("clear");
   
   int j;                                      
   Map* plyr_2_map;


   printf("Construir Mapa: Jogador 2\n\n");
   printf("Colocar Navios:\n\n\n automatico(tecla 1)        manual(tecla 2)\n\n");
   
   while((j!=1)&&(j!=2)){
  
   scanf("%d",&j);
  
   if(j==1){
       plyr_2_map = build_automatic_map(map_size,n_barcos);
       printf("Selecionado Colocacao Automatica\ny' para confirmar\n");
   }
    else{
       
         if(j==2){
            plyr_2_map = build_own_map(map_size,n_barcos);
            printf("Selecionado Colocacao Manual\ny' para confirmar\n");
         } 
         else printf("nao e uma opçao\n");
            scanf("%d",&j);
         }
   }

   char ready_2;
   while (ready_2!='y'){
      if(ready_2!='y') scanf("%c", &ready_2);   
   }

   system("clear");

   print_own_map(plyr_2_map);

   printf("\n\n'y'para continuar\n");
   char confirm_2;
   while (confirm_2!='y'){
      if(confirm_2!='y') scanf("%c", &confirm_2);
   }

system("clear");

printf("E a vez do jogador 1 atacar!\n");
while((plyr_1_map->total_shotcount!=0)&&(plyr_2_map->total_shotcount!=0)){


char conf_1;
   
   turn(plyr_1_map,plyr_2_map);
   conf_1=' ';
    scanf("%c", &conf_1);
   while (conf_1!='\n'){
      if(conf_1!='\n') scanf("%c", &conf_1);
   }

   if(plyr_2_map->total_shotcount==0) break;

   printf("E a vez do jogador 2 atacar!\n(enter para continuar)");
char conf_2;
   scanf("%c", &conf_2);
   while (conf_2!='\n'){
      if(conf_2!='\n') scanf("%c", &conf_2);
   }

   system("clear");
   turn(plyr_2_map,plyr_1_map);
   conf_2=' ';
   
    scanf("%c", &conf_2);
   while (conf_2!='\n'){
      if(conf_2!='\n') scanf("%c", &conf_2);
   }

    if(plyr_2_map->total_shotcount==0) break;

   printf("E a vez do jogador 1 atacar!\n(enter para continuar)");
   scanf("%c", &conf_1);
   while (conf_1!='\n'){
      if(conf_1!='\n') scanf("%c", &conf_1);
   }
   system("clear");

}

printf("\033[1;34m");
if(plyr_2_map->total_shotcount==0) printf("Vitoria do Jogador 1\n");
if(plyr_1_map->total_shotcount==0) printf("Vitoria do Jogador 2\n");
printf("\033[1;0m");

return 0;
}
