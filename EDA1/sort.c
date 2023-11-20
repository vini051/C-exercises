#include <stdio.h>

void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
    return;
}

void bubble_opt(int *v, int length){
    int troca = 1;
    while(troca){
        troca = 0;
        for(int i = 0; i < length - 1; i ++){
            if (v[i] > v[i + 1]){
                swap(&v[i], &v[i + 1]);
                troca = 1;    
            }
        }
        length --;
    }
}

void bubble_rec(int *v, int length){
    if (length < 2) return;
    for(int i = 0; i < length - 1; i ++){
        if (v[i] > v[i + 1]){
            swap(&v[i], &v[i + 1]);    
        }
    }
    bubble_rec(v, length - 1);
}

int main(int argc, char *argv[]){
    int n = 10;
    int v[n];
    
    printf("Entre com %d numeros:\n", n);
    
    for(int i = 0; i < n; i ++){
        scanf("%d", &v[i]);
    }

    bubble_rec(v, n);

    printf("Eis o vetor ordenado:\n");

    for(int i = 0; i < n; i ++){
        printf("%d ", v[i]);
    }
    return 0;
}