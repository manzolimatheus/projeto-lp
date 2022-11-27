#include "./AccountView.h"

void saveRecord() {
  Account acc;

  printf("\nNome da conta: >");
  scanf("%s", acc.name);
  fflush(stdin);
  printf("\nEh um cliente especial? [1/0] >");
  scanf("%i", &acc.isSpecial);
  fflush(stdin);
  printf("\nSaldo da conta: >");
  scanf("%lf", &acc.balance);
  fflush(stdin);

  Response res = AccountController_saveRecord(acc);

  printf("\n%s", res.message);
}

void searchAccount() {
  int id;
  printf("\nDigite o id da conta: >");
  scanf("%i", &id);
  fflush(stdin);

  Response res = AccountController_search(id);

  printf("\n%s", res.message);
}

void depositValue() {
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

void withdrawValue() {
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