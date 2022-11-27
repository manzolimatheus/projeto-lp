#include "./MenuView.h"

void menu() {
  int opcao = 0;
  do {
    // system("cls");
    line();
    printf("\nBanco Fatec \n");
    line();
    printf("1. Cadastrar Conta\n");
    printf("2. Atualizar Conta\n");
    printf("3. Procurar Conta\n");
    printf("4. Deposito em Conta\n");
    printf("5. Saque em Conta\n");
    printf("6. Listar Contas\n");
    printf("7. Saldo Total de Contas \n");
    printf("8. Sair \n");
    printf("Digite sua opcao:  \n");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      AccountView_saveRecord();
      break;
    case 2:
      printf("\nWork in progress...");
      break;
    case 3:
      AccountView_searchAccount();
      break;
    case 4:
      AccountView_depositValue();
      break;
    case 5:
      AccountView_withdrawValue();
      break;
    case 6:
      printf("\nWork in progress...");
      break;
    case 7:
      printf("\nWork in progress...");
      break;
    case 8:
      printf("Fim do programa \n");
      break;
    default:
      printf("\nOpcao invalida!");
      break;
    }
  } while (opcao != 8);
}