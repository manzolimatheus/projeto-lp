#include "../../controllers/AccountController.h"
#include "../tests.h"

/*
  Função que agrupa todos os testes
  e os executa de uma só vez
*/
void AccountController_runTests();

void test_search_account_by_id_should_return_not_found();

void test_search_account_by_id_should_return_found();

void test_search_account_by_name_should_return_not_found();

void test_search_account_by_name_should_return_found();

void test_if_balance_is_being_deposited();

void test_if_balance_is_not_being_deposited();

void test_if_withdraw_was_made();

void test_if_withdraw_was_not_made();

void test_create_account_should_create();

void test_get_overall_balance_should_return_balance();

void test_modify_account_status_should_return_error();