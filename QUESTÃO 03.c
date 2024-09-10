#include <stdio.h>

#define NUM_CONTAS 100


int buscaBinaria(int contas[], int tamanho, int numeroConta, int *comparacoes) {
    int inicio = 0, fim = tamanho - 1;
    
    while (inicio <= fim) {
        (*comparacoes)++;
        int meio = (inicio + fim) / 2;
        
        if (contas[meio] == numeroConta) {
            return meio; // Conta encontrada
        } else if (contas[meio] < numeroConta) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; 
}

int main() {
    int contas[NUM_CONTAS];
    int numeroConta, comparacoes = 0;
    
    
    for (int i = 0; i < NUM_CONTAS; i++) {
        contas[i] = 1000 + i;
    }
    
    // Solicitando o número da conta 
    printf("Digite o numero da conta que deseja buscar: ");
    scanf("%d", &numeroConta);
    
   
    int posicao = buscaBinaria(contas, NUM_CONTAS, numeroConta, &comparacoes);
    
    // o resultado
    if (posicao != -1) {
        printf("Conta %d encontrada na posicao %d.\n", numeroConta, posicao);
    } else {
        printf("Conta %d nao encontrada.\n", numeroConta);
    }
    
    printf("Comparacoes realizadas: %d\n", comparacoes);
    
    return 0;
}