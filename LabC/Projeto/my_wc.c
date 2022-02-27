#include <stdio.h>
#include <string.h>

void wc_io(){

  int lines=0, words=0,chars=0;
  char c;
  while(c!=EOF){
    chars++;
    if(c=='\n') lines++;
    if(c==' ') words++;
  }
  printf("%d, %d, %d", lines, words, chars);

}


int find_count_of_lines(const char *str){

   int liness=0, i=0;

   for(i=0; str[i] != '\0'; i++){
     if( str[i] == '\n' ){
       liness+=1;
     }
   }
   return liness;
}



int find_count_of_words(const char *str){

int words=0, i=0;

 while(str[i] != '\0'){

   if( str[i] == ' ' || str[i] == '\n' || str[i]== '\r' || str[i] == '\t'){
    i++;
  }
   else{

     break;
  }
 }

for(; str[i] != '\0'; i++){

  if( str[i] == ' ' || str[i] == '\n' || str[i]== '\r' || str[i] == '\t' ){
    words+=1;
    
    while(str[i]==' ' || str[i] == '\n' || str[i]== '\r' || str[i] == '\t'){

      i++;
    }
  }
 }

return words;

}
 
 int txt_my_wc(FILE *fp, int *lines_p, int *words_p, int *chars_p){
								   int  lines=0, words=0, chars=0;
								   char buffer[1024]={0x00};
								   size_t bytes=0;
								   fseek(fp, 0L, SEEK_SET);
								   do{
                memset(buffer, 0x00, sizeof(buffer));
                bytes = fread(buffer, sizeof(char), sizeof(buffer)-1, fp);
                if(bytes > 0){
                        lines += find_count_of_lines(buffer);
                        words += find_count_of_words(buffer);
                        chars += bytes;
                }
        }while(bytes > 0);
        *lines_p = lines;
        *words_p = words;
        *chars_p = chars;
        return chars;
}


int main(int argc, char *argv[]){
        FILE *fp = NULL;
        int lines=0, words=0, chars=0,i;

	if((argc == 1)||((argc==2)&&(*argv[1]=='-'))) wc_io();

  
        if((argc > 1)&&(*argv[1]!='-')){
	  
	  for(i=0;i<argc;i++){
	    fp = fopen(argv[i], "r");
	    txt_my_wc(fp, &lines, &words, &chars);
	    printf("  %d  %d  %d  %s\n", lines, words, chars, argv[i]);
	    fclose(fp);}
	  printf("conatgens totais: %d\n", i);
	}
	
	  return 0;
}
