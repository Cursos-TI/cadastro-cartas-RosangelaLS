#include <stdio.h>

// Função recursiva para movimentar a Torre (vertical)
void moverTorre(int casas) {
    if (casas <= 0) return;
    printf("Cima\n");
    moverTorre(casas - 1);
}

// Função recursiva para movimentar a Rainha (horizontal)
void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverRainha(casas - 1);
}

// Função recursiva + loops aninhados para o Bispo (diagonal)
void moverBispo(int casas) {
    if (casas <= 0) return;

    for (int i = 0; i < casas; i++) {
        for (int j = 0; j < casas; j++) {
            if (i == j) {
                printf("Diagonal: Cima + Direita\n");
            }
        }
    }

    moverBispo(casas - 1);
}

// Função com loops complexos para o Cavalo (2 para cima, 1 para direita)
void moverCavalo() {
    int movimentosVerticais = 2;
    int movimentosHorizontais = 1;

    printf("\nMovimento do Cavalo:\n");

    for (int i = 0; i < movimentosVerticais; i++) {
        if (i == 1) {
            printf("Cima\n");
            continue;
        }

        for (int j = 0; j < movimentosHorizontais; j++) {
            if (j == 0) {
                printf("Cima\n");
                printf("Direita\n");
                break;
            }
        }
    }
}

int main() {
    int casasTorre = 3;
    int casasRainha = 3;
    int casasBispo = 3;

    // Movimento da Torre
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);

    // Separação visual
    printf("\n");

    // Movimento da Rainha
    printf("Movimento da Rainha:\n");
    moverRainha(casasRainha);

    // Separação visual
    printf("\n");

    // Movimento do Bispo
    printf("Movimento do Bispo:\n");
    moverBispo(casasBispo);

    // Separação visual
    printf("\n");

    // Movimento do Cavalo
    moverCavalo();

    return 0;
}