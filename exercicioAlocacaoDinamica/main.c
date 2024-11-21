#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>

void reset(TTemperaturas *temperaturas){
    int dias;
    printf("Digite a quantidade de dias:\n");
    scanf("%d", &dias);
    temperaturas->qtde_dias = dias;
    temperaturas->qtde_medidas = 0;
    TMedidas medidas[] = malloc(sizeof(TMedidas)*dias);
}

// void inserir_medida(TMedidas *medida, TTemperaturas *temperaturas){
//     if () {
//         printf("Não é possível inserir mais medidas.\n");
    // }
    //add medida ao vetor de temperaturas
    // temperaturas->qtde_medidas ++;
// }

// void estatistica(TMedidas *medida){
//     float media, menor, maior;
//     printf("Temperatura média: %f\n", media);
//     printf("Menor temperatura: %f\nCidade: %s\n", menor, medida->cidade);
//     printf("Maior temperatura: %f\nCidade: %s\n", maior, medida->cidade);
// }

// void sair(TMedidas *medidas){
//     free(medidas);
//}



int main(){
    int escolha;
    TTemperaturas *temperaturas;
    while(escolha != 4){
        printf("Menu:\n1 - reset\n2 - inserir medida\n3 - estatistica\n4 - sair\n");
        scanf("%d", &escolha);
        switch (escolha){
        case 1:
            reset(temperaturas);
            printf("escolhido %d\n", escolha);
            printf(temperaturas->qtde_dias);
            printf(temperaturas->qtde_medidas);
            break;
        case 2:
            // inserir_medida();
            printf("escolhido %d\n", escolha);
            break;
        case 3:
            // estatistica();
            printf("escolhido %d\n", escolha);
            break;
        case 4:
            // sair();
            printf("escolhido %d\n", escolha);
            break;
        
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    return 0;
}
