#ifndef INVESTIMENTO_H
#define INVESTIMENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum {
    PREFIXADO,
    IPCA,
    SELIC,
    CDI
} TipoInvestimentoEnum;

typedef struct {
    char dataAplicacao[11];
    char dataVencimento[11];
    float valorAplicado;
    float taxaJuros;
    char imposto[10];
    char nome[50];
    TipoInvestimentoEnum tipo;
    float valorBruto;
    float valorLiquido;
} Investimento;

typedef float (*CalculoJurosFunc)(Investimento *, int);

int diferencaDias(const char *dataInicio, const char *dataFim);
void atualizarInvestimento(Investimento *inv);
float calcularJurosIPCA(Investimento *inv, int meses);
float calcularJurosPrefixado(Investimento *inv, int meses);
float calcularJurosPeloTipo(Investimento *inv, int meses);

#endif
