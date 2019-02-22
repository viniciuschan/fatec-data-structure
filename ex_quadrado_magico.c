#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, soma_linha, soma_coluna, tamanho_matriz;
    int soma_diagonal_1 = 0, soma_diagonal_2 = 0;
    int soma_pivo = 0, quadrado_magico = 1;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanho_matriz);

    int matriz[tamanho_matriz][tamanho_matriz];

    // Alimenta matriz
    for (i = 0; i < tamanho_matriz; i++) {
        for (j = 0; j < tamanho_matriz; j++) {
            printf("Digite os números: ");
            scanf("%d", &matriz[i][j]);
        }
    }

    // Soma linha 1 para pivô da soma
    for (i = 0; i < tamanho_matriz; i++) {
        soma_pivo += matriz[i][0];
    }

    // Testa linhas
    for (i=0; i < tamanho_matriz; i++) {
        soma_linha = 0;
        for (j = 0; j < tamanho_matriz; j++) {
            soma_linha += matriz[i][j];
        }
        if (soma_linha != soma_pivo) {
            quadrado_magico = 0;
        }
    }

    // Testa colunas
    for (i = 0; i < tamanho_matriz; i++) {
        soma_coluna = 0;
        for (j = 0; j < tamanho_matriz; j++) {
            soma_coluna += matriz[i][j];
        }
        if (soma_coluna != soma_pivo) {
            quadrado_magico = 0;
        }
    }

    // Testa diagonal 1
    for (i = 0; i < tamanho_matriz; i++) {
        for (j = 0; j < tamanho_matriz; j++) {
            if (i == j) {
                soma_diagonal_1 += matriz[i][j];
            }
        }
    }
    if (soma_diagonal_1 != soma_pivo) {
        quadrado_magico = 0;
    }

    // Testa diagonal 2
    for (i = 0; i < tamanho_matriz; i++) {
        for (j = tamanho_matriz -1; j > -1; j--) {
            if (i == j) {
                soma_diagonal_2 += matriz[i][j];
            }
        }
    }
    if (soma_diagonal_2 != soma_pivo) {
        printf("TESTA DIAGONAL2 - %d soma local - %d soma pivo\n", soma_diagonal_2, soma_pivo);
        quadrado_magico = 0;
    }

    // Mostra matriz
    for (i = 0; i < tamanho_matriz; i++) {
        for ( j = 0; j < tamanho_matriz; j++) {
        printf("%3.d\t", matriz[i][j]);
        }
        printf("\n\n");
    }

    if (quadrado_magico == 1) {
        printf("\n\nÉ quadrado mágico!\n");
    } else {
        printf("\n\nNão é quadrado mágico!\n");
    }
    printf("\n\n");
    getchar();
    return 0;
}
