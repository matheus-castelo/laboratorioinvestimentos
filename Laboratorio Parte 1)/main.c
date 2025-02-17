#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INVESTIMENTOS 100  

// QUESTÃO 1
typedef struct {
    char data[11];
    float valor;
    char tipo[50];
    char nome[50];
} Investimento;

// QUESTÃO 1
void criarInvestimento(Investimento *inv) {
    printf("Digite a data (dd/mm/aaaa): ");
    scanf("%s", inv->data);
    printf("Digite o valor: ");
    scanf("%f", &inv->valor);
    printf("Digite o tipo do investimento: ");
    scanf("%s", inv->tipo);
    printf("Digite o nome do investimento: ");
    scanf("%s", inv->nome);
}
// QUESTÃO 2
void exibirInvestimentos(Investimento investimentos[], int quantidadeInvestimentos) {
    printf("\nInvestimentos cadastrados:\n");
    printf("Data\t\tValor\t\tTipo\t\tNome\n");
    printf("---------------------------------------------------------------\n");
    
    for (int i = 0; i < quantidadeInvestimentos; i++) {
        printf("%s\t%.2f\t\t%s\t\t%s\n", investimentos[i].data, investimentos[i].valor, investimentos[i].tipo, investimentos[i].nome);
    }
}

// QUESTÃO 3
void ordenarPorTipo(Investimento investimentos[], int quantidadeInvestimentos) {
    Investimento temp;
    for (int i = 0; i < quantidadeInvestimentos - 1; i++) {
        for (int j = i + 1; j < quantidadeInvestimentos; j++) {
            if (strcmp(investimentos[i].tipo, investimentos[j].tipo) > 0) {
                temp = investimentos[i];
                investimentos[i] = investimentos[j];
                investimentos[j] = temp;
            }
        }
    }
    printf("\nInvestimentos ordenados por tipo.\n");
}

// QUESTÃO 3
void ordenarPorValor(Investimento investimentos[], int quantidadeInvestimentos) {
    Investimento temp;
    for (int i = 0; i < quantidadeInvestimentos - 1; i++) {
        for (int j = i + 1; j < quantidadeInvestimentos; j++) {
            if (investimentos[i].valor > investimentos[j].valor) {
                temp = investimentos[i];
                investimentos[i] = investimentos[j];
                investimentos[j] = temp;
            }
        }
    }
    printf("\nInvestimentos ordenados por valor.\n");
}

int main() { 
    int inputUsuario = 0;
    int quantidadeInvestimentos = 0;
    Investimento investimentos[MAX_INVESTIMENTOS];  
    do {
        puts("Digite 1 para criar um novo investimento, 2 para exibir os investimentos, 3 para ordenar por tipo, 4 para ordenar por valor, ou 13 para sair.");
        scanf("%d", &inputUsuario);

        if (inputUsuario == 1) {
            if (quantidadeInvestimentos < MAX_INVESTIMENTOS) {
                criarInvestimento(&investimentos[quantidadeInvestimentos]);  
                quantidadeInvestimentos++;
                printf("Investimento criado com sucesso!\n");
            } else {
                printf("Não é possível criar mais investimentos. Limite atingido!\n");
            }
        } else if (inputUsuario == 2) {
            exibirInvestimentos(investimentos, quantidadeInvestimentos);  
        } else if (inputUsuario == 3) {
            ordenarPorTipo(investimentos, quantidadeInvestimentos);  
            exibirInvestimentos(investimentos, quantidadeInvestimentos);  
        } else if (inputUsuario == 4) {
            ordenarPorValor(investimentos, quantidadeInvestimentos);  
            exibirInvestimentos(investimentos, quantidadeInvestimentos);  
        }

    } while(inputUsuario != 13);

    return 0;
}
