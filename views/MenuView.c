#include "./MenuView.h"

void menu() {
  int opcao = 0;
  int selectedOption;

  do {
    // system("cls");
    line();
    printf("\n");
    system("toilet -f smblock BANK AGENT --filter border:metal");
    line();

    char *options[] = {"Cadastrar Conta",
                       "Atualizar Conta",
                       "Procurar Conta",
                       "Deposito em Conta",
                       "Saque em Conta",
                       "Listar Contas",
                       "Saldo Geral",
                       "Desabilitar/Habilitar Conta",
                       "Exibir registros excluidos",
                       "Creditos",
                       "Sair"};

    int selectedOption = outputMenu(options, 11);
    switch (selectedOption) {
    case 1:
      AccountView_saveRecord();
      break;
    case 2:
      AccountView_modifyAccount();
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
      AccountView_showRecords();
      break;
    case 7:
      AccountView_overallBalance();
      break;
    case 8:
      AccountView_modifyStatusAccount();
      break;
    case 9:
      AccountView_showTrashCan();
      break;
    case 10:
      MenuView_showCredits();
      break;
    case 11:
      printf("Fim do programa \n");
      exit(1);
      break;
    }
  } while (opcao != 11);
}

void MenuView_showCredits() {
  clearScreen(1);
  system("cowsay 'Feito com <3 por: Guilherme Ronha, Matheus Biazotto, Matheus "
         "Manzoli, Raíne Felix, Tiago Sorato - @2022'");
  Utils_pause();
}