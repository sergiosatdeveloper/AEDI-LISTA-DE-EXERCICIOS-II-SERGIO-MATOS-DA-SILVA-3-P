#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CRIANCAS 50
#define MAX_NOTA 5

int main() {
    int notas[NUM_CRIANCAS];
    int contagem[MAX_NOTA + 1] = {0}; 
   
    srand(time(NULL));
    
   
    for (int i = 0; i < NUM_CRIANCAS; i++) {
        notas[i] = rand() % MAX_NOTA + 1; 
        contagem[notas[i]]++;
    }
    
    // Exibindo o resultado
    printf("Resultado da pesquisa:\n");
    for (int i = 1; i <= MAX_NOTA; i++) {
        printf("Nota %d: %d vezes\n", i, contagem[i]);
    }
    
    return 0;
}
