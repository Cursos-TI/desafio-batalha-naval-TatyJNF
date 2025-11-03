
#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int k = 0; k < NAVIO; k++) {
        int l = linha, c = coluna;
        if (direcao == 0) c += k;
        else if (direcao == 1) l += k;
        else if (direcao == 2) { l += k; c += k; }
        else if (direcao == 3) { l += k; c -= k; }
        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO) return 0;
        if (tabuleiro[l][c] != 0) return 0;
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int k = 0; k < NAVIO; k++) {
        int l = linha, c = coluna;
        if (direcao == 0) c += k;
        else if (direcao == 1) l += k;
        else if (direcao == 2) { l += k; c += k; }
        else if (direcao == 3) { l += k; c -= k; }
        tabuleiro[l][c] = 3;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    printf("=== BATALHA NAVAL - NIVEL INTERMEDIARIO ===\n");
    printf("Posicionando navios no tabuleiro...\n\n");

    int h_linha = 2, h_coluna = 1;
    if (podePosicionar(tabuleiro, h_linha, h_coluna, 0)) {
        posicionarNavio(tabuleiro, h_linha, h_coluna, 0);
        printf("Navio horizontal posicionado na linha 3, colunas 2-4\n");
    } else printf("Erro ao posicionar navio horizontal!\n");

    int v_linha = 5, v_coluna = 7;
    if (podePosicionar(tabuleiro, v_linha, v_coluna, 1)) {
        posicionarNavio(tabuleiro, v_linha, v_coluna, 1);
        printf("Navio vertical posicionado na coluna 8, linhas 6-8\n");
    } else printf("Erro ao posicionar navio vertical!\n");

    int d1_linha = 7, d1_coluna = 0;
    if (podePosicionar(tabuleiro, d1_linha, d1_coluna, 2)) {
        posicionarNavio(tabuleiro, d1_linha, d1_coluna, 2);
        printf("Navio diagonal principal posicionado nas posicoes (8,1)-(10,3)\n");
    } else printf("Erro ao posicionar navio diagonal principal!\n");

    int d2_linha = 0, d2_coluna = 9;
    if (podePosicionar(tabuleiro, d2_linha, d2_coluna, 3)) {
        posicionarNavio(tabuleiro, d2_linha, d2_coluna, 3);
        printf("Navio diagonal secundaria posicionado nas posicoes (1,10)-(3,8)\n");
    } else printf("Erro ao posicionar navio diagonal secundaria!\n");

    printf("\n=== TABULEIRO FINAL ===\n");
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) printf("%2d ", j + 1);
    printf("\n   ");
    for (int j = 0; j < TAMANHO; j++) printf("---");
    printf("\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d|", i + 1);
        for (int j = 0; j < TAMANHO; j++) printf("%2d ", tabuleiro[i][j]);
        printf("\n");
    }
    printf("\nLegenda:\n0 = Agua\n3 = Navio\n");
    return 0;
}
