#include <stdio.h>

void movex(char *a, int n) {
    if (a[n] == '\0') {
        return;
    }
    if (a[n] == 'x') {
        movex(a, n + 1);
        if (a[n + 1] != '\0') {
            char aux = a[n];
            a[n] = a[n + 1];
            a[n + 1] = aux;
        }
    } else {
        movex(a, n + 1);
    }
}

int main() {
    char entrada[101];
    int length;
    scanf("%s%n", &entrada[0], &length);
    movex(entrada, 0);
    printf("%s\n", entrada);
    return 0;
}
