#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"barcos.h"




Boat* build_boat(int b,int rot){
   
Boat* barco = (Boat*) malloc(sizeof(Boat));
barco->rot = rot;
barco->shot_count = 0;

   switch (b)
   {
   case 1:                 // CARGUEIRO

      barco->ship=CARGUEIRO;   
      switch (rot)
      {
      case 0:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if(i==2){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
               
            }
         }
         break;
      
      case 90:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if(j==2){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 180:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if(i==2){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

         case 270:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if(j==2){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

         case 360:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if(i==2){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;
      default:
         break;
      }
      break;
   
   


   case 2:                          // COURACA
      
      barco->ship=COURACA;   
      switch (rot)
      {
      case 0:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==2)&&(j!=4)){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;
      
      case 90:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((j==2)&&(i!=0)){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 180:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==2)&&(j!=0)){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 270:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((j==2)&&(i!=4)){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 360:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==2)&&(j!=4)){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;
      
      default:
         break;
      }
      break;
   
   
   case 3:                          // CRUZEIRO
      
      barco->ship=CRUZEIRO; 
      switch (rot)
      {
      case 0:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==2)&&((j>=1)&&(j<=3))){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;
      
      case 90:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((j==2)&&((i>=1)&&(i<=3))){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 180:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==2)&&((j>=1)&&(j<=3))) {
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 270:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((j==2)&&((i>=1)&&(i<=3))){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 360:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==2)&&((j>=1)&&(j<=3))){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      
      default:
         break;
      }
      break;

   case 4:                          // SUBMARINO
      
      barco->ship=SUBMARINO; 
      switch (rot)
      {
      case 0:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==2)&&((j>=1)&&(j<=3))){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;
      
      case 90:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((j==2)&&((i>=1)&&(i<=3))){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 180:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==2)&&((j>=1)&&(j<=3))){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 270:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((j==2)&&((i>=1)&&(i<=3))){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 360:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==2)&&((j>=1)&&(j<=3))){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;
      
      default:
         break;
      }
      break;

      case 5:                          // DESTRUIDOR
      
      barco->ship=DESTRUIDOR; 
      switch (rot)
      {
      case 0:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==2)||(j==0)){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;
      
      case 90:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==4)||(j==2)){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 180:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==2)||(j==4)){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 270:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==0)||(j==2)){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;

      case 360:
         for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if((i==2)||(j==0)){
                  barco->canonical[i][j]='1';
                  barco->shot_count++;
               }
               else barco->canonical[i][j]='0';
            }
         }
         break;
      
      default:
         break;
      }
      break;
   
   default:
      break;
   }
   return barco;
}

void print_boat(Boat* barco_p1){

   for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
         if(barco_p1->canonical[i][j]=='1'){
            printf("\033[1;32m");
            printf("%c ",barco_p1->canonical[i][j]);
            printf("\033[0m");
         }
         else{
            printf("\033[1;34m");
            printf("%c ",barco_p1->canonical[i][j]);
            printf("\033[0m");
         }
      }
      printf("\n");
   }
}

