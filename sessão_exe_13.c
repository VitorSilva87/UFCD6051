#include <stdio.h>

void esperar(int segundos) {
    // Função para simular a espera usando um loop
    for (int i = 0; i < segundos * 100000000; i++) {
        // Apenas um loop vazio para gastar tempo
    }
}

int main() {
    while(1) {
        // Cor verde
        printf("Sinal Verde - Pode passar\n");
        esperar(20); // Simula esperar 20 segundos

        // Cor amarelo
        printf("Sinal Amarelo - Atencao\n");
        esperar(20); // Simula esperar 20 segundos

        // Cor vermelho
        printf("Sinal Vermelho - Pare\n");
        esperar(20); // Simula esperar 20 segundos
    }

    return 0;
}
