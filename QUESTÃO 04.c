#include <stdio.h>

#define NUM_PRIMOS 25

// Lista de números primos 
int primos[NUM_PRIMOS] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
    73, 79, 83, 89, 97
};


int buscaBinaria(int arr[], int tamanho, int chave) {
    int inicio = 0, fim = tamanho - 1;
    
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        
        if (arr[meio] == chave) {
            return meio; // Número encontrado
        } else if (arr[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; // Número não encontrado
}

int main() {
    int numero;
    
    // Solicitando o número ao usuário
    printf("Digite um numero de 1 a 100: ");
    scanf("%d", &numero);
    
    
    int posicao = buscaBinaria(primos, NUM_PRIMOS, numero);
    
    //resultado
    if (posicao != -1) {
        printf("O numero %d eh primo e esta na lista.\n", numero);
    } else {
        printf("O numero %d nao eh primo ou nao esta na lista.\n", numero);
    }
    
    return 0;
}