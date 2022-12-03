#include "./AccountController_test.h"
#include "../../helpers/utils.h"

void AccountController_runTests() {
  test_search_account_by_id_should_return_not_found();
  test_search_account_by_id_should_return_found();
  test_search_account_by_name_should_return_not_found();
  test_search_account_by_name_should_return_found();
  test_if_balance_is_being_deposited();
  test_if_balance_is_not_being_deposited();
  test_if_withdraw_was_made();
  test_if_withdraw_was_not_made();
  // test_create_account_should_create();
  test_get_overall_balance_should_return_balance();
  test_modify_account_status_should_return_error();
}

void test_search_account_by_id_should_return_not_found() {
  Response res = AccountController_search(0, "");

  assertTest("Pesquisa por id deve retornar nao encontrado", !res.status);
}

void test_search_account_by_id_should_return_found() {
  Response res = AccountController_search(1, "");

  assertTest("Pesquisa por id deve retornar encontrado", res.status);
}

void test_search_account_by_name_should_return_not_found() {
  Response res = AccountController_search(0, "-");

  assertTest("Pesquisa por nome deve retornar nao encontrado", !res.status);
}

void test_search_account_by_name_should_return_found() {
  Response res = AccountController_search(0, "matheus");

  assertTest("Pesquisa por nome deve retornar encontrado", res.status);
}

void test_if_balance_is_being_deposited() {
  Response res = AccountController_deposit(500, 1);
  assertTest("Novo saldo deve ser 10750", res.status);
}

void test_if_balance_is_not_being_deposited() {
  Response res = AccountController_deposit(-5, 1);
  assertTest("Deve retornar erro ao adicionar saldo", res.status);
}

void test_if_withdraw_was_made() {
  Response res = AccountController_withdraw(500, 1);
  assertTest("Novo saldo deve ser 10250", res.status);
}

void test_if_withdraw_was_not_made() {
  Response res = AccountController_withdraw(50000, 1);
  assertTest("Deve retornar erro ao sacar", res.status);
}

void test_create_account_should_create() {
  Account account = {473847, "Conta Teste", 1, 10.50, 0};

  Response res = AccountController_saveRecord(account);

  assertTest("Criar conta deve criar com sucesso", res.status = 1);
}

void test_get_overall_balance_should_return_balance() {
  Response res = AccountController_overallBalance();

  assertTest("Saldo geral deve retornar o saldo", res.status);
}

void test_modify_account_status_should_return_error() {
  Response res = AccountController_modifyAccountStatus(10000, 1);

  assertTest("Modificar status da conta deve retornar erro", !res.status);
}