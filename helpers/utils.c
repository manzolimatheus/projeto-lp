#include "./utils.h"

void line(){
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void outputMenu(char ** words, int size){
for(int i = 0; i < size; i++){
printf("\n[%i] - [%s]", i + 1, words[i]);
}
printf("\nDigite sua resposta: >");
}