#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define NAVIO_VALOR 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se pode posicionar navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha, c = coluna;
        if (diagonal == 1) { // diagonal ↘
            l += i; c += i;
        } else if (diagonal == 2) { // diagonal ↙
            l += i; c -= i;
        } else if (direcao == 0) { // horizontal
            c += i;
        } else { // vertical
            l += i;
        }
        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != AGUA) {
            return 0; // inválido
        }
    }
    return 1; // válido
}

// Função para posicionar navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha, c = coluna;
        if (diagonal == 1) { // diagonal ↘
            l += i; c += i;
        } else if (diagonal == 2) { // diagonal ↙
            l += i; c -= i;
        } else if (direcao == 0) { // horizontal
            c += i;
        } else { // vertical
            l += i;
        }
        tabuleiro[l][c] = NAVIO_VALOR;
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa tabuleiro
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;

    // Coordenadas dos navios
    int navios[4][4] = {
        {2, 4, 0, 0}, // horizontal
        {5, 6, 1, 0}, // vertical
        {0, 0, 0, 1}, // diagonal ↘
        {0, 9, 0, 2}  // diagonal ↙
    };

    // Posiciona navios
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int direcao = navios[i][2];
        int diagonal = navios[i][3];

        if (podePosicionar(tabuleiro, linha, coluna, direcao, diagonal)) {
            posicionarNavio(tabuleiro, linha, coluna, direcao, diagonal);
        } else {
            printf("Erro ao posicionar navio %d!\n", i + 1);
        }
    }

    // Exibe tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}