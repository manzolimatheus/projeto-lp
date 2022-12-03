#include "./DBController.h"

AccountArray DBController_getRecords() {
  // Open db.csv and convert to Record array
  FILE *fp = fopen("database/accounts.csv", "r");
  AccountArray array;

  if (fp == NULL) {
    printf("\nError opening file");
    array.size = 0;
    array.data = NULL;

    return array;
  }

  char line[100];
  int i = 0;
  Account *accounts = NULL;
  char *p_balance;

  while (fgets(line, 100, fp) != NULL) {
    if (i == 0) {
      accounts = realloc(accounts, 1 * sizeof(Account));
    }
    char *token = strtok(line, ",");
    accounts[i].id = atoi(token);
    token = strtok(NULL, ",");
    strcpy(accounts[i].name, token);
    token = strtok(NULL, ",");
    accounts[i].isSpecial = atoi(token);
    token = strtok(NULL, ",");
    accounts[i].balance = strtod(token, &p_balance);
    token = strtok(NULL, ",");
    accounts[i].isDeleted = atoi(token);
    i++;
    accounts = realloc(accounts, (i + 1) * sizeof(Account));
  }

  // close the file
  fclose(fp);

  array.size = i - 1;
  array.data = accounts;

  return array;
}

Account DBController_findRecord(int id) {
  AccountArray array = DBController_getRecords();
  Account acc;
  acc.id = 0;

  for (int i = 1; i < array.size + 1; i++) {
    if (array.data[i].id == id && !array.data[i].isDeleted) {
      acc = array.data[i];
      return acc;
    }
  }

  return acc;
}

Account DBController_findRecordByName(char *query) {
  AccountArray array = DBController_getRecords();
  Account acc;
  acc.id = 0;

  for (int i = 1; i < array.size + 1; i++) {
    if (strstr(array.data[i].name, query) != NULL && !array.data[i].isDeleted) {
      acc = array.data[i];
      return acc;
    }
  }

  return acc;
}

Response DBController_writeToDB(AccountArray *accounts, char *http_method,
                                int id) {

  // printf("\nContas recebidas:\n");
  // for (int i = 1; i < accounts->size + 1; i++) {
  //   printf("\n%i,%s,%i,%.2lf,%i", accounts->data[i].id,
  //   accounts->data[i].name,
  //          accounts->data[i].isSpecial, accounts->data[i].balance,
  //          accounts->data[i].isDeleted);
  // }
  // printf("\n---------");

  FILE *fp = fopen("database/accounts.csv", "w");
  Response res;

  if (fp == NULL) {
    res.status = 0;
    asprintf(&res.message, "Error opening file");

    return res;
  }

  fprintf(fp, "id, name, isSpecial, balance, isDeleted");

  for (int i = 1; i < accounts->size + 1; i++) {
    fprintf(fp, "\n%i,%s,%i,%.2lf,%i", accounts->data[i].id,
            accounts->data[i].name, accounts->data[i].isSpecial,
            accounts->data[i].balance, accounts->data[i].isDeleted);
  }

  fclose(fp);

  asprintf(&res.message, "Salvo com sucesso!");
  res.status = 1;

  char *command;
  asprintf(&command, "python3 main.py %s %i", http_method, id);
  system(command);

  return res;
}
