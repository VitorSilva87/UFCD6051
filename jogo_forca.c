#include <stdio.h> 
#include <conio.h> // Para _getch()
#include <string.h>
#include <stdlib.h> // Para system()
#include <windows.h> // Para SetConsoleTextAttribute, GetStdHandle e Sleep

#define MAX_TENTATIVAS 6
#define MAX_PALAVRA 100

void limparTela() {
    system("cls");
}

void definirCor(int cor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, cor);
}

void resetarCor() {
    definirCor(7); // Cor padrão (branco no fundo preto)
}

void exibirForca(int tentativas) {
    const char* estados[] = {
        "______\n|    |\n|    \n|    \n|    \n|    \n",
        "______\n|    |\n|    O\n|    \n|    \n|    \n",
        "______\n|    |\n|    O\n|    |\n|    \n|    \n",
        "______\n|    |\n|    O\n|   /|\n|    \n|    \n",
        "______\n|    |\n|    O\n|   /|\\\n|    \n|    \n",
        "______\n|    |\n|    O\n|   /|\\\n|   /\n|    \n",
        "______\n|    |\n|    O\n|   /|\\\n|   / \\\n|    \n"
    };

    printf("%s", estados[tentativas]);
}

void exibirPalavra(const char* palavra, const int* acertadas, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (acertadas[i]) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void esperarEnter() {
    printf("Pressione ENTER para comecar...");
    while (_getch() != 13) { // 13 é o código ASCII para ENTER
        // Espera até que ENTER seja pressionado
    }
    printf("\n");
}

void mensagemBoasVindas() {
    printf("Bem-vindo ao jogo da Forca!\n");
    printf("Tente adivinhar a palavra antes que suas tentativas se esgotem.\n\n");
}

int jogarNovamente() {
    char opcao;
    printf("Deseja jogar novamente? (S para sim, N para nao): ");
    opcao = _getch(); // Lê a opção sem esperar Enter
    printf("\n");

    return (opcao == 'S' || opcao == 's');
}

void esperar(int milissegundos) {
    Sleep(milissegundos); // Espera o tempo especificado em milissegundos
}

int main() {
    char palavra[MAX_PALAVRA];
    int tamanho;
    int acertadas[MAX_PALAVRA];
    int tentativas;
    int i;
    char letra;
    int acertou;
    int jogar = 1; // Controla se o jogo deve continuar

    while (jogar) {
        // Inicializa as variáveis para uma nova partida
        strcpy(palavra, "programacao"); // Palavra a ser adivinhada
        tamanho = strlen(palavra);
        memset(acertadas, 0, sizeof(acertadas)); // Zera o array de letras acertadas
        tentativas = 0;

        limparTela();
        mensagemBoasVindas(); // Exibe a mensagem de boas-vindas

        // Espera pelo ENTER para começar o jogo e limpa a tela
        esperarEnter(); 
        limparTela();

        // Exibe a estrutura inicial da forca e o estado do jogo
        exibirForca(tentativas);
        exibirPalavra(palavra, acertadas, tamanho);
        printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
        printf("Digite uma letra: ");

        while (tentativas < MAX_TENTATIVAS) {
            acertou = 0;

            // Lê uma letra do usuário
            letra = _getch(); // Lê uma letra sem esperar Enter
            printf("\n");

            // Verifica se a letra está na palavra
            for (i = 0; i < tamanho; i++) {
                if (palavra[i] == letra) {
                    acertadas[i] = 1;
                    acertou = 1;
                }
            }

            // Se a letra não estiver na palavra, incrementa o contador de tentativas
            if (!acertou) {
                tentativas++;
            }

            // Limpa a tela e exibe o estado atualizado do jogo
            limparTela();
            exibirForca(tentativas);
            exibirPalavra(palavra, acertadas, tamanho);
            printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
            printf("Digite uma letra: ");

            // Verifica se a palavra foi completamente acertada
            int vitoria = 1;
            for (i = 0; i < tamanho; i++) {
                if (!acertadas[i]) {
                    vitoria = 0;
                    break;
                }
            }

            if (vitoria) {
                // Mensagem de vitória em verde
                definirCor(10); // Cor verde
                printf("Parabens! Voce ganhou!\n");
                resetarCor(); // Resetar a cor para o padrão
                break;
            }
        }

        if (tentativas == MAX_TENTATIVAS) {
            // Mensagem de "Você perdeu!" em vermelho
            definirCor(12); // Cor vermelha
            printf("             Voce perdeu! Tente uma proxima.\n");
            resetarCor(); // Resetar a cor para o padrão
        }

        // Mensagem final em amarelo
        definirCor(14); // Cor amarela
        printf("                           Obrigado por jogar! Ate a proxima!\n");
        resetarCor(); // Resetar a cor para o padrão

        // Espera 10 segundos antes de reiniciar o jogo ou sair
        esperar(10000); // 10000 milissegundos = 10 segundos

        limparTela(); // Limpa a tela antes de reiniciar o jogo

        // Pergunta se o usuário deseja jogar novamente
        jogar = jogarNovamente();
    }

    return 0;
}
