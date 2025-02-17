#include "../include/gerenciamento.h"
#include <stdio.h>
#include <stdlib.h>

#define ARQUIVO_INVESTIMENTOS "investimentos.dat"

int main() {
    int inputUsuario = 0;
    int quantidadeInvestimentos = 0;
    Investimento investimentos[MAX_INVESTIMENTOS];

    
    quantidadeInvestimentos = carregarInvestimentos(investimentos, ARQUIVO_INVESTIMENTOS);
    
    do {
        puts("\n1 - Criar Investimento\n2 - Editar Investimento\n3 - Exibir Investimentos");
        puts("4 - Deletar Investimento\n5 - Salvar e Sair");
        printf("Escolha uma opção: ");
        scanf("%d", &inputUsuario);
        getchar();  

        if (inputUsuario == 1) {
            if (quantidadeInvestimentos < MAX_INVESTIMENTOS) {
                criarInvestimento(&investimentos[quantidadeInvestimentos]);
                quantidadeInvestimentos++;
                printf("Investimento criado!\n");
            } else {
                printf("Limite de investimentos atingido!\n");
            }
        } 
        else if (inputUsuario == 2) {
            editarInvestimento(investimentos, quantidadeInvestimentos);
        }
        else if (inputUsuario == 3) {
            exibirInvestimentos(investimentos, quantidadeInvestimentos);
        } 
        else if (inputUsuario == 4) {
            deletarInvestimento(investimentos, &quantidadeInvestimentos);
        }
    } while (inputUsuario != 5);

    
    salvarInvestimentos(investimentos, quantidadeInvestimentos, ARQUIVO_INVESTIMENTOS);
    printf("Investimentos salvos. Saindo do programa...\n");

    return 0;
}
