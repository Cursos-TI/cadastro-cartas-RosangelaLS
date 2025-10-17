include <stdio.h>

int main() {
    // Definindo o número de casas para o movimento do Cavalo
    int casasBaixo = 2;
    int casasEsquerda = 1;

    // Movimento do Cavalo
    printf("\nMovimento do Cavalo:\n");

    // Loop for para mover para baixo
    for (int i = 0; i < casasBaixo; i++) {
        printf("Baixo\n");
    }

    // Loop while para mover para a esquerda
    int j = 0;
    while (j < casasEsquerda) {
        printf("Esquerda\n");
        j++;
    }

    return 0;
}
