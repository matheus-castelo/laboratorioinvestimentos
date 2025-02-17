#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

#include "investimento.h"

#define MAX_INVESTIMENTOS 100

void criarInvestimento(Investimento *inv);
void exibirInvestimentos(Investimento investimentos[], int quantidadeInvestimentos);
void exibirValorBrutoTotal(Investimento investimentos[], int quantidadeInvestimentos);
void exibirValorLiquidoTotal(Investimento investimentos[], int quantidadeInvestimentos);

#endif
