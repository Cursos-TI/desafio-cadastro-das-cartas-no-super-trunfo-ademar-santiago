#include <stdio.h>
#include <string.h>

int main() {
    // Dados das cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;

    // Entrada dos dados da Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código: ");
    scanf("%s", codigo1);
    printf("Nome da cidade: ");
    getchar();
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0';
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos1);

    // Entrada dos dados da Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código: ");
    scanf("%s", codigo2);
    printf("Nome da cidade: ");
    getchar();
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0';
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos2);

    // Cálculos
    float densidade1 = (float)populacao1 / area1;
    float densidade2 = (float)populacao2 / area2;

    float pibPerCapita1 = (pib1 * 1000000000.0) / (float)populacao1;
    float pibPerCapita2 = (pib2 * 1000000000.0) / (float)populacao2;

    float superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontos1 + pibPerCapita1 + (1.0 / densidade1);
    float superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontos2 + pibPerCapita2 + (1.0 / densidade2);

    // Comparações (1 = Carta 1 venceu, 0 = Carta 2 venceu)
    int venceuPopulacao = (populacao1 > populacao2) ? 1 : 0;
    int venceuArea = (area1 > area2) ? 1 : 0;
    int venceuPib = (pib1 > pib2) ? 1 : 0;
    int venceuPontos = (pontos1 > pontos2) ? 1 : 0;
    int venceuDensidade = (densidade1 < densidade2) ? 1 : 0; // menor vence
    int venceuPibPerCapita = (pibPerCapita1 > pibPerCapita2) ? 1 : 0;
    int venceuSuperPoder = (superPoder1 > superPoder2) ? 1 : 0;

    // Resultado
    printf("\n=== Comparação de Cartas ===\n");
    printf("População: Carta 1 venceu (%d)\n", venceuPopulacao);
    printf("Área: Carta 1 venceu (%d)\n", venceuArea);
    printf("PIB: Carta 1 venceu (%d)\n", venceuPib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", venceuPontos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", venceuDensidade);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", venceuPibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", venceuSuperPoder);

    return 0;
}
