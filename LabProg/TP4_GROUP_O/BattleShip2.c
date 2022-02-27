#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "barcos.h"
#include "quadtree.h"
#include "enemy.h"
#include "player.h"
#include "quadutil.h"


void quad_turn(Player* p1,Player* p2){
  
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

   if(r=='y'){ print_my_quadmap(p1->map_for_enemy->size,p1->player_quadmap,p1->map_for_enemy);
   r =' ';
   printf("Continuar 'y'\n");

   while(r!='y') scanf("%c",&r);
   }

   system("clear");

   print_enemy_quadmap(p2->map_for_enemy);
   printf("Selecione uma coordenada para disparar\n");
   int shot_x,shot_y;
   scanf("%d",&shot_x);
   scanf("%d",&shot_y);

   int aux_shot=quad_shot(shot_x,shot_y,p2->map_for_enemy,p2->player_quadmap);
  
   while (aux_shot!=0){
      if(aux_shot==2){
         printf("Essa coordenada ja foi atingida\n");
         scanf("%d",&shot_x);
         scanf("%d",&shot_y);
      }

      if(aux_shot==1){
         printf("Posiçao fora do mapa\n");
         scanf("%d",&shot_x);
         scanf("%d",&shot_y);
      }

          aux_shot=quad_shot(shot_x,shot_y,p2->map_for_enemy,p2->player_quadmap);
      
   }

   quad_shot(shot_x,shot_y,p2->map_for_enemy,p2->player_quadmap);

   system("clear");
   
   
   print_enemy_quadmap(p2->map_for_enemy);


}

Player* build_own_quadmap(int map_size,int n_barcos){

   Player* player = new_player(map_size);
   //player->map_for_enemy = build_new_node(map_size);
   int aux_tipo=5;  // Auxiliar de verificaçao de todos os barcos colocados
   
   while(aux_tipo!=0){ 
      
     QD_NODE* m = build_new_node(map_size);
     Enemy* map_for_enemy=bulid_enemy(map_size);
     
     system("clear"); //IMPORTANTE  
      
      int aux_barcos=n_barcos; //Contador de Barcos restantes a colocar
      int tipo_barco[5]; // Verificador de cada tipo de barco 0 existe 1 nao existe
      for(int i=0;i<5;i++) tipo_barco[i]=1;

     
   

      for(int i=0;i<n_barcos;i++){

         printf("Faltam colocar %d barcos",aux_barcos );
         print_my_quadmap(map_size,m,map_for_enemy);

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
         print_my_quadmap(map_size,m,map_for_enemy);

         int x,y;
         scanf("%d",&x);
         scanf("%d",&y);
         
         while((x<0)||(x>map_size)||(y<0)||(y>map_size)){
            printf("nao e possivel\n");
            scanf("%d",&x);
            scanf("%d",&y);
         }
         
         system("clear"); //IMPORTANTE

         int aux=insert_boat(barco_p1,x,y,m,map_for_enemy);
         while(aux!=0){
            if(aux==3){
               
               print_boat(barco_p1);
               printf("\nPosicao fora do mapa.Insere outra coordenada\n");
               print_my_quadmap(map_size,m,map_for_enemy);

               scanf("%d",&x);
               scanf("%d",&y);
               
               while((x<0)||(x>map_size)||(y<0)||(y>map_size)){
                  printf("Posicao fora do mapa\n");
                  scanf("%d",&x);
                  scanf("%d",&y);
                  
               }
               aux=insert_boat(barco_p1,x,y,m,map_for_enemy);
            }
         
            if(aux==1){
               print_boat(barco_p1);
               printf("\nJa existe um barco aqui.Insere outra coordenada\n");
               print_my_quadmap(map_size, m,map_for_enemy);
               
               scanf("%d",&x);
               scanf("%d",&y);
               
               while((x<0)||(x>map_size)||(y<0)||(y>map_size)){
                  printf("nao e possivel\n");
                  scanf("%d",&x);
                  scanf("%d",&y);
               
               }
                aux=insert_boat(barco_p1,x,y,m,map_for_enemy);
            }


         }  
         insert_boat(barco_p1,x,y,m,map_for_enemy);
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

      player->player_quadmap=m;
      player->map_for_enemy=map_for_enemy;
   }
   system("clear");
   return player;
}

int main()
{
 system("clear"); //IMPORTANTE
   printf("\n\n\n\n\n\n\n\n\n\n");
   printf ("\033[1;31m"); 
   printf ("           ██████████████████████x█X█x███████████████████████\n");
   printf ("            \\\\                                            //\n");
   printf ("\033[0m");
   printf ("               ------------------------------------------\n");
   printf ("     █████   ████  ██████ ██████ ██     ██████  █████ ██  ██ ██ ████\n");
	printf ("     ██  ██ ██  ██   ██     ██   ██     ██     ██     ██  ██ ██ ██  ██\n");
	printf ("     █████  ██  ██   ██     ██   ██     ████    ████  ██████ ██ ████\n"); 
	printf ("     ██  ██ ██████   ██     ██   ██     ██         ██ ██  ██ ██ ██\n");
	printf ("     █████  ██  ██   ██     ██   ██████ ██████ █████  ██  ██ ██ ██\n");
   printf ("               ---------------QUAD VERSION---------------\n");
   printf ("\033[1;31m");
   printf ("            //                                            \\\\ \n");
   printf ("           ██████████████████████x█X█x███████████████████████\n\n");
   printf ("\033[1;34m");
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
   Player* p1;


   printf("Construir Mapa: Jogador 1\n\n");
   printf("Colocar Navios:\n\n\n automatico(tecla 1)        manual(tecla 2)\n\n");
   
   while((i!=1)&&(i!=2)){
  
   scanf("%d",&i);
  
   if(i==1){
       p1 = build_automatic_quadmap(map_size,n_barcos);
       printf("Selecionado Colocacao Automatica\ny' para confirmar\n");
   }
    else{
       
         if(i==2){
            p1 = build_own_quadmap(map_size,n_barcos);
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

   print_my_quadmap(p1->map_for_enemy->size,p1->player_quadmap,p1->map_for_enemy);

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
   Player* p2;


   printf("Construir Mapa: Jogador 2\n\n");
   printf("Colocar Navios:\n\n\n automatico(tecla 1)        manual(tecla 2)\n\n");
   
   while((j!=1)&&(j!=2)){
  
   scanf("%d",&j);
  
   if(j==1){
       p2 = build_automatic_quadmap(map_size,n_barcos);
       printf("Selecionado Colocacao Automatica\ny' para confirmar\n");
   }
    else{
       
         if(j==2){
            p2 = build_own_quadmap(map_size,n_barcos);
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

   print_my_quadmap(p2->map_for_enemy->size,p2->player_quadmap,p2->map_for_enemy);

   printf("\n\n'y'para continuar\n");
   char confirm_2;
   while (confirm_2!='y'){
      if(confirm_2!='y') scanf("%c", &confirm_2);
   }

system("clear");

printf("E a vez do jogador 1 atacar!\n");
while((p1->map_for_enemy->total_shot_count!=0)&&(p2->map_for_enemy->total_shot_count!=0)){


char conf_1;
   
   quad_turn(p1,p2);
   conf_1=' ';
    scanf("%c", &conf_1);
   while (conf_1!='\n'){
      if(conf_1!='\n') scanf("%c", &conf_1);
   }

   if(p2->map_for_enemy->total_shot_count==0) break;

   printf("E a vez do jogador 2 atacar!\n(enter para continuar)");
char conf_2;
   scanf("%c", &conf_2);
   while (conf_2!='\n'){
      if(conf_2!='\n') scanf("%c", &conf_2);
   }

   system("clear");
   quad_turn(p2,p1);
   conf_2=' ';
   
    scanf("%c", &conf_2);
   while (conf_2!='\n'){
      if(conf_2!='\n') scanf("%c", &conf_2);
   }

    if(p1->map_for_enemy->total_shot_count==0) break;

   printf("E a vez do jogador 1 atacar!\n(enter para continuar)");
   scanf("%c", &conf_1);
   while (conf_1!='\n'){
      if(conf_1!='\n') scanf("%c", &conf_1);
   }
   system("clear");

}

printf("\033[1;34m");
if(p2->map_for_enemy->total_shot_count==0) printf("Vitoria do Jogador 1\n");
if(p1->map_for_enemy->total_shot_count==0) printf("Vitoria do Jogador 2\n");
printf("\033[1;0m");

return 0;
}
