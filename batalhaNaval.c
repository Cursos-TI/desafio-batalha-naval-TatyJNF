#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;
    
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    printf("=== BATALHA NAVAL - NIVEL NOVATO ===\n");
    printf("Posicionando navios no tabuleiro...\n\n");
    
    tabuleiro[2][1] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    printf("Navio horizontal posicionado na linha 3, colunas 2-4\n");
    
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;
    printf("Navio vertical posicionado na coluna 8, linhas 6-8\n");
    
    printf("\n=== TABULEIRO FINAL ===\n");
    
    printf("   ");
    for (j = 0; j < 10; j++) {
        printf("%2d ", j + 1);
    }
    printf("\n");
    
    printf("   ");
    for (j = 0; j < 10; j++) {
        printf("---");
    }
    printf("\n");
    
    for (i = 0; i < 10; i++) {
        printf("%2d|", i + 1);
        for (j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    
    printf("\nLegenda:\n");
    printf("0 = Agua\n");
    printf("3 = Navio\n");
    
    return 0;
}
