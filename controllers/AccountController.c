#include "./AccountController.h"
#include <string.h>

Response AccountController_search(int id, char *query) {
  Account account;
  account.id = 0;

  if ((int)strlen(query) > 0) {
    account = DBController_findRecordByName(query);
  } else {
    account = DBController_findRecord(id);
  }

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
        Response res =
            DBController_writeToDB(&accounts, "put", accounts.data[i].id);
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
      if (accounts.data[i].balance - saldo >= 0 && saldo > 0) {
        accounts.data[i].balance = accounts.data[i].balance - saldo;

        Response res =
            DBController_writeToDB(&accounts, "put", accounts.data[i].id);
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
  return res;
}

Response AccountController_overallBalance() {
  Response res;
  AccountArray accounts = DBController_getRecords();
  float overallBalance = 0;

  for (int i = 1; i < accounts.size + 1; i++) {
    if (!accounts.data[i].isDeleted) {
      overallBalance = overallBalance + accounts.data[i].balance;
    }
  }

  asprintf(&res.message, "O saldo geral é de: R$ %.2lf", overallBalance);
  res.status = 1;

  return res;
}

Response AccountController_modifyAccountStatus(int id, int op) {
  Response res;
  AccountArray accounts = DBController_getRecords();

  for (int i = 1; i < accounts.size + 1; i++) {
    if (accounts.data[i].id == id) {

      if (op == 1) {
        if (accounts.data[i].isDeleted == 0 && accounts.data[i].balance == 0) {
          accounts.data[i].isDeleted = 1;

          Response res = DBController_writeToDB(&accounts, "put", id);
          asprintf(&res.message, "Conta desabilitada com sucesso.");

          res.status = 1;

          return res;
        } else if (accounts.data[i].isDeleted == 0 &&
                   accounts.data[i].balance > 0) {
          asprintf(&res.message, "Erro ao atualizar: saque todo o saldo da "
                                 "conta antes de desabilita-la.");
          res.status = 1;
          return res;
        }

        asprintf(

            &res.message,

            "Erro ao atualizar: a conta selecionada ja esta desabilitada.");

        res.status = 0;

        return res;
      }

      if (accounts.data[i].isDeleted == 1) {

        accounts.data[i].isDeleted = 0;

        Response res = DBController_writeToDB(&accounts, "put", id);
        asprintf(&res.message, "Conta habilitada com sucesso!");

        res.status = 1;

        return res;
      }
      asprintf(&res.message,

               "Erro ao atualizar: a conta selecionada ja esta habilitada.");

      res.status = 0;

      return res;
    }
  }
  asprintf(&res.message, "Erro ao atualizar: conta nao encontrada.");
  res.status = 0;
}

Response AccountController_modifyAccount(int id, char *name) {

  Response res;
  AccountArray accounts = DBController_getRecords();

  for (int i = 1; i < accounts.size + 1; i++) {
    if (accounts.data[i].id == id && accounts.data[i].isDeleted == 0) {
      strcpy(accounts.data[i].name, name);

      Response res = DBController_writeToDB(&accounts, "put", id);
      asprintf(&res.message, "Conta alterada com sucesso!");
      res.status = 1;
      return res;
    } else if (accounts.data[i].id == id && accounts.data[i].isDeleted == 1) {
      asprintf(&res.message, "Erro ao alterar: conta desabilitada.");
      res.status = 1;
      return res;
    }
  }

  asprintf(&res.message, "Erro ao alterar: conta nao encontrada.");
  res.status = 0;
  return res;
}

Response AccountController_saveRecord(Account acc) {

  AccountArray accs = DBController_getRecords();
  accs.data = (Account *)realloc(accs.data, (accs.size + 2) * sizeof(Account));

  acc.id = accs.size + 1;
  acc.isDeleted = 0;

  accs.data[accs.size + 1] = acc;
  accs.size++;

  Response res = DBController_writeToDB(&accs, "post", acc.id);

  return res;
}

AccountArray AccountController_getAllRecords() {
  AccountArray accounts = DBController_getRecords();
  AccountArray enabledAccounts;
  enabledAccounts.size = 0;
  enabledAccounts.data = malloc(sizeof(Account));

  for (int i = 1; i < accounts.size + 1; i++) {
    if (!accounts.data[i].isDeleted) {
      enabledAccounts.size++;
      enabledAccounts.data = realloc(
          enabledAccounts.data, (enabledAccounts.size + 1) * sizeof(Account));
      enabledAccounts.data[enabledAccounts.size - 1] = accounts.data[i];
    }
  }

  return enabledAccounts;
}

AccountArray AccountController_getDeletedRecords() {
  AccountArray accounts = DBController_getRecords();
  AccountArray deletedRecords;
  deletedRecords.size = 0;
  deletedRecords.data = malloc(sizeof(Account));

  for (int i = 1; i < accounts.size + 1; i++) {
    if (accounts.data[i].isDeleted) {
      deletedRecords.size++;
      deletedRecords.data = realloc(
          deletedRecords.data, (deletedRecords.size + 1) * sizeof(Account));
      deletedRecords.data[deletedRecords.size - 1] = accounts.data[i];
    }
  }

  return deletedRecords;
}