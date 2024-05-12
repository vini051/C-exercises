#include <stdio.h>
#define SWAP(a, b, t) (t = a, a = b, b = t)

//TENTATIVA DE ITERATIVO
void movex(char *a, int n){
    for (int i = 0; i < n - 1; i++){
        if (a[i] == 'x')        {
          char temp;
          SWAP(a[i], a[i + 1], temp);
        }
    }
}

/* TENTATIVA FRACASSADA DE RECURSAO
void movesquerda(char *a, int n){
    if (a[n] != '\0') {
        a[n] = a[n + 1];
        movesquerda(a, n + 1);
    }
    return;
}

void movex(char *a, int n) {
    if (a[n] == '\0') {
        return;
    }
    if (a[n] == 'x') {
        movesquerda(a, n);
        char aux = a[n];
        a[n] = a[n + 1];
        a[n + 1] = aux;
    }
    movex(a, n + 1);
}
*/

int main() {
    char entrada[101];
    int length;
    scanf("%s%n", entrada, &length);
    movex(entrada, length);
    printf("%s\n", entrada);
    return 0;
}
