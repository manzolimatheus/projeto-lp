#include "../models/Account.h"
#include "../models/Response.h"
#include "./DBController.h"

/*
  Função para procurar a conta em uma lista de contas
*/
Response AccountController_search(int id, char * query);

/*
  Função para adicionar depósito/saldo a uma conta já existente.
*/
Response AccountController_deposit(float saldo, int id);

/*
  Função para sacar saldo de uma conta já existente.
*/
Response AccountController_withdraw(float saldo, int id);

/*
  Função que recebe como parâmetro uma conta
  Ela salva no banco de dados (.csv) a conta recebida
*/
Response AccountController_saveRecord(Account acc);