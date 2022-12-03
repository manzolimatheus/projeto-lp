#include "./AccountView.h"
#include "../helpers/utils.h"

void AccountView_saveRecord() {
  system("python3 main.py get");
  clearScreen(0);

  Account acc;

  printf("\nCADASTRO DE CONTA");
  printf("\nNome da conta: >");
  scanf(" ");
  fflush(stdin);
  fgets(acc.name, 51, stdin);
  acc.name[strcspn(acc.name, "\n")] = 0;
  printf("\nEh um cliente especial? [1/0] >");
  scanf("%i", &acc.isSpecial);
  fflush(stdin);

  Response res = AccountController_saveRecord(acc);

  printf("\n%s", res.message);
  Utils_pause();

  clearScreen(0);
}

void AccountView_searchAccount() {
  system("python3 main.py get");
  clearScreen(0);

  int choice;

  printf("\nBUSCA DE CONTA");
  printf("\nEscolha sua opção:");
  printf("\n[1]. Buscar por Id");
  printf("\n[2]. Buscar por nome");
  printf("\n[3]. Cancelar busca\n>");
  scanf("%i", &choice);

  int id = 0;
  char query[20];

  switch (choice) {
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
  case 3:
    printf("\nCancelando busca...");
    return;
    break;
  default:
    printf("\nOpcao invalida! Cancelando...");
    break;
  }

  Response res = AccountController_search(id, query);

  printf("\n%s", res.message);
  fflush(stdin);
  Utils_pause();

  clearScreen(3);
}

void AccountView_depositValue() {
  system("python3 main.py get");
  clearScreen(0);

  int id;
  double saldo;

  printf("\nDEPOSITO EM CONTA");
  printf("\nDigite o id da conta: >");
  scanf("%i", &id);
  fflush(stdin);
  printf("\nDigite saldo que deseja depositar na conta: >R$ ");
  scanf("%lf", &saldo);

  Response res = AccountController_deposit(saldo, id);
  printf("\n%s", res.message);
  Utils_pause();

  clearScreen(0);
}

void AccountView_withdrawValue() {
  system("python3 main.py get");
  clearScreen(0);

  int id;
  double saldo;

  printf("\nSAQUE EM CONTA");
  printf("\nDigite o id da conta: >");
  scanf("%i", &id);
  fflush(stdin);
  printf("\nDigite saldo que deseja sacar da conta: >R$ ");
  scanf("%lf", &saldo);

  Response res = AccountController_withdraw(saldo, id);
  printf("\n%s", res.message);
  Utils_pause();

  clearScreen(0);
}

void AccountView_overallBalance() {
  system("python3 main.py get");
  clearScreen(0);

  printf("\nSALDO GERAL");
  Response res = AccountController_overallBalance();

  printf("\n%s", res.message);
  printf("\n");
  Utils_pause();

  fflush(stdin);
  clearScreen(0);
}

void AccountView_modifyStatusAccount() {
  system("python3 main.py get");
  clearScreen(0);

  int id, op;
  char *opcoes[] = {"Desabilitar Conta", "Habilitar Conta"};

  printf("\nMODIFICAR STATUS DA CONTA");

  op = outputMenu(opcoes, 2);
  printf("\nDigite o ID da conta: >");
  scanf("%d", &id);

  Response res = AccountController_modifyAccountStatus(id, op);
  printf("%s", res.message);
  Utils_pause();

  fflush(stdin);
  clearScreen(0);
}

void AccountView_showTrashCan() {
  system("python3 main.py get");
  clearScreen(0);

  printf("\nExibindo todos os registros...\n\n");
  AccountArray accounts = AccountController_getDeletedRecords();
  for (int i = 0; i < accounts.size; i++) {
    // if (accounts.data[i].isDeleted) {
    printf("\nId: %i, Nome: %s, Eh Especial? %s, Saldo: %.2lf, Deletado? %s",
           accounts.data[i].id, accounts.data[i].name,
           accounts.data[i].isSpecial ? "Sim" : "Nao", accounts.data[i].balance,
           accounts.data[i].isDeleted ? "Sim" : "Nao");
    // }
  }

  Utils_pause();
  clearScreen(0);
}

void AccountView_showRecords() {
  system("python3 main.py get");
  clearScreen(1);
  printf("\nExibindo todos os registros...\n\n");
  AccountArray accounts = AccountController_getAllRecords();
  for (int i = 0; i < accounts.size; i++) {
    printf("\nId: %i, Nome: %s, Eh Especial? %s, Saldo: %.2lf, Deletado? %s",
           accounts.data[i].id, accounts.data[i].name,
           accounts.data[i].isSpecial ? "Sim" : "Nao", accounts.data[i].balance,
           accounts.data[i].isDeleted ? "Sim" : "Nao");
  }

  Utils_pause();
}

void AccountView_modifyAccount() {
  system("python3 main.py get");
  clearScreen(0);

  int id;
  char name[51];

  printf("\nMODIFICAR CONTA - ALTERAR NOME");
  printf("\nDigite o ID da conta: >");
  scanf("%d", &id);
  printf("\nDigite o nome da conta: >");
  scanf(" ");
  fgets(name, 51, stdin);
  name[strcspn(name, "\n")] = 0;

  Response res = AccountController_modifyAccount(id, name);
  printf("%s", res.message);
  Utils_pause();

  fflush(stdin);
  clearScreen(0);
}