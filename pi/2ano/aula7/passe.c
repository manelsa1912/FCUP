#include<stdio.h>

int forte(char str[]){
int sum=0,mais=0,menos=0,num=0;

for(int i=0;str[i]!='\0';i++){

  if(str[i]>='A'&& str[i]<='Z') {
    //sum++;
    mais++;
  }

  if(str[i]>='a'&& str[i]<='z') {
    //sum++;
    menos++;
  }

  if(str[i]>='0'&& str[i]<='9') {
    //sum++;
    num++;
  }
  sum++;
}

if(sum>=6 && mais>=1 && menos>=1 && num>=1) return 1;
else return 0;

}