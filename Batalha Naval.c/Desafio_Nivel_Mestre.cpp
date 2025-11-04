#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define NAVIO_VALOR 3
#define HABILIDADE_VALOR 5
#define HAB_TAM 5

// Função para exibir o tabuleiro com caracteres
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n   ");
    for (int j = 0; j < TAM; j++) printf("%2d", j);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA) printf("~ ");
            else if (tabuleiro[i][j] == NAVIO_VALOR) printf("# ");
            else if (tabuleiro[i][j] == HABILIDADE_VALOR) printf("* ");
        }
        printf("\n");
    }
}

// Função para criar matriz Cone
void criarCone(int cone[HAB_TAM][HAB_TAM]) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (j >= (HAB_TAM/2 - i) && j <= (HAB_TAM/2 + i)) cone[i][j] = 1;
            else cone[i][j] = 0;
        }
    }
}

// Função para criar matriz Cruz
void criarCruz(int cruz[HAB_TAM][HAB_TAM]) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (i == HAB_TAM/2 || j == HAB_TAM/2) cruz[i][j] = 1;
            else cruz[i][j] = 0;
        }
    }
}

// Função para criar matriz Octaedro
void criarOctaedro(int octaedro[HAB_TAM][HAB_TAM]) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (abs(HAB_TAM/2 - i) + abs(HAB_TAM/2 - j) <= HAB_TAM/2) octaedro[i][j] = 1;
            else octaedro[i][j] = 0;
        }
    }
}

// Função para aplicar habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HAB_TAM][HAB_TAM], int origemLinha, int origemColuna) {
    int offset = HAB_TAM / 2;
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha + (i - offset);
                int coluna = origemColuna + (j - offset);
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM && tabuleiro[linha][coluna] == AGUA) {
                    tabuleiro[linha][coluna] = HABILIDADE_VALOR;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa tabuleiro
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;

    // Posiciona navios (exemplo)
    for (int i = 0; i < NAVIO; i++) tabuleiro[2][4 + i] = NAVIO_VALOR; // horizontal
    for (int i = 0; i < NAVIO; i++) tabuleiro[5 + i][6] = NAVIO_VALOR; // vertical

    // Cria habilidades
    int cone[HAB_TAM][HAB_TAM], cruz[HAB_TAM][HAB_TAM], octaedro[HAB_TAM][HAB_TAM];
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 1);       // Cone no canto superior esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // Cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);  // Octaedro no canto inferior direito

    // Exibe tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}