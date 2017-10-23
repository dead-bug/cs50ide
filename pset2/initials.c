#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <ctype.h>

int main(void){
 char* name=GetString();
 //printf("%s\n",name);
 bool capitalise=1;
 for(int i=0; i<strlen(name);i++){
  if(name[i]==' '){
   capitalise=1;
  }
  else {
   if(capitalise==1){
    printf("%c",toupper(name[i]));
    capitalise=0;
   }
   }
  }
  printf("\n");
 }