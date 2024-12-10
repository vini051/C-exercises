#include <stdio.h>
#include <stdlib.h>

// OUTRA QUESTAO
// int* CriaVetInt(int qtde){   //alocacao de vetores do tipo int
//     int *vetint = malloc(sizeof(int)*qtde);
//     return vetint;
// }

// float* CriaVetFloat(int qtde){ //alocacao de vetores do tipo float
//     float *vetfloat = malloc(sizeof(float)*qtde);
//     return vetfloat;
// }

void inclui(char *pvetcar, int ptammax, char entrada){
    for(int i = 0; i < ptammax; i ++){
        if (pvetcar[i] == '\0'){
            pvetcar[i] = entrada;
            break;
        }
    }
}

void exclui(char *pvetcar, int ptammax, char entrada){
    for(int i = 0; i < ptammax; i ++){
        if (pvetcar[i] == entrada){
            pvetcar[i] = '\0';
            break;
        }
    }
}

int imprime(char *pvetcar, int ptammax){
    for (int i = 0; i < ptammax; i ++){
        printf("%c", pvetcar[i]);
    }
    printf("\n");
}

int main(){
    int ptammax;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &ptammax);
    char *pvetcar = malloc(sizeof(char)*ptammax);
    inclui(pvetcar, ptammax, 'i');
    inclui(pvetcar, ptammax, 'k');
    inclui(pvetcar, ptammax, 'a');
    inclui(pvetcar, ptammax, 'r');
    inclui(pvetcar, ptammax, 'o');
    inclui(pvetcar, ptammax, 's');
    inclui(pvetcar, ptammax, 's');
    imprime(pvetcar, ptammax);
    exclui(pvetcar, ptammax, 's');
    imprime(pvetcar, ptammax);


    //int pqtde;  //qtde atual de elementos de pvetcar -> incrementar ao scanf;
    
    return 0;
}