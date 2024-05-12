#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char palavra[16];
} Instrucao;

int comparar(const void *a, const void *b) {
    Instrucao *instrucaoA = (Instrucao *)a;
    Instrucao *instrucaoB = (Instrucao *)b;
    return instrucaoA->codigo - instrucaoB->codigo;
}

int buscaBinaria(Instrucao *instrucoes, int n, int codigo) {
    int esquerda = 0, direita = n - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (instrucoes[meio].codigo == codigo)
            return meio;
        if (instrucoes[meio].codigo < codigo)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    Instrucao *instrucoes = (Instrucao *)malloc(n * sizeof(Instrucao));

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &instrucoes[i].codigo, instrucoes[i].palavra);
    }

    // Ordenando as instruções pelo código para usar busca binária
    qsort(instrucoes, n, sizeof(Instrucao), comparar);

    int codigo;
    while (scanf("%d", &codigo) != EOF) {
        int indice = buscaBinaria(instrucoes, n, codigo);
        if (indice != -1) {
            printf("%s\n", instrucoes[indice].palavra);
        } else {
            printf("undefined\n");
        }
    }

    free(instrucoes);
    return 0;
}
