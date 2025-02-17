#include "../include/investimento.h"
#include <time.h>

char dataAtual[11] = "28/01/2025";

float taxasIPCA[12] = {0.45, 0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 0.85, 0.90, 0.95, 1.00};

int diferencaDias(const char *dataInicio, const char *dataFim) {
    struct tm tmInicio = {0}, tmFim = {0};

    sscanf(dataInicio, "%d/%d/%d", &tmInicio.tm_mday, &tmInicio.tm_mon, &tmInicio.tm_year);
    tmInicio.tm_mon -= 1;
    tmInicio.tm_year -= 1900;

    sscanf(dataFim, "%d/%d/%d", &tmFim.tm_mday, &tmFim.tm_mon, &tmFim.tm_year);
    tmFim.tm_mon -= 1;
    tmFim.tm_year -= 1900;

    time_t tInicio = mktime(&tmInicio);
    time_t tFim = mktime(&tmFim);

    return (int)difftime(tFim, tInicio) / (60 * 60 * 24);
}

float calcularJurosPrefixado(Investimento *inv, int meses) {
    float taxaMensal = pow(1 + inv->taxaJuros / 100, 1.0 / 12) - 1;
    return inv->valorAplicado * pow(1 + taxaMensal, meses);
}

float calcularJurosIPCA(Investimento *inv, int meses) {
    float valor = inv->valorAplicado;
    for (int i = 0; i < meses; i++) {
        valor *= (1 + taxasIPCA[i % 12] / 100);
    }
    return valor;
}

float calcularJurosPeloTipo(Investimento *inv, int meses) {
    switch (inv->tipo) {
        case PREFIXADO:
            return calcularJurosPrefixado(inv, meses);
        case IPCA:
            return calcularJurosIPCA(inv, meses);
        default:
            return calcularJurosPrefixado(inv, meses);
    }
}

void atualizarInvestimento(Investimento *inv) {
    int meses = diferencaDias(inv->dataAplicacao, dataAtual) / 30;
    inv->valorBruto = calcularJurosPeloTipo(inv, meses);

    float impostoPercentual = 0;
    if (strcmp(inv->imposto, "IR") == 0) {
        if (meses <= 6) impostoPercentual = 0.225;
        else if (meses <= 12) impostoPercentual = 0.20;
        else if (meses <= 24) impostoPercentual = 0.175;
        else impostoPercentual = 0.15;
    }

    float valorImposto = (inv->valorBruto - inv->valorAplicado) * impostoPercentual;
    inv->valorLiquido = inv->valorBruto - valorImposto;
}
