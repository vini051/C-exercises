#include <stdio.h>

void ordena(int *v, int n) {
    ordenaSelecaoRecursiva(v, n, 0);
}

void troca(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void ordenaSelecaoRecursiva(int *v, int n, int index) {
    if (index == n) {
        return;
    }

    int min_idx = index;
    for (int i = index + 1; i < n; i++) {
        if (v[i] < v[min_idx]) {
            min_idx = i;
        }
    }

    troca(&v[min_idx], &v[index]);

    ordenaSelecaoRecursiva(v, n, index + 1);
}
