#include "../models/DB.h"
#include "../models/Response.h"
#include <stdio.h>
#include <stdlib.h>

/*
Função para obter os registros do banco de dados
*/
AccountArray DBController_getRecords();

/*
  Função para pesquisar um registro com base no id no banco de dados
*/
Account DBController_findRecord(int id);

/*
  Função para salvar no banco dados
  A função espera receber um objeto lista de contas
  Pode-se utilizar a função DBController_getRecords para obter a lista atual de
  registros e então inserir, alterar ou excluir Em seguida, é só passar o
  AccountArray modificado para a função registrar no arquivo
*/
Response DBController_writeToDB(AccountArray *accounts, char *http_method,
                                int id);