#include "./AccountController.h"
#include <string.h>

Response AccountController_search(int id) {

  Account account = DBController_findRecord(id);
  // printf("\nId: %i, Nome: %s, Eh Especial? %s, Saldo: %.2lf\n", account.id,
  //        account.name, account.isSpecial ? "Sim" : "Nao", account.balance);

  Response res;

  if (!account.id || account.isDeleted) {
    res.status = 0;
    asprintf(&res.message, "Conta nao encontrada");
    return res;
  }

  res.status = 1;
  asprintf(&res.message, "Id: %i, Nome: %s, Eh Especial? %s, Saldo: %.2lf",
           account.id, account.name, account.isSpecial ? "Sim" : "Nao",
           account.balance);
  return res;
}

Response AccountController_deposit(float saldo, int id) {
  Response res;
  AccountArray accounts = DBController_getRecords();

  for (int i = 1; i < accounts.size + 1; i++) {
    if (accounts.data[i].id == id && !accounts.data[i].isDeleted) {
      if (saldo > 0) {
        accounts.data[i].balance = accounts.data[i].balance + saldo;

        res.status = 1;
        Response res = DBController_writeToDB(&accounts);
        asprintf(&res.message, "Deposito realizado com sucesso.");
        return res;
      }
      res.status = 1;
      asprintf(
          &res.message,
          "Erro ao depositar saldo: Saldo de deposito deve ser maior que 0.");
      return res;
    }
  }
  res.status = 0;
  asprintf(&res.message,
           "Erro ao depositar saldo: Conta nao encontrada ou desativada.");
  return res;
}

Response AccountController_withdraw(float saldo, int id) {
  Response res;
  AccountArray accounts = DBController_getRecords();

  for (int i = 1; i < accounts.size + 1; i++) {
    if (accounts.data[i].id == id && !accounts.data[i].isDeleted) {
      if (accounts.data[i].balance - saldo == 0 ||
          accounts.data[i].balance - saldo > 0 && saldo > 0) {
        accounts.data[i].balance = accounts.data[i].balance - saldo;

        Response res = DBController_writeToDB(&accounts);
        asprintf(&res.message, "Saque realizado com sucesso.");
        res.status = 1;
        return res;
      }
      asprintf(&res.message,
               "Erro ao sacar: Valor de saque indisponivel em conta.");
      res.status = 1;
      return res;
    }
  }
  res.status = 0;
  asprintf(&res.message, "Erro ao sacar: Conta nao encontrada ou desativada.");
}

Response AccountController_saveRecord(Account acc) {

  AccountArray accs = DBController_getRecords();

  accs.data = realloc(accs.data, (accs.size + 1) * sizeof(Account));

  acc.id = accs.size + 1;
  acc.isDeleted = 0;

  accs.data[accs.size + 1] = acc;
  accs.size++;

  Response res = DBController_writeToDB(&accs);

  return res;
}