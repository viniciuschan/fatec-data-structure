#include <stdio.h>
#include <stdlib.h>

int main() {
    int lin, col, i, j, tamanho_matriz;
    int soma_linha, soma_coluna;
    int soma_diag1 = 0, soma_diag2 = 0;
    int soma = 0, quadrado_magico = 1;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanho_matriz);
    int matriz[tamanho_matriz][tamanho_matriz];

    // Alimenta matriz
    for(i = 0; i < tamanho_matriz; i++){
        for(j = 0; j < tamanho_matriz; j++){
            printf("Digite os números: ");
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // Soma coluna1
    for(i = 0; i < col; i++){
        soma += matriz[i][0];
    }

    // Testa linhas
    for(i=0; i < lin; i++){
        soma_linha = 0;
        for(j = 0; j < col; j++){
            soma_linha += matriz[0][j];
        }
        if(soma_linha != soma){
            quadrado_magico = 0;
        }
    }

    // Testa colunas
    for(i = 0; i < col; i++){
        soma_coluna = 0;
        for(j = 0; j < col; j++){
            soma_coluna += matriz[i][0];
        }
        if(soma_coluna != soma){
            quadrado_magico = 0;
        }
    }

    // Testa diagonal 1
    for(i = 0; i < col; i++) {
        soma_diag1 = 0;
        for(j = 0; j < col; j++) {
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

    if (quadrado_magico == 1) {
        printf("\nÉ um quadrado mágico\n");
    }
    else {
        printf("\nNão é quadrado mágico\n");
    }

    printf("\n\n");
    getchar();
    return 0;
}