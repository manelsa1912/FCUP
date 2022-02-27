#include<stdio.h>

void decompor(int total_seg, int *horas, int *mins, int *segs){

  *horas=total_seg/(60*60);
  *mins=total_seg%(60*60);
  *segs=(*mins)%60;
  *mins=(*mins)/60;
  
  }


int main(){

  int a, b, c;
  int ts, *h, *m, *s;

  printf("introduz o total de segundos:\n");
  scanf("%d", &ts);

  h=&a; m=&b; s=&c;


  decompor(ts, h, m, s);

  printf("%d segundos sao \n %d horas, %d minutos e %d segundos.\n", ts, *h, *m, *s);
  
   return 0;
}
