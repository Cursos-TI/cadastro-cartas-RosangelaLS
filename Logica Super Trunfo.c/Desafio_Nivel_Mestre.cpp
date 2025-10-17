#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para calcular densidade demográfica
void calcularDensidade(struct Carta *carta) {
    carta->densidadeDemografica = carta->populacao / carta->area;
}

// Função para exibir os atributos disponíveis
void exibirMenu(int ignorar) {
    printf("Escolha um atributo para comparar:\n");
    if (ignorar != 1) printf("1 - População\n");
    if (ignorar != 2) printf("2 - Área\n");
    if (ignorar != 3) printf("3 - PIB\n");
    if (ignorar != 4) printf("4 - Pontos Turísticos\n");
    if (ignorar != 5) printf("5 - Densidade Demográfica\n");
}

int main() {
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 1860.0, 30};
    struct Carta carta2 = {"Argentina", 45380000, 2780400.0, 640.0, 20};

    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int atributo1, atributo2;
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;

    printf("=== SUPER TRUNFO - NÍVEL MESTRE ===\n\n");

    // Escolha do primeiro atributo
    exibirMenu(0);
    printf("Digite o número do primeiro atributo: ");
    scanf("%d", &atributo1);

    // Escolha do segundo atributo (sem repetir o primeiro)
    printf("\nAgora escolha o segundo atributo:\n");
    exibirMenu(atributo1);
    printf("Digite o número do segundo atributo: ");
    scanf("%d", &atributo2);

    // Função auxiliar para obter valor do atributo
    float obterValor(struct Carta c, int atributo) {
        switch (atributo) {
            case 1: return c.populacao;
            case 2: return c.area;
            case 3: return c.pib;
            case 4: return c.pontosTuristicos;
            case 5: return c.densidadeDemografica;
            default: return 0;
        }
    }

    // Obter valores dos atributos escolhidos
    valor1_c1 = obterValor(carta1, atributo1);
    valor1_c2 = obterValor(carta2, atributo1);
    valor2_c1 = obterValor(carta1, atributo2);
    valor2_c2 = obterValor(carta2, atributo2);

    // Exibir valores
    printf("\nComparando %s e %s...\n\n", carta1.pais, carta2.pais);
    printf("Atributo 1: ");
    switch (atributo1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", carta1.pais, valor1_c1, carta2.pais, valor1_c2);

    printf("Atributo 2: ");
    switch (atributo2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", carta1.pais, valor2_c1, carta2.pais, valor2_c2);

    // Ajustar valores para densidade (menor é melhor)
    valor1_c1 = (atributo1 == 5) ? -valor1_c1 : valor1_c1;
    valor1_c2 = (atributo1 == 5) ? -valor1_c2 : valor1_c2;
    valor2_c1 = (atributo2 == 5) ? -valor2_c1 : valor2_c1;
    valor2_c2 = (atributo2 == 5) ? -valor2_c2 : valor2_c2;

    // Soma dos atributos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.pais, soma_c1);
    printf("%s: %.2f\n", carta2.pais, soma_c2);

    // Resultado final
    printf("\nResultado: ");
    (soma_c1 > soma_c2) ? printf("%s venceu!\n", carta1.pais) :
    (soma_c2 > soma_c1) ? printf("%s venceu!\n", carta2.pais) :
    printf("Empate!\n");

    return 0;
}