#include <stdio.h>
int main ()
{

// 1.introduzir o numero 1
float x = 0.0f;
printf("introduza o primeiro numero:");
scanf("%f", &x);

// 2.introduzir o numero 2
float y = 0.0f;
printf("introduza o segundo numero:");
scanf("%f", &y);

//3.introdudir o operrador
char operador; 
printf("introduza o operador: ");
scanf(" %c",&operador);

//4.fazer o calculo.
float resultado = 0.0f;
switch (operador)
{
case '+':
    resultado = x + y;
    break;

case '-':
    resultado = x - y;
    break;

case '*':
    resultado = x * y;
    break;

case'/':
    resultado = x * y;
    break;

default:
printf("operador invalido.");
    break;
}


// demostrar o resultado.
printf("resultado:%.2f",resultado);

    return 0;
}