#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>


void io_uniq(){
 
while((c=getchar()) != EOF) {
 
 
 
 

 }

}


void file_uniq(str[]){

 char c;
    
    FILE *fptr;
  
    if ((fptr = fopen(str)) == NULL){
        printf("Error! opening file");
        exit(-1);
    }
     
    else {
    
    fptr = fopen(str);
    while(c != EOF){
    
    
    }
 }
 
 }
 
void io_c(){
 
 char c;
 
  while((c=getchar()) != EOF) {
  
 
 
  
 
  }
 
 }
 
void file_c(str[]){
 
 char c;
    
    FILE *fptr;
 
    if ((fptr = fopen(str)) == NULL){
        printf("Error! opening file");
        exit(-1);
    }
    
    else {
    
    fptr = fopen(str);
    while(c != EOF){
    
    
    }
 }
 
 }
 
 
void io_d(){
 
 while((c=getchar()) != EOF) {
 
 
 
  
 
  }
 }
 
 
 
void file_d(str[]){
 
 char c;
    
    FILE *fptr;
 
    if ((fptr = fopen(str)) == NULL){
        printf("Error! opening file");
        exit(-1);
    }
    
    else {
    
    fptr = fopen(str);
    while(c != EOF){
    
    
    }
 }
 
 }
 
 
 
void io_i(){
 
 while((c=getchar()) != EOF) {
 
 
 
  
 
  }
 }
 
 
void file_i(str[]){
  
 char c;
    
    FILE *fptr;
 
    if ((fptr = fopen(str)) == NULL){
        printf("Error! opening file");
        exit(-1);
    }
    
    else {
    
    fptr = fopen(str);
    while(c != EOF){
    
    
    }
 }
 
 }
 
 
 
int main(int argc, char* argv[]){
 
 char c;
 
 
 
 while((c = getopt(argc,argv,"cdi")) != -1){
 
  switch (c) {
 
    case 'c':
    if(argc==2) io_c();
    if(argc==3) file_c(argv[2]);
    break;
 
    case 'd':
    if(argc==2) io_d();
    if(argc==3) file_d(argv[2]);
    break;
    
    case 'i':
    if(argc==2) io_i();
    if(argc==3) file_i(argv[2]);
    break;
    
    }
    
 }
        
