#include "./tests.h"

void assertTest(char *label, int condition) {
  printf("\n %s - [%s]", label, condition ? "OK" : "ERROR");
}