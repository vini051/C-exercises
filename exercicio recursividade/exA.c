#include <stdio.h>

long int somavet(int *a, int qtde){
    int soma;
    if (qtde == 0) 
        return soma;
    soma = a[qtde-1] + somavet(a, --qtde);
}

int main(){
    int qtd;
    printf("Digite a quantidade de numeros do vetor: \n");
    scanf("%d", &qtd);
    int vetor[qtd];
    printf("Popule o vetor:\n");

    for (int i = 0; i < qtd; i++) {
        printf("Posicao %d:\n", i);
        scanf("%d", &vetor[i]);
    }

    int somae = somavet(vetor, qtd);
    printf("Soma dos elementos do vetor: %d\n", somae);
    return 0;
}