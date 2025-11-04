#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define NAVIO_VALOR 3

int main() {
    int tabuleiro[TAM][TAM];
    int navioHorizontal[NAVIO] = {NAVIO_VALOR, NAVIO_VALOR, NAVIO_VALOR};
    int navioVertical[NAVIO] = {NAVIO_VALOR, NAVIO_VALOR, NAVIO_VALOR};

    // Inicializa tabuleiro com água
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais dos navios (definidas no código)
    int linhaHorizontal = 2, colunaHorizontal = 4; // Navio horizontal
    int linhaVertical = 5, colunaVertical = 6;     // Navio vertical

    // Validação simples para não ultrapassar limites
    if (colunaHorizontal + NAVIO <= TAM && linhaVertical + NAVIO <= TAM) {
        // Posiciona navio horizontal
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }

        // Posiciona navio vertical (verifica sobreposição)
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == AGUA) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            } else {
                printf("Erro: sobreposição detectada!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: coordenadas inválidas!\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}