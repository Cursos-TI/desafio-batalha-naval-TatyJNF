
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define NAVIO 3
#define TAMANHO_HABILIDADE 5
#define AGUA 0
#define NAVE 3
#define HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void criarHabilidadeCone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == 0 && j == 2) {
                cone[i][j] = 1;
            } else if (i == 1 && (j >= 1 && j <= 3)) {
                cone[i][j] = 1;
            } else if (i == 2 && (j >= 0 && j <= 4)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

void criarHabilidadeCruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

void criarHabilidadeOctaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int distancia = abs(i - centro) + abs(j - centro);
            if (distancia <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}



void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origem_linha, int origem_coluna) {
    int offset = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origem_linha - offset + i;
                int coluna = origem_coluna - offset + j;
                if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                    if (tabuleiro[linha][coluna] != NAVE) {
                        tabuleiro[linha][coluna] = HABILIDADE;
                    }
                }
            }
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
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    
    inicializarTabuleiro(tabuleiro);

    printf("=== BATALHA NAVAL - NIVEL AVANCADO ===\n");
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

    printf("\nCriando habilidades especiais...\n");
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    printf("Aplicando habilidade Cone na posicao (4,4)...\n");
    aplicarHabilidade(tabuleiro, cone, 3, 3);

    printf("Aplicando habilidade Cruz na posicao (7,2)...\n");
    aplicarHabilidade(tabuleiro, cruz, 6, 1);

    printf("Aplicando habilidade Octaedro na posicao (9,6)...\n");
    aplicarHabilidade(tabuleiro, octaedro, 8, 5);

    printf("\n=== TABULEIRO COM HABILIDADES ===\n");
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
    printf("\nLegenda:\n0 = Agua\n3 = Navio\n5 = Area de Efeito da Habilidade\n");
    return 0;
}
