#include <stdio.h>

int Q1(char *Nome, int qtde){
	int i=0;
	if (*Nome == '\0')
		return qtde;
	while (Nome[i] != '\0')
		i++;	
	return Q1(Nome + 1, qtde + i);
}

char letraCorrespondente(int P){
    P = P % 26;
    return 'a' + P;
}
int Q2(char *NomeCompleto, int matricula){
    int p=0, ret = 0;
    char chave = letraCorrespondente(matricula % 100);
    while (NomeCompleto[p] != '\0'){
        if (chave == NomeCompleto[p])
            ret += p;
        p++;
    }
    return ret;
}

int Q3(char *Nome, int tamanho, int matricula){
    int inicio = 0, meio, fim = tamanho - 1, pcont = 0;
    char chave = Nome[matricula % 10];
    while (inicio <= fim){
        pcont++;
        meio = (inicio + fim) / 2;
        if (chave == Nome[meio])
            break;
        else if (chave < Nome[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return pcont;
}

int Q4(char *vet, int tam){
    int i, j, pcont = 0;
    char aux;
    for(i = 0; i < tam; i++)
        for (j = i+1; j < tam; j++)
            if (vet[i] < vet[j]){
                aux = vet[i]; vet[i] = vet[j]; vet[j] = aux; pcont++;
            }
    return pcont;
}

int Q5(char vetor[], int tamanho){
    int trocas = 0, j, i;
    char chave;
    for (i = 1; i < tamanho; i++){
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j--;
            trocas++;
        }
        vetor[j + 1] = chave;
    }
    return trocas;
}

/*A questão 6 deu muito trabalho portanto não vou mantê-la aqui*/

int main(){
    char q1[] = "vinicius";
    int q1qtde = 0;

    int respostaQ1 = Q1(q1, q1qtde);
    printf("Resposta Q1: %d\n\n", respostaQ1);

    char q2[] = "vinicius gabriel rodrigues da silva brito";
    int q2matricula = 180028847;

    int respostaQ2 = Q2(q2, q2matricula);
    printf("Resposta Q2: %d\n\n", respostaQ2);

    char q3[] = "     aaabbcddeeggiiiiiiillnoorrrrssstuuvv";
    int q3tamanho = 41;
    int q3matricula = 180028847;

    int respostaQ3 = Q3(q3, q3tamanho, q3matricula);
    printf("Resposta Q3: %d\n\n", respostaQ3);

    char q4[] = "vinicius";
    int q4qtde = 8;
    int q4R = Q4(q4, q4qtde);

    printf("Resposta Q4:\n");
    printf("Valor de R: %d\n", q4R);
    printf("Valor de Nome: %s\n\n", q4);

    char q5[] = "brito";
    int q5qtde = 5;
    int q5R = Q5(q5, q5qtde);

    printf("Resposta Q5:\n");
    printf("Valor de R: %d\n", q5R);
    printf("Valor de Nome:%s\n\n", q5);

    return 0;
}