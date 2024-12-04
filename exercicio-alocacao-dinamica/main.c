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
        printf("Não é possível inserir mais medidas.\n\n");
        return;
    }
    
    printf("Informe a cidade:\n");
    scanf("%20s", temperaturas->medidas[temperaturas->qtde_medidas].cidade);
    
    printf("Informe a temperatura:\n");
    temperaturas->medidas[temperaturas->qtde_medidas].temperatura = malloc(sizeof(float));
    scanf("%f", temperaturas->medidas[temperaturas->qtde_medidas].temperatura);

    temperaturas->qtde_medidas ++;
}


void estatistica(TTemperaturas *temperaturas){
    if (temperaturas->qtde_medidas == 0){
        printf("Primeiro insira medidas!\n");
        return;
    }

    float media = 0, menor, maior;
    int maiorpos = 0, menorpos = 0;

    menor = maior = *(temperaturas->medidas[0].temperatura);

    for (int i = 0; i < temperaturas->qtde_medidas; i ++){
        media += *(temperaturas->medidas[i].temperatura);

        if (*temperaturas->medidas[i].temperatura > maior){
            maior = *temperaturas->medidas[i].temperatura;
            maiorpos = i;
        }
        
        if (*temperaturas->medidas[i].temperatura < menor){
            menor = *temperaturas->medidas[i].temperatura;
            menorpos = i;
        }
    }
    media = media/temperaturas->qtde_medidas;

    printf("Temperatura média: %.2f\n", media);

    printf("Menor temperatura: %.2f\nCidade: %s\n", menor, temperaturas->medidas[menorpos].cidade);
    printf("Maior temperatura: %.2f\nCidade: %s\n", maior, temperaturas->medidas[maiorpos].cidade);
}

void sair(TTemperaturas *temperaturas){
    for (int i = 0; i < temperaturas->qtde_medidas; i ++){
        free(temperaturas->medidas[i].temperatura);
    }

    free(temperaturas->medidas);
    temperaturas->medidas = NULL;
    free(temperaturas);
    temperaturas = NULL;
}

int main(){
    int escolha = 0;
    TTemperaturas *temperaturas = malloc(sizeof(TTemperaturas));
    while(escolha != 4){
        printf("Menu:\n1 - reset\n2 - inserir medida\n3 - estatistica\n4 - sair\n\n");
        scanf("%d", &escolha);
        switch (escolha){
        case 1:
            reset(temperaturas);
            printf("\n");
            break;
        case 2:
            inserir_medida(temperaturas);
            printf("\n");
            break;
        case 3:
            estatistica(temperaturas);
            printf("\n");
            break;
        case 4:
            sair(temperaturas);
            printf("Até mais...\n");
            break;
        
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    return 0;
}
