#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>

void reset(TTemperaturas *temperaturas){
    printf("Digite a quantidade de dias:\n");
    scanf("%d", &temperaturas->qtde_dias);
    temperaturas->qtde_medidas = 0;
    temperaturas->medidas = malloc((sizeof(TMedidas))*temperaturas->qtde_dias);
}

void inserir_medida(TTemperaturas *temperaturas){
    if (temperaturas->qtde_medidas >= temperaturas->qtde_dias) {
        printf("Não é possível inserir mais medidas.\n");
    }
    printf("Informe a cidade:\n");
    scanf("%20s", temperaturas->medidas[temperaturas->qtde_medidas].cidade);
    printf("Informe a temperatura:\n");
    scanf("%f", temperaturas->medidas[temperaturas->qtde_medidas].temperatura);

    temperaturas->qtde_medidas ++;
}

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
    int escolha = 0;
    TTemperaturas *temperaturas = malloc(sizeof(TTemperaturas));
    while(escolha != 4){
        printf("Menu:\n1 - reset\n2 - inserir medida\n3 - estatistica\n4 - sair\n");
        scanf("%d", &escolha);
        switch (escolha){
        case 1:
            reset(temperaturas);
            printf("%d\n", temperaturas->qtde_dias);
            printf("%d\n", temperaturas->qtde_medidas);
            break;
        case 2:
            inserir_medida(temperaturas);
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
