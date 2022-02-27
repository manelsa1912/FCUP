
#include<stdio.h>

int main(){

  float evap[12] ={8.6, 7.0, 6.4, 4.0, 2.8, 1.8, 1.8, 2.3, 3.2, 4.7, 6.2, 7.9};

    printf("polinomio:");

    
    printf("((x-%d)",2);
        for(int j=3;j<=12;j++){
            printf("*(x-%d)",j);
        }
        
        printf(")/");

        printf("("); 
        
        printf("(1-2)");
        for(int j=3;j<=12;j++){
            printf("*(1-%d)",j);
        }
       
        printf(")");
        printf("*%.1f+", evap[0]);
    
    
    
    
    for(int i=2;i<=12;i++){

        printf("("); 
        if(i!=1) printf("(x-%d)",1);
        for(int j=2;j<=12;j++){
            if(i!=j) printf("*(x-%d)",j);
        }
        
        printf(")/");

        printf("("); 
        if(i!=1) printf("(%d-%d)",i,1);
        for(int j=2;j<=12;j++){
            if(i!=j) printf("*(%d-%d)",i,j);
        }

        printf(")");

        
       if(i!=12)  printf("*%.1f+", evap[i-1]);
       
  
       else printf("*%.1f", evap[i-1]);
    }


    return 0;
}