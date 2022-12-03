#include "../controllers/AccountController.h"

// Função para receber os dados de uma conta para criar seu registro
void AccountView_saveRecord();

// Função para receber o id da conta a ser pesquisada
void AccountView_searchAccount();

// Função para depositar determinado valor em uma conta com base em seu id
void AccountView_depositValue();

// Função para retirar determinado valor de uma conta com base em seu id
void AccountView_withdrawValue();

// Função para somar o saldo de todas as contas e retorná-lo
void AccountView_overallBalance();

// Função para exibir registros excluídos
void AccountView_showTrashCan();

// Função para exibir os registros
void AccountView_showRecords();

// Função para ativar/desativar registros
void AccountView_modifyStatusAccount();

// Função para atualizar o nome do registro
void AccountView_modifyAccount();