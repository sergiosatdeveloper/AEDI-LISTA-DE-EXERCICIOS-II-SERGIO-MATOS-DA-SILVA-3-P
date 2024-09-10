#include <stdio.h>
#include <string.h>

#define MAX_TAM 10

void exibirPalavra(char palavra[], int tam, int acertou[]) {
    for (int i = 0; i < tam; i++) {
        if (acertou[i]) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    char palavra[MAX_TAM + 1];  
    int acertou[MAX_TAM] = {0}; 
    char letra;
    int vidas, tamPalavra, acertos = 0;
    
    // Inserção da palavra 
    printf("Digite a palavra secreta (até 10 caracteres): ");
    scanf("%s", palavra);
    
    tamPalavra = strlen(palavra);
    vidas = tamPalavra + 2;
    
    while (vidas > 0 && acertos < tamPalavra) {
        int encontrou = 0;
        
        printf("\nVidas restantes: %d\n", vidas);
        exibirPalavra(palavra, tamPalavra, acertou);
        
        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        
        
        for (int i = 0; i < tamPalavra; i++) {
            if (palavra[i] == letra && !acertou[i]) {
                acertou[i] = 1;
                acertos++;
                encontrou = 1;
            }
        }
        
        if (!encontrou) {
            printf("Letra incorreta! Você perdeu uma vida.\n");
            vidas--;
        } else {
            printf("Você acertou uma letra!\n");
        }
    }
    
    if (acertos == tamPalavra) {
        printf("\nParabéns! Você descobriu a palavra: %s\n", palavra);
    } else {
        printf("\nVocê perdeu! A palavra secreta era: %s\n", palavra);
    }
    
    return 0;
}
