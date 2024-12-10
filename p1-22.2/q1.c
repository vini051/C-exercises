#include <stdio.h>

int main(void){
    int vet[] = {10,20,30};
    int *p = vet;                   // aponta para o começo do vetor
    p++;                            // incrementou uma posição no vetor, ou seja, antes apontava para 10 e agora aponta para 20
    printf("\n%d", *p);             // 20
    (*p)++;                         // desreferencia p e incrementa, ou seja, incrementa o conteúdo, o valor apontado por p: 20 + 1 = 21
    printf(" - %d", *p);            // 21
    printf(" - %d", *(p+1));        // 30   -   incrementou mais uma posição do vetor
    return 0;
}