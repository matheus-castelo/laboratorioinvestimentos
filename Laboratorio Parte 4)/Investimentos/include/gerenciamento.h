#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

#include "investimento.h"

#define MAX_INVESTIMENTOS 100

void criarInvestimento(Investimento *inv);
void exibirInvestimentos(Investimento investimentos[], int quantidadeInvestimentos);
void editarInvestimento(Investimento investimentos[], int quantidadeInvestimentos);
void deletarInvestimento(Investimento investimentos[], int *quantidadeInvestimentos);
void salvarInvestimentos(Investimento investimentos[], int quantidadeInvestimentos, const char *arquivo);
int carregarInvestimentos(Investimento investimentos[], const char *arquivo);

#endif
