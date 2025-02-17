#include "../include/gerenciamento.h"

void criarInvestimento(Investimento *inv) {
    printf("Digite a data de aplicação (dd/mm/aaaa): ");
    scanf("%s", inv->dataAplicacao);
    printf("Digite a data de vencimento (dd/mm/aaaa): ");
    scanf("%s", inv->dataVencimento);
    printf("Digite o valor aplicado: ");
    scanf("%f", &inv->valorAplicado);
    printf("Digite a taxa de juros anual (em %%): ");
    scanf("%f", &inv->taxaJuros);
    printf("Digite o tipo de imposto: ");
    scanf("%s", inv->imposto);
    printf("Digite o nome do investimento: ");
    scanf("%s", inv->nome);
    printf("Escolha o tipo de investimento (0: Prefixado, 1: IPCA+, 2: Selic, 3: CDI): ");
    int tipo;
    scanf("%d", &tipo);
    inv->tipo = (TipoInvestimentoEnum)tipo;

    inv->valorBruto = inv->valorAplicado;
    inv->valorLiquido = inv->valorAplicado;
}

void exibirInvestimentos(Investimento investimentos[], int quantidadeInvestimentos) {
    printf("\nInvestimentos cadastrados:\n");
    printf("Data Aplicacao\tData Vencimento\tValor Aplicado\tValor Bruto\tValor Liquido\n");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < quantidadeInvestimentos; i++) {
        atualizarInvestimento(&investimentos[i]);
        printf("%s\t%s\t%.2f\t%.2f\t%.2f\n",
               investimentos[i].dataAplicacao,
               investimentos[i].dataVencimento,
               investimentos[i].valorAplicado,
               investimentos[i].valorBruto,
               investimentos[i].valorLiquido);
    }
}

void exibirValorBrutoTotal(Investimento investimentos[], int quantidadeInvestimentos) {
    float totalBruto = 0;
    for (int i = 0; i < quantidadeInvestimentos; i++) {
        atualizarInvestimento(&investimentos[i]);
        totalBruto += investimentos[i].valorBruto;
    }
    printf("\nValor bruto total: %.2f\n", totalBruto);
}

void exibirValorLiquidoTotal(Investimento investimentos[], int quantidadeInvestimentos) {
    float totalLiquido = 0;
    for (int i = 0; i < quantidadeInvestimentos; i++) {
        atualizarInvestimento(&investimentos[i]);
        totalLiquido += investimentos[i].valorLiquido;
    }
    printf("\nValor líquido total: %.2f\n", totalLiquido);
}
