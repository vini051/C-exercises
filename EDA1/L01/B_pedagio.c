#include <stdio.h>

int main(){
    int L, D, K, P, C;
    /*
    L = Comprimento da estrada
    D = Dist entre pedagios
    K = custo por km
    P = valor de cada pedagio
    C = custo total da viagem
    */
    scanf("%d %d", &L, &D);
    scanf("%d %d", &K, &P);
    C = (K*L) + (P*(L/D));    //pensar em como fazer esse calculo da quantidade de pedagios para depois multiplicar pelo custo para ter o custo total
    printf("%d\n", C); 
    
}