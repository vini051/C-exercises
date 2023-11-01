#include <stdio.h>
#include <string.h>

void movex(char *a, int n) {
    if (n == strlen(a)) {
        return;
    }
    if (a[n] == 'x') {
        char aux = a[n];
        memmove(&a[n], &a[n + 1], strlen(a) - n);
        a[strlen(a) - 1] = aux;
    }
    a[strlen(a)] = '\0';
    movex(a, n + 1);
}

int main() {
    char entrada[101];
    scanf("%s", entrada);
    movex(entrada, 0);
    printf("%s\n", entrada);
    return 0;
}
