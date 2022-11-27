#include "./AccountView.h"

void AccountView_saveRecord() {
  Account acc;
  printf("\nNome da conta: >");
  scanf(" ");
  fgets(acc.name, 30, stdin);
  acc.name[strcspn(acc.name, "\n")] = 0;
  printf("\nEh um cliente especial? [1/0] >");
  scanf("%i", &acc.isSpecial);
  fflush(stdin);

  Response res = AccountController_saveRecord(acc);

  printf("\n%s", res.message);
}

void AccountView_searchAccount() {

  int choice;
  line();
  printf("\nBUSCA DE CONTA");
  printf("\nEscolha sua opção:");
  printf("\n[1]. Buscar por Id");
  printf("\n[2]. Buscar por nome");
  printf("\n[3]. Cancelar busca\n>");
  scanf("%i", &choice);

  int id = 0;
  char query[20];

  switch(choice) {
    case 1:
      printf("\nDigite o id da conta: >");
      scanf("%i", &id);
      fflush(stdin);
      break;
    case 2:
      printf("\nDigite o nome da conta: >");
      scanf(" ");
      fgets(query, 30, stdin);
      query[strcspn(query, "\n")] = 0;
      fflush(stdin);
      break;
    default:
      printf("\nOpcao invalida! Cancelando...");
    break;
  }

  Response res = AccountController_search(id, query);

  printf("\n%s", res.message);
}

void AccountView_depositValue() {
  int id;
  double saldo;

  printf("\nDigite o id da conta: >");
  scanf("%i", &id);
  fflush(stdin);
  printf("\nDigite saldo que deseja depositar na conta: >R$ ");
  scanf("%lf", &saldo);

  Response res = AccountController_deposit(saldo, id);
  printf("\n%s", res.message);
}

void AccountView_withdrawValue() {
  int id;
  double saldo;

  printf("\nDigite o id da conta: >");
  scanf("%i", &id);
  fflush(stdin);
  printf("\nDigite saldo que deseja sacar da conta: >R$ ");
  scanf("%lf", &saldo);

  Response res = AccountController_withdraw(saldo, id);
  printf("\n%s", res.message);
}