#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int flag_c(char *name){

	FILE *fic;
	char ch;
	fic = fopen(name,"r");
	int contador=0;
	
	while ((ch = fgetc(fic)) != EOF){
		contador++;
	}
	fclose(fic);

	return contador;
}

int flag_w(char *name){

	FILE *fic;
	char ch;
	fic = fopen(name,"r");
	int contador=0;
	
	while ((ch = fgetc(fic)) != EOF){
		if(ch == ' ' || ch == '\n') contador++;
	}
	fclose(fic);

	return contador;
}

int flag_l(char *name){

	FILE *fic;
	char ch;
	fic = fopen(name,"r");
	int contador=0;
	
	while ((ch = fgetc(fic)) != EOF){
		if(ch == '\n') contador++;
	}
	fclose(fic);

	return contador;
}

int main(int argc, char* argv[]){

	char* flag = (char*)malloc(64 * sizeof(char));
	strcpy(flag,argv[1]);

	if((strcmp(flag,"-c")) == 0)
		printf("%d\n",flag_c(argv[2]));

	else if((strcmp(flag,"-w")) == 0)
		printf("%d\n",flag_w(argv[2]));

	else if((strcmp(flag,"-l")) == 0)
		printf("%d\n",flag_l(argv[2]));

	else printf("%d\n",flag_c(argv[1]));

	return EXIT_SUCCESS;
}