#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1000000000

// Função para comparar dois inteiros usada no qsort
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função para remover elementos duplicados de um vetor
int removerDuplicados(int *vetor, int tamanho) {
    int i, j = 0;
    for (i = 0; i < tamanho - 1; i++) {
        if (vetor[i] != vetor[i + 1]) {
            vetor[j++] = vetor[i];
        }
    }
    vetor[j++] = vetor[tamanho - 1];
    return j; // Novo tamanho do vetor sem duplicatas
}

int main() {
    int N, i, novoTamanho, tamanhoNMU;
    scanf("%d", &N);
    int *vetor = (int *)malloc(N * sizeof(int));
    int *NMU = (int *)malloc((N / 2 + 1) * sizeof(int)); // Vetor para armazenar os NMU

    // Leitura dos números
    for (i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    // Ordenação e remoção de duplicados
    qsort(vetor, N, sizeof(int), comparar);
    novoTamanho = removerDuplicados(vetor, N);

    // Adicionando 1 bilhão se o tamanho for ímpar
    if (novoTamanho % 2 != 0) {
        vetor[novoTamanho++] = MAX_NUM;
    }

    // Calculando os NMU
    tamanhoNMU = 0;
    for (i = 0; i < novoTamanho; i += 2) {
        NMU[tamanhoNMU++] = vetor[i] + vetor[i + 1];
    }

    // Reinserindo os NMU no vetor original
    for (i = 0; i < tamanhoNMU; i++) {
        if (bsearch(&NMU[i], vetor, novoTamanho, sizeof(int), comparar) == NULL) {
            vetor[novoTamanho++] = NMU[i];
        }
    }

    // Ordenando o vetor final
    qsort(vetor, novoTamanho, sizeof(int), comparar);

    // Imprimindo os elementos e a quantidade de elementos únicos
    for (i = 0; i < novoTamanho; i += 4) {
        printf("%d\n", vetor[i]);
    }
    printf("Elementos: %d\n", novoTamanho);

    // Liberando a memória alocada
    free(vetor);
    free(NMU);

    return 0;
}
