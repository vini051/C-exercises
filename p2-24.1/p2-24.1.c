#include <stdio.h>

int Q1(char *Nome, int qtde){
	int pc=0;
	if (Nome[pc] == '\0')
		return qtde;
	while (Nome[pc] != '\0')
		pc++;	
	return Q1(Nome + 1, qtde + pc);
}

char letraCorrespondente(int P){
    P = P%25;
    return 'a' + P;
}
int Q2(char *NomeCompleto, int matricula){
    int p=0, pvez = 0;
    char chave = letraCorrespondente(matricula % 100);
    while (NomeCompleto[p] != '\0'){
        if (chave == NomeCompleto[p])
            pvez++;
        p++;
    }
    return pvez;
}

int Q3(char *Nome, int tamanho, int matricula){
    int inicio = 0, meio, fim = tamanho - 1, pcont = 0;
    char chave = Nome[matricula % 10];
    while (inicio <= fim){
        pcont++;
        meio = (inicio+fim)/2;
        if (chave == Nome[meio])
            break;
        else if (chave < Nome[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return pcont;
}

int faux(char *vet, int tam, int i){
    int j, min = i;
    for(j=i+1; j<tam; j++)
        if(vet[j] < vet[min])
            min = j;
    return min;
}
int Q4(char *vet, int tam){
    int i, min, aux, pcont = 0;
    for(i=0; i<tam; i++){
        min = faux(vet, tam, i);
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
        pcont = pcont + (tam - i);
    }
    return pcont;
}

int Q5(char vetor[], int tamanho){
    int pqtde = 0, j, i;
    char chave;
    for (i = 1; i < tamanho; i++){
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] < chave){
            vetor[j + 1] = vetor[j];
            j--;
            pqtde++;
        }
        vetor[j + 1] = chave;
    }
    return pqtde;
}

int main(){
    char q1[] = "brito";
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

    char q4[] = "vinicius gabriel rodrigues da silva brito";
    int q4qtde = 41; // ATENÇÃO! na questão é pedido que essa variável seja a quantidade de LETRAS do nome (36), porém quando eu fiz, utilizei a quantidade de CARACTERES (contando espaços). Para fins de correção vou ignorar, mas na prova preciso prestar atenção no que é pedido e realizar o cálculo com a variável correta.
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