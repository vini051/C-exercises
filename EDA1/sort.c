#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

// void compexch(int *a, int *b){
//     if (a > b){
//         swap(a, b);
//     }
//     return;
// }

int particiona(int *v, int i, int f){
    int meio = (f - i)/2;
    int pivo = (v[meio] + v[i] + v[f])/3;
    while (i < f){
        while(i < f && v[i] <= pivo)
            i ++;
        while(i < f && v[f] > pivo)
            f --;
        swap(&v[i], &v[f]);
    }
    return i;
}

void quick(int *v, int i, int f){
    int pivo = particiona(v, i, f);
    while(i < f){
        quick(v, i, pivo);
        quick(v, pivo + 1, f);
    }
}

void bubble(int *v, int length){
    for(int j = 0; j < length; j ++){
        for(int i = 0; i < length - 1; i ++){
            if (v[i] > v[i + 1]){
                swap(&v[i], &v[i + 1]);
            }
        }
    }
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
    int length;
    printf("Numero de elementos:\n");
    scanf("%d", &length);
    int v[length], temp[length];
    printf("Elementos a serem ordenados:\n");
    for(int i = 0; i < length; i ++){
        scanf("%d", &v[i]);
        temp[i] = v[i];
    }

    // clock_t begin, end;
    // double time_spent;

    // Bubble sort
    memcpy(v, temp, length * sizeof(int));  // Copiar os elementos originais de temp para v
    // begin = clock();
    bubble(v, length);
    // end = clock();
    // time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    printf("\nbubble: %f\n"/*, time_spent */);
    for(int i = 0; i < length; i ++){
        printf("%d ", v[i]);
    }

    // Bubble sort otimizado
    memcpy(v, temp, length * sizeof(int));  // Copiar os elementos originais de temp para v
    // begin = clock();
    bubble_opt(v, length);
    // end = clock();
    // time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    printf("\nbubble otimizado: %f\n"/*, time_spent */);
    for(int i = 0; i < length; i ++){
        printf("%d ", v[i]);
    }

    // Bubble sort recursivo
    memcpy(v, temp, length * sizeof(int));  // Copiar os elementos originais de temp para v
    // begin = clock();
    bubble_rec(v, length);
    // end = clock();
    // time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    printf("\nbubble recursivo: %f\n"/*, time_spent */);
    for(int i = 0; i < length; i ++){
        printf("%d ", v[i]);
    }

    // Quick sort
    memcpy(v, temp, length * sizeof(int));  // Copiar os elementos originais de temp para v
    // begin = clock();
    quick(v, 0, length - 1);
    // end = clock();
    // time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    printf("\nquick: %f\n"/*, time_spent */);
    for(int i = 0; i < length; i ++){
        printf("%d ", v[i]);
    }
    
    /*  TENTATIVA DE LER INPUTS
    FILE *arq = fopen(argv[1], "rt");
    

    fscanf(arq, "%d", &length);

    int *v = malloc(length * sizeof(int));

    for (int i = 0; i < length; i++) {
        fscanf(arq, "%d", &v[i]);
    }

    fclose(arq);

    if(strcmp(argv[2], "bubble") == 0) {bubble(v, length);}
    if(strcmp(argv[2],  "bubble_opt") == 0) {bubble_opt(v, length);}
    if(strcmp(argv[2],  "bubble_rec") == 0) {bubble_rec(v, length);}

    free(v);
    */
    return 0;
}