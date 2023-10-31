#include <stdio.h>
#include <string.h>

// ideia: ler um char com 101 posicoes, sendo 100 para leitura + \0
// pegar esse char e comparar cada posicao com "x". caso igual, move para a proxima posicao
// (posicao seguinte recebe posicao atual) ou (posicao[strlen: ultima posicao] recebe posicao atual)
// repetir isso recursivamente por ??? vezes

void movex(char *a, int n){
    if (n == strlen(a)){
        return;
    }
    int i = n;
    if (a[i] == 'x'){
        a[i+1] = a[i];
    }
    movex(a, ++i);
}

int main(){
    int i = 0;
    char entrada[101];
    scanf("%s", entrada);
    //printf("%ld\n", strlen(entrada));
    movex(entrada, i);
    printf("%s", entrada);
    return 0;
}