// #include "tests/AccountController/AccountController_test.h"
#include "views/MenuView.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Sincronizando o CSV com a nuvem
  system("python3 main.py get");

  // 🐢 *TODO*
  // Por conta do tempo, os testes
  // Não estão funcionais
  // Precisam ser implementados e ajustados
  // @tests
  // AccountController_runTests();

  menu();

  return 0;
}