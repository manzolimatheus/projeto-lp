#pragma once
#include <stdio.h>
#include <unistd.h>

/*
  Função para exibir uma linha na tela
*/
void line();

// Função para exibir menu com base em uma lista de itens {string}
int outputMenu(char **words, int size);

// Função para limpar tela
void clearScreen(int seconds);

// Função para pausar a tela
void Utils_pause();
