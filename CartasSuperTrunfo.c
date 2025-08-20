#include <stdio.h>
#include <string.h>

// Estrutura de carta
typedef struct {
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

int main() {
    // Cartas pré-cadastradas
    Carta c1 = {"Brasil", 214000000, 8516000, 18470, 50, 0, 0};
    Carta c2 = {"Argentina", 46000000, 2780000, 640, 20, 0, 0};

    // Calculando atributos derivados
    c1.densidade = (float)c1.populacao / c1.area;
    c2.densidade = (float)c2.populacao / c2.area;

    c1.pibPerCapita = (c1.pib * 1000000000.0) / (float)c1.populacao;
    c2.pibPerCapita = (c2.pib * 1000000000.0) / (float)c2.populacao;

    // Menu de atributos
    int escolha1, escolha2;

    printf("=== Super Trunfo - Comparação de Cartas ===\n");
    printf("Carta 1: %s\n", c1.nome);
    printf("Carta 2: %s\n\n", c2.nome);

    printf("Escolha o PRIMEIRO atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    scanf("%d", &escolha1);

    // Menu dinâmico para o segundo atributo
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != escolha1) {
            switch(i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Populacional\n"); break;
                case 6: printf("6 - PIB per Capita\n"); break;
            }
        }
    }
    scanf("%d", &escolha2);

    // Função auxiliar para pegar valor do atributo
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;

    switch (escolha1) {
        case 1: valor1_c1 = c1.populacao; valor1_c2 = c2.populacao; break;
        case 2: valor1_c1 = c1.area; valor1_c2 = c2.area; break;
        case 3: valor1_c1 = c1.pib; valor1_c2 = c2.pib; break;
        case 4: valor1_c1 = c1.pontosTuristicos; valor1_c2 = c2.pontosTuristicos; break;
        case 5: valor1_c1 = c1.densidade; valor1_c2 = c2.densidade; break;
        case 6: valor1_c1 = c1.pibPerCapita; valor1_c2 = c2.pibPerCapita; break;
    }

    switch (escolha2) {
        case 1: valor2_c1 = c1.populacao; valor2_c2 = c2.populacao; break;
        case 2: valor2_c1 = c1.area; valor2_c2 = c2.area; break;
        case 3: valor2_c1 = c1.pib; valor2_c2 = c2.pib; break;
        case 4: valor2_c1 = c1.pontosTuristicos; valor2_c2 = c2.pontosTuristicos; break;
        case 5: valor2_c1 = c1.densidade; valor2_c2 = c2.densidade; break;
        case 6: valor2_c1 = c1.pibPerCapita; valor2_c2 = c2.pibPerCapita; break;
    }

    // Comparação dos dois atributos
    int resultado1, resultado2;

    // Regra especial para densidade: menor vence
    resultado1 = (escolha1 == 5) ? (valor1_c1 < valor1_c2 ? 1 : 0) : (valor1_c1 > valor1_c2 ? 1 : 0);
    resultado2 = (escolha2 == 5) ? (valor2_c1 < valor2_c2 ? 1 : 0) : (valor2_c1 > valor2_c2 ? 1 : 0);

    // Soma dos atributos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    // Exibição dos resultados
    printf("\n=== Resultado da Comparação ===\n");
    printf("%s - Atributo 1: %.2f | Atributo 2: %.2f | Soma: %.2f\n", c1.nome, valor1_c1, valor2_c1, soma_c1);
    printf("%s - Atributo 1: %.2f | Atributo 2: %.2f | Soma: %.2f\n", c2.nome, valor1_c2, valor2_c2, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("\nVencedor: %s!\n", c1.nome);
    } else if (soma_c2 > soma_c1) {
        printf("\nVencedor: %s!\n", c2.nome);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}

