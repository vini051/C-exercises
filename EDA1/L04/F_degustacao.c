#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char caractere;
    int tamanho;
    int posicao;
} Sequencia;

int comparar(const void *a, const void *b) {
    Sequencia *seqA = (Sequencia *)a;
    Sequencia *seqB = (Sequencia *)b;
    if (seqA->tamanho == seqB->tamanho) {
        return seqA->posicao - seqB->posicao;
    }
    return seqB->tamanho - seqA->tamanho;
}

int main() {
    char s[100001];
    scanf("%s", s);
    int n = strlen(s);

    Sequencia sequencias[n];
    int count = 0;
    char atual = s[0];
    int tamanho = 1;
    int posicao = 0;

    for (int i = 1; i < n; i++) {
        if (s[i] == atual) {
            tamanho++;
        } else {
            sequencias[count].caractere = atual;
            sequencias[count].tamanho = tamanho;
            sequencias[count].posicao = posicao;
            count++;
            atual = s[i];
            tamanho = 1;
            posicao = i;
        }
    }
    sequencias[count].caractere = atual;
    sequencias[count].tamanho = tamanho;
    sequencias[count].posicao = posicao;
    count++;

    qsort(sequencias, count, sizeof(Sequencia), comparar);

    for (int i = 0; i < count; i++) {
        printf("%d %c %d\n", sequencias[i].tamanho, sequencias[i].caractere, sequencias[i].posicao);
    }

    return 0;
}
