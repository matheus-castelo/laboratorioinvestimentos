#include "../include/gerenciamento.h"
#include <stdio.h>
#include <stdlib.h>

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
    printf("\nLista de Investimentos:\n");
    printf("Data Aplicação | Data Vencimento | Valor Aplicado | Tipo | Valor Bruto | Valor Líquido\n");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < quantidadeInvestimentos; i++) {
        atualizarInvestimento(&investimentos[i]);
        printf("%s | %s | %.2f | %d | %.2f | %.2f\n",
               investimentos[i].dataAplicacao,
               investimentos[i].dataVencimento,
               investimentos[i].valorAplicado,
               investimentos[i].tipo,
               investimentos[i].valorBruto,
               investimentos[i].valorLiquido);
    }
}

void editarInvestimento(Investimento investimentos[], int quantidadeInvestimentos) {
    int id;
    printf("Digite o número do investimento a ser editado (0-%d): ", quantidadeInvestimentos - 1);
    scanf("%d", &id);

    if (id < 0 || id >= quantidadeInvestimentos) {
        printf("Investimento inválido!\n");
        return;
    }

    printf("Editando investimento %d...\n", id);
    criarInvestimento(&investimentos[id]);
}

void deletarInvestimento(Investimento investimentos[], int *quantidadeInvestimentos) {
    int id;
    printf("Digite o número do investimento a ser deletado (0-%d): ", *quantidadeInvestimentos - 1);
    scanf("%d", &id);

    if (id < 0 || id >= *quantidadeInvestimentos) {
        printf("Investimento inválido!\n");
        return;
    }

    for (int i = id; i < *quantidadeInvestimentos - 1; i++) {
        investimentos[i] = investimentos[i + 1];
    }
    
    (*quantidadeInvestimentos)--;
    printf("Investimento deletado!\n");
}

void salvarInvestimentos(Investimento investimentos[], int quantidadeInvestimentos, const char *arquivo) {
    FILE *fp = fopen(arquivo, "wb");
    if (!fp) {
        printf("Erro ao salvar os investimentos!\n");
        return;
    }
    fwrite(&quantidadeInvestimentos, sizeof(int), 1, fp);
    fwrite(investimentos, sizeof(Investimento), quantidadeInvestimentos, fp);
    fclose(fp);
}

int carregarInvestimentos(Investimento investimentos[], const char *arquivo) {
    FILE *fp = fopen(arquivo, "rb");
    if (!fp) {
        printf("Nenhum investimento salvo anteriormente.\n");
        return 0;
    }

    int quantidade;
    fread(&quantidade, sizeof(int), 1, fp);
    fread(investimentos, sizeof(Investimento), quantidade, fp);
    fclose(fp);

    printf("%d investimentos carregados com sucesso!\n", quantidade);
    return quantidade;
}
