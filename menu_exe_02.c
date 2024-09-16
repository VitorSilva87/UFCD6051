#include <stdio.h>

int main() {
    int opcao;

    do {
        // Exibe o menu
        printf("\n         Menu      \n");
        printf("\n");
    
        printf("1. Visualizar cronograma\n");
        printf("2. Marcar ocupacoes\n");
        printf("3. Atividade de monitorizacao\n");
        printf("4. Mediacao\n");
        printf("5. Sair\n");
        printf("\n");
        printf("\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Verifica a opção escolhida
        switch(opcao) {
            case 1:
                printf("Você escolheu 'Visualizar cronograma'.\n");
                // Coloque o código da funcionalidade aqui
                break;
            case 2:
                printf("Você escolheu 'Marcar ocupações'.\n");
                // Coloque o código da funcionalidade aqui
                break;
            case 3:
                printf("Você escolheu 'Atividade de monitorizacao'.\n");
                // Coloque o código da funcionalidade aqui
                break;
            case 4:
                printf("Você escolheu 'Mediação'.\n");
                // Coloque o código da funcionalidade aqui
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 5); // O loop continua até que a opção seja 'Sair'

    return 0;
}