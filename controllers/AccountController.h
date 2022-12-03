#include "../models/Account.h"
#include "../models/Response.h"
#include "./DBController.h"

/*
  Função para procurar a conta em uma lista de contas
*/
Response AccountController_search(int id, char *query);

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

/*
  Função responsável por somar todos os valores disponíveis
  nas contas do banco.
*/
Response AccountController_overallBalance();

/*
  Função responsável por atualizar o status de conta habilitada/desabilitada.
*/
Response AccountController_modifyAccountStatus(int id, int op);

/*
  Função responsável por atualizar o nome da conta do cliente.
*/
Response AccountController_modifyAccount(int id, char *name);

/*
  Função responsável por retornar toda a lista de contas.
*/
AccountArray AccountController_getAllRecords();

AccountArray AccountController_getDeletedRecords();