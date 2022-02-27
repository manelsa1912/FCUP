#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

  int i,val,val2,val3;

  if(argc > 4){
    printf("seq: extra operands");
    exit(1);
  }

  if(argc==1){
    printf("missing operand");
    exit(2);
  }

  if(argc==2){
    val=atoi(argv[1]);
    for(i=1;i<=val;i++) printf("%d\n", i);
  }

  if(argc==3){
    val=atoi(argv[1]);
    val2=atoi(argv[2]);

    for(i=val;i<=val2;i++) printf("%d\n", i);
  }

  if(argc==4){
    val=atoi(argv[1]);
    val2=atoi(argv[2]);
    val3=atoi(argv[3]);

    if(val3>=val){
      i=val;

      while(i<=val3){
      printf("%d\n", i);
      i=i+val2;
      }
    }

    else{
      i=val;
      if(val2<0){
	while(i>=val3){
	  printf("%d\n", i);
	  i=i+val2;}
      }
    }
  }
  
  return 0;
}
