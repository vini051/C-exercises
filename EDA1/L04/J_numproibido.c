#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);
    int *numerosProibidos = (int*)malloc(N * sizeof(int));

    for(int i = 0; i < N; i++) {
        scanf("%d", &numerosProibidos[i]);
    }

    // Ordenando os números proibidos para usar busca binária
    qsort(numerosProibidos, N, sizeof(int), comparar);

    int num;
    while(scanf("%d", &num) != EOF) {
        if(bsearch(&num, numerosProibidos, N, sizeof(int), comparar)) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }

    free(numerosProibidos);
    return 0;
}
