/*fazer código exemplo com ciclos*/
#include<stdio.h>
int main()
    {
        int temperatura = 0;
        //1. intrudozir a temperatura inicial.
        printf("introduza a tempratura:");
        scanf("%d",&temperatura);

        //2. Enquanto a temperatura for superior a 40, continua a pedir para introduzir a tempratura.
        // simulação de temperatura, através do teclado.
        while (temperatura > 40 || temperatura < 10)
        {
            printf("intoduza a tempratura:");
            scanf("%d", &temperatura);
        }
        return 0;

    }
