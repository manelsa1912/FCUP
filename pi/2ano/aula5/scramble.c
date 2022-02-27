#include <stdio.h>

int main(){
int sum=0;
char c;
while(c!='\n'){

  c=getchar();
 
  switch(c){
   case 'A': case 'E':
   case 'I': case 'L': 
   case 'N': case 'O':    
   case 'R': case 'T':   
   case 'S': case 'U': sum+=1;
                       break;
   
   case 'D':
   case 'G': sum+=2;
             break;
   
   case 'B': case 'C':
   case 'M': case 'P': sum+=3;
                       break;
   
   case 'F': case 'H':
   case 'V': case 'W':
   case 'Y':           sum+=4;
                       break;
   
   case 'K': sum+=5;
           break;
   
   case 'J': case 'X': sum+=8;
                       break;
   
   case 'Q': case 'Z': sum+=10;
                       break;  
    
   default: sum+=0; 
  
  }

}
printf("\npontuacao = %d\n", sum);

return 0;
}