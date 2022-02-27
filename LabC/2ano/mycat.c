#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//imprimir o conteudo
int ler_ficheiro(char *name){

	FILE *fic;
	char ch;
	
	if(fic = fopen(name,"r")){
	
	while ((ch = fgetc(fic)) != EOF){
		putchar(ch);
	}
	fclose(fic);
	return 0;
	}
	return 1;
}

int colocar_fic(char *fic1,char *new_fic){




}

void print_terminal(){

	char c;
	while (c!=EOF){
		scanf("%c",&c);
		printf("%c",c);
	}
}


int main(int argc, char* argv[]){

	for(int i=1; i<argc; i++){
		if (argv[i]== '-')||(argc==1) print_terminal();
		
		int aux=ler_ficheiro(argv[i];
		if(aux==0) ler_ficheiro(argv[i]);
		else {
			printf("./my_cat: <file>: No such file or directory\n");
			return 1;
		}
	}

	return 0;
}