#include <stdio.h>
#include <stdlib.h>

void def_print(int argc,char *argv[]){
   char c;
    if(argc==1){
       while((c=getchar())!= EOF) printf("%c",c);
       exit(0);
    }

    FILE* arq;
    for(int i=1;i<argc;i++){
       if(*argv[i]=='-'){
          while((c=getchar())!= EOF) printf("%c",c);
          continue;
       }

       arq = fopen(argv[i],"r");
       while((c=fgetc(arq))!= EOF) printf("%c",c);
       fclose(arq);
    }
    exit(0);
}

int main(int argc,char *argv[]){
  def_print(argv,argv);
  return 0;

}


