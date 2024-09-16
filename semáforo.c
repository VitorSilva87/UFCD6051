#include <stdio.h>
#include <conio.h>
#include <windows.h>  // Para Sleep() e SetConsoleTextAttribute()

// Definições de cores para o console no Windows
#define COR_VERDE  10
#define COR_AMARELO 14
#define COR_VERMELHO 12
#define COR_PADRAO  7

// Enumeração para os estados do semáforo
enum EstadoSemaforo {
    VERDE,
    AMARELO,
    VERMELHO,
    MANTENCAO,
    DESLIGADO
};

// Função para exibir o semáforo com as cores no console do Windows
void mostrarSemaforo(enum EstadoSemaforo estado, int piscaAmarelo) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Define a posição do cursor no topo para atualizar apenas a área do semáforo
    COORD semaforoPos = {0, 0};
    SetConsoleCursorPosition(hConsole, semaforoPos);

    SetConsoleTextAttribute(hConsole, COR_PADRAO);
    printf(" Semáforo:\n");

    // Mostrar as luzes como bolas coloridas dentro da caixa
    SetConsoleTextAttribute(hConsole, (estado == VERDE) ? COR_VERDE : COR_PADRAO);
    printf("\n");
    printf("\n");
    printf("[ %s ]\n", (estado == VERDE) ? "O" : " ");
    
    SetConsoleTextAttribute(hConsole, (estado == AMARELO || piscaAmarelo) ? COR_AMARELO : COR_PADRAO);
    printf("[ %s ]\n", (estado == AMARELO || piscaAmarelo) ? "O" : " ");
    
    SetConsoleTextAttribute(hConsole, (estado == VERMELHO) ? COR_VERMELHO : COR_PADRAO);
    printf("[ %s ]\n", (estado == VERMELHO) ? "O" : " ");
    printf("\n");

    SetConsoleTextAttribute(hConsole, COR_PADRAO); // Restaura a cor padrão
}

// Função para exibir o menu de comandos na parte inferior da tela
void mostrarMenu() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    // Posição da última linha no console
    COORD pos = {0, consoleInfo.dwSize.Y - 5}; // Ajuste para o número de linhas que você quer deixar no fundo
    SetConsoleCursorPosition(hConsole, pos);

    // Exibe os comandos no rodapé
    SetConsoleTextAttribute(hConsole, COR_PADRAO);
    printf("\nComandos: L: Ligar  D: Desligar  M: Manutenção  S: Sair da Manutenção  V: Excesso de Velocidade\n");
}

int main() {
    enum EstadoSemaforo estado = DESLIGADO;
    char comando;
    int tempoRestante = 0; // Tempo restante para a mudança de estado
    int piscaAmarelo = 0; // Flag para controle do piscar da luz amarela
    int tempoPiscaAmarelo = 0; // Tempo para alternar o piscar da luz amarela
    int estadoV = 0; // Flag para controlar o estado de mudança para vermelho via 'V'
    int tempoAmarelo = 0; // Tempo restante para o estado amarelo após pressionar 'V'
    
    // Exibe o menu uma vez, ele ficará fixo no fundo
    mostrarMenu();

    while (1) {
        // Verifica se há comandos a serem processados
        if (_kbhit()) { // Verifica se uma tecla foi pressionada
            comando = _getch(); // Captura o comando

            if (estado == DESLIGADO) {
                if (comando == 'L' || comando == 'l') {
                    estado = VERDE; // Liga o semáforo
                    tempoRestante = 7000; // Define o tempo para a luz verde
                    estadoV = 0; // Reseta o estado da tecla 'V'
                }
            } else {
                // Processa outros comandos
                switch (comando) {
                    case 'L':
                    case 'l':
                        // Não faz nada se o semáforo já estiver ligado
                        break;
                    case 'D':
                    case 'd':
                        estado = DESLIGADO;
                        estadoV = 0; // Reseta o estado da tecla 'V'
                        break;
                    case 'M':
                    case 'm':
                        estado = MANTENCAO;
                        tempoPiscaAmarelo = 0; // Reseta o tempo do piscar quando entra em manutenção
                        estadoV = 0; // Reseta o estado da tecla 'V'
                        break;
                    case 'S':
                    case 's':
                        if (estado == MANTENCAO) {
                            estado = VERDE;
                            tempoRestante = 7000; // Reinicia o tempo para 7 segundos no verde
                        }
                        estadoV = 0; // Reseta o estado da tecla 'V'
                        break;
                    case 'V':
                    case 'v':
                        if (estado != DESLIGADO) {
                            estado = AMARELO;
                            tempoAmarelo = 2000; // Tempo para a luz amarela
                            estadoV = 1; // Marca que o processo de mudança para vermelho está em andamento
                            tempoRestante = 0; // Reseta o tempo restante para evitar conflitos
                        }
                        break;
                }
            }
        }

        if (estadoV) {
            if (tempoAmarelo > 0) {
                mostrarSemaforo(AMARELO, 0);
                Sleep(1000); // Dorme por 1 segundo
                tempoAmarelo -= 1000; // Reduz o tempo restante
            }

            if (tempoAmarelo <= 0) {
                estado = VERMELHO;
                tempoRestante = 7000; // Tempo para a luz vermelha
                estadoV = 0; // Reseta o estado da tecla 'V'
            }
        } else if (estado != DESLIGADO && estado != MANTENCAO) {
            mostrarSemaforo(estado, 0);

            // Controle do tempo restante
            if (tempoRestante > 0) {
                Sleep(1000); // Dorme por 1 segundo
                tempoRestante -= 1000; // Reduz o tempo restante
            }

            if (tempoRestante <= 0) {
                // Muda o estado do semáforo conforme o estado atual
                if (estado == VERDE) {
                    estado = AMARELO;
                    tempoRestante = 4000; // Define o tempo restante para o próximo estado
                } else if (estado == AMARELO) {
                    estado = VERMELHO;
                    tempoRestante = 7000; // Define o tempo restante para o próximo estado
                } else if (estado == VERMELHO) {
                    estado = VERDE;
                    tempoRestante = 7000; // Define o tempo restante para o próximo estado
                }
            }
        } else if (estado == MANTENCAO) {
            // Controla o piscar da luz amarela
            tempoPiscaAmarelo += 500; // Incrementa o tempo do piscar

            // Alterna a visibilidade da luz amarela a cada 500ms
            if (tempoPiscaAmarelo >= 500) {
                piscaAmarelo = !piscaAmarelo;
                tempoPiscaAmarelo = 0; // Reseta o tempo do piscar
            }

            mostrarSemaforo(estado, piscaAmarelo);
            Sleep(500); // Dorme por 0.5 segundo para o piscar
        } else {
            mostrarSemaforo(estado, 0);
            Sleep(500); // Dorme por 0.5 segundo para evitar uso excessivo de CPU
        }
    }

    return 0;
}
