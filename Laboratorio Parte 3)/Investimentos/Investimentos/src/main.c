#include "../include/gerenciamento.h"

int main() {
    int inputUsuario = 0;
    int quantidadeInvestimentos = 0;
    Investimento investimentos[MAX_INVESTIMENTOS];

    do {
        puts("1 - Criar Investimento, 2 - Exibir Investimentos, 3 - Valor Bruto Total, 4 - Valor Líquido Total, 13 - Sair.");
        scanf("%d", &inputUsuario);

        if (inputUsuario == 1) {
            if (quantidadeInvestimentos < MAX_INVESTIMENTOS) {
                criarInvestimento(&investimentos[quantidadeInvestimentos]);
                quantidadeInvestimentos++;
                printf("Investimento criado!\n");
            } else {
                printf("Limite de investimentos atingido!\n");
            }
        } else if (inputUsuario == 2) {
            exibirInvestimentos(investimentos, quantidadeInvestimentos);
        } else if (inputUsuario == 3) {
            exibirValorBrutoTotal(investimentos, quantidadeInvestimentos);
        } else if (inputUsuario == 4) {
            exibirValorLiquidoTotal(investimentos, quantidadeInvestimentos);
        }
    } while (inputUsuario != 13);

    return 0;
}
