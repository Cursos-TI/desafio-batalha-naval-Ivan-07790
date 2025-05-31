#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para verificar se há sobreposição
int verificaSobreposicao(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] != AGUA;
}

int main() {
    // 1. Declarar e inicializar o tabuleiro com 0
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posicionar dois navios horizontais/verticais
    // --- Navio Horizontal ---
    int linhaH = 1, colunaH = 2;
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (!verificaSobreposicao(tabuleiro, linhaH, colunaH + i)) {
                tabuleiro[linhaH][colunaH + i] = NAVIO;
            }
        }
    }

    // --- Navio Vertical ---
    int linhaV = 4, colunaV = 7;
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (!verificaSobreposicao(tabuleiro, linhaV + i, colunaV)) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        }
    }

    // 3. Posicionar dois navios diagonais
    // --- Navio Diagonal Principal (↘) ---
    int linhaD1 = 0, colunaD1 = 0;
    if (linhaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (!verificaSobreposicao(tabuleiro, linhaD1 + i, colunaD1 + i)) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            }
        }
    }

    // --- Navio Diagonal Secundária (↙) ---
    int linhaD2 = 2, colunaD2 = 8;
    if (linhaD2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD2 - (TAMANHO_NAVIO - 1) >= 0) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (!verificaSobreposicao(tabuleiro, linhaD2 + i, colunaD2 - i)) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            }
        }
    }

    // 4. Exibir o tabuleiro
    printf("\nTabuleiro de Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
