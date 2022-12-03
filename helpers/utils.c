#include "./utils.h"

void line() { printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"); }

int outputMenu(char **words, int size) {
  int response;
  for (int i = 0; i < size; i++) {
    printf("\n[%i] - [%s]", i + 1, words[i]);
  }
  printf("\nDigite sua resposta: >");
  scanf("%i", &response);

  if (response > size || response < 0) {
    printf("\nOpcao invalida!");
    return 0;
  }

  return response;
}

void Utils_pause() {
  int a;
  printf("\n\nDigite 1 para continuar...\n");
  scanf("%i", &a);
  clearScreen(1);
}

void clearScreen(int seconds) {
  sleep(seconds);
  system("clear");
}