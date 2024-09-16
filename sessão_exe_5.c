/*semáforo */

#include <stdio.h>

int main()

{
float x = 0.0f;
float y = 0.0f;
// 1. introduza o numero 1
printf("introduza o primeiro numero:");
scanf("%2f",&x);

// 2. introduza o numero 2
printf("introduza o segundo numero:");
scanf("%2f",&y);

float soma = 0.0f;
float produto = 0.0f;
float diferenca = 0.0f;
float quociente = 0.0f;

// 3. correr funçõens 
soma = x + y ;
produto = x * y ;
diferenca = x - y ;
quociente = x / y ;

//4. resultado
 printf("soma: %.2f\n", soma);
 printf("produto: %.2f\n", produto);
 printf("diferenca: %.2f\n", diferenca);
 printf("quociente: %.2f\n", quociente);

return 0;
}