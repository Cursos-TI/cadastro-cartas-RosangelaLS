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

// Função para exibir os dados da carta
void exibirCarta(struct Carta carta) {
    printf("País: %s\n", carta.pais);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidadeDemografica);
    printf("-----------------------------\n");
}

int main() {
    // Cartas pré-definidas
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 1860.0, 30};
    struct Carta carta2 = {"Argentina", 45380000, 2780400.0, 640.0, 20};

    // Cálculo da densidade
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int opcao;

    // Menu interativo
    printf("=== SUPER TRUNFO - COMPARAÇÃO DE PAÍSES ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    printf("\nComparando %s e %s...\n\n", carta1.pais, carta2.pais);

    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d\n", carta1.pais, carta1.populacao);
            printf("%s: %d\n", carta2.pais, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.pais, carta1.area);
            printf("%s: %.2f km²\n", carta2.pais, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", carta1.pais, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.pais, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", carta1.pais, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.pais, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.pais, carta1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", carta2.pais, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Por favor, escolha um número de 1 a 5.\n");
    }

    return 0;
}