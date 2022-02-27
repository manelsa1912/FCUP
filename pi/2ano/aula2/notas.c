#include<stdio.h>

int main(){

int m,v,rv,d,rd,c,rc,u;

scanf("%d", &m);

v=m/20;
rv=m-(v*20);

d=rv/10;
rd=rv-(d*10);

c=rd/5;
rc=rd-(c*5);

u=rc;


printf("20€:%d\n10€:%d\n5€:%d\n1€:%d\n", v, d, c, u);
return 0;

}
