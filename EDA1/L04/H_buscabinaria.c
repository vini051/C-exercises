#include <stdio.h>

int buscaBinaria(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return buscaBinaria(arr, l, mid - 1, x);

        return buscaBinaria(arr, mid + 1, r, x);
    }

    return l;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (q--) {
        int x;
        scanf("%d", &x);
        int resultado = buscaBinaria(arr, 0, n - 1, x);
        printf("%d\n", resultado);
    }

    return 0;
}
