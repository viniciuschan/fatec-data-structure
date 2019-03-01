#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void checaOp(char *operacao) {
    while (!strchr("+-*/", toupper(*operacao))) {
        puts("Escolha um operador válido");
        *operacao = toupper(getchar());
    }
    return;
}

void checaValor(char *operacao, float *valor) {
    while (strchr("/", *operacao) && valor[1] == 0) {
        puts("Divisão por zero, escolha outro valor");
        scanf("%f", &valor[1]);
    }
    return;
}

float calculaOperacao(char *operacao, float *valor) {
    switch (*operacao) {
    case '+': return valor[0] + valor[1];
    case '-': return valor[0] - valor[1];
    case '*': return (valor[0]) * (valor[1]);
    case '/': return valor[0] / valor[1];
    case 'Q': exit(0);
    default: exit(0);
    }
}

int main() {
    float valor[2];
    char operacao;

    puts("Escolha uma das operações:");
    puts("[ + ] Soma  -  [ - ]  Subtração  -  [ * ] Multiplicaçao  -  [ / ] Divisão");
    scanf("%c", &operacao);

    puts("Digite o primeiro valor");
    scanf("%f", &valor[0]);

    puts("Digite o segundo valor");
    scanf("%f", &valor[1]);

    checaOp(&operacao);
    checaValor(&operacao, valor);

    printf("%f %c %f = %f\n", valor[0], operacao, valor[1], calculaOperacao(&operacao, valor));
    getchar();

    return EXIT_SUCCESS;
}
