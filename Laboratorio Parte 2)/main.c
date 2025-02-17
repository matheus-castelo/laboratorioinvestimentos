#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INVESTIMENTOS 100

// QUESTÃO 3
typedef enum {
    PREFIXADO,
    IPCA,
    SELIC,
    CDI
} TipoInvestimentoEnum;

const char *tipoInvestimentoStr[] = {"Prefixado", "IPCA+", "Selic", "CDI"};

//  QUESTÃO 1
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

// QUESTÃO 2
char dataAtual[11] = "28/01/2025";

// QUESTÃO 2
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


void atualizarInvestimento(Investimento *inv) {
    int dias = diferencaDias(inv->dataAplicacao, dataAtual);
    float taxaDiaria = pow(1 + inv->taxaJuros / 100, 1.0 / 365) - 1;

    
    inv->valorBruto = inv->valorAplicado * pow(1 + taxaDiaria, dias);

    float impostoPercentual = 0;
    if (strcmp(inv->imposto, "IR") == 0) {
        if (dias <= 180) impostoPercentual = 0.225;
        else if (dias <= 360) impostoPercentual = 0.20;
        else if (dias <= 720) impostoPercentual = 0.175;
        else impostoPercentual = 0.15;
    }

    float valorImposto = (inv->valorBruto - inv->valorAplicado) * impostoPercentual;
    inv->valorLiquido = inv->valorBruto - valorImposto;
}

// QUESTÃO 2 e 3
void exibirInvestimentos(Investimento investimentos[], int quantidadeInvestimentos) {
    printf("\nInvestimentos cadastrados:\n");
    printf("Data Aplicacao\tData Vencimento\tValor Aplicado\tTipo\tValor Bruto\tValor Liquido\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < quantidadeInvestimentos; i++) {
        atualizarInvestimento(&investimentos[i]); 
        printf("%s\t%s\t%.2f\t%s\t%.2f\t%.2f\n",
               investimentos[i].dataAplicacao,
               investimentos[i].dataVencimento,
               investimentos[i].valorAplicado,
               tipoInvestimentoStr[investimentos[i].tipo],
               investimentos[i].valorBruto,
               investimentos[i].valorLiquido);
    }
}

// QUESTÃO 3
void exibirValorBrutoTotal(Investimento investimentos[], int quantidadeInvestimentos) {
    float totalBruto = 0;
    for (int i = 0; i < quantidadeInvestimentos; i++) {
        atualizarInvestimento(&investimentos[i]);
        totalBruto += investimentos[i].valorBruto;
    }
    printf("\nValor bruto total: %.2f\n", totalBruto);
}

// QUESTÃO 3
void exibirValorLiquidoTotal(Investimento investimentos[], int quantidadeInvestimentos) {
    float totalLiquido = 0;
    for (int i = 0; i < quantidadeInvestimentos; i++) {
        atualizarInvestimento(&investimentos[i]);
        totalLiquido += investimentos[i].valorLiquido;
    }
    printf("\nValor líquido total: %.2f\n", totalLiquido);
}

int main() {
    int inputUsuario = 0;
    int quantidadeInvestimentos = 0;
    Investimento investimentos[MAX_INVESTIMENTOS];

    do {
        puts("Digite 1 para criar um novo investimento, 2 para exibir os investimentos, 3 para exibir o valor bruto total, 4 para exibir o valor líquido total, ou 13 para sair.");
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
            exibirValorBrutoTotal(investimentos, quantidadeInvestimentos);
        } else if (inputUsuario == 4) {
            exibirValorLiquidoTotal(investimentos, quantidadeInvestimentos);
        }

    } while (inputUsuario != 13);

    return 0;
}
