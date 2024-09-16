/*
1. Introduzir 2 números e imprimir o maior.
*/

#include <stdio.h>

int main() {
    int num1, num2;

    // Solicita o primeiro números
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    // solicita o segundo número
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    // Verifica qual número é maior
    if (num1 > num2) {
        printf("O maior número é: %d\n", num1);
    } else if (num2 > num1) {
        printf("O maior número é: %d\n", num2);
    } else {
        printf("Os dois números são iguais.\n");
    }

    return 0;
}