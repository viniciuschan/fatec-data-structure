#include <stdio.h>
#include <stdlib.h>

int main() {
    int lin, col, i, j, tamanho_matriz;
    int soma_linha, soma_coluna;
    int soma_diag1 = 0, soma_diag2 = 0;
    int soma = 0, quadrado_magico = 1;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &lin);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &col);

    if (lin != col) {
        printf("A matriz precisa ser quadrada, tente novamente!");
        exit(0);
    }

    int matriz[lin][col];

    // Alimenta matriz
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("Digite os números: ");
            scanf("%d", &matriz[i][j]);
        }
    }

    // Soma linha 1 para pivô da soma
    for (i = 0; i < lin; i++) {
        soma += matriz[i][0];
    }

    // Testa linhas
    for (i=0; i < lin; i++) {
        soma_linha = 0;
        for (j = 0; j < col; j++) {
            soma_linha += matriz[0][j];
        }
        if (soma_linha != soma) {
            quadrado_magico = 0;
        }
    }

    // Testa colunas
    for (i = 0; i < col; i++) {
        soma_coluna = 0;
        for (j = 0; j < col; j++) {
            soma_coluna += matriz[i][0];
        }
        if (soma_coluna != soma) {
            quadrado_magico = 0;
        }
    }

    // Testa diagonal 1
    for (i = 0; i < col; i++) {
        soma_diag1 = 0;
        for (j = 0; j < col; j++) {
            if (i == j) {
                soma_diag1 += matriz[i][j];
            }
        }
        if (soma_diag1 != soma) {
            quadrado_magico = 0;
        }
    }

    // Testa diagonal 2
    for (i = 0; i < col; i++) {
        soma_diag2 = 0;
        for (j = col - 1; j > -1; j--) {
            soma_diag2 += matriz[i][j];
        }
        if (soma_diag1 != soma) {
            quadrado_magico = 0;
        }
    }

    // Mostra matriz
    for (i=0; i<lin; i++) {
        for (j=0; j<col;j++) {
        printf("%3.d\t",matriz[i][j]);
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
