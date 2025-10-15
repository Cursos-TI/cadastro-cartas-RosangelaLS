#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta
struct Carta {
    char estado[30];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular os valores derivados
void calcularIndicadores(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir os dados da carta
void exibirCarta(struct Carta carta) {
    printf("Cidade: %s (%s)\n", carta.cidade, carta.estado);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("-----------------------------\n");
}

int main() {
    // Cadastro das cartas
    struct Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 799.0, 25};
    struct Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6710000, 1182.30, 411.0, 18};

    // Cálculo dos indicadores
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibição das cartas
    printf("=== Carta 1 ===\n");
    exibirCarta(carta1);
    printf("=== Carta 2 ===\n");
    exibirCarta(carta2);

    // Comparação por PIB per capita
    printf("Comparação de cartas (Atributo: PIB per capita):\n\n");
    printf("Carta 1 - %s (%.2f)\n", carta1.cidade, carta1.pibPerCapita);
    printf("Carta 2 - %s (%.2f)\n", carta2.cidade, carta2.pibPerCapita);

    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}