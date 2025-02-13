/*****************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
/*****************************************************************************************************************/
#define T1 TABP *novo = malloc(sizeof(TABP)); novo->Num = num; novo->Dir = novo->Esq = NULL; return novo;
#define T2 return raiz;
#define T3 return buscar(raiz->Esq, valor);
#define T4 return buscar(raiz->Dir, valor);
#define T5 liberarArvore(raiz->Esq);
#define T6 liberarArvore(raiz->Dir);
#define T7 raiz = inserir(raiz, num);
#define T8 imprimirInOrder(raiz->Esq);
#define T9 imprimirInOrder(raiz->Dir);
/*****************************************************************************************************************/
typedef struct node{
    int Num;
    struct node *Esq;
    struct node *Dir;
} TABP;

//Função para inserir um novo nó na ABP
TABP* inserir(TABP *raiz, int num){
    if(raiz == NULL){
        T1
    } else if (num < raiz->Num){
        raiz->Esq = inserir(raiz->Esq, num);
    } else {
        raiz->Dir = inserir(raiz->Dir, num);
    }
    T2
}

//Função para buscar um nó na ABP
TABP* buscar(TABP *raiz, int valor){
    if (raiz == NULL || raiz->Num == valor){
        return raiz;
    } else if (valor < raiz->Num){
        T3
    } else {
        T4
    }
}

//Função para liberar desalocar os nós da ABP
void liberarArvore(TABP *raiz){
    if (raiz != NULL){
        T5
        T6
        free(raiz);
    }
}

//Função para carregar os dados de um arquivo para a ABP
TABP* carregarDados(char *nomeArquivo){
    TABP *raiz = NULL;
    int num;
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL){
        printf("Erro ao abrir o arquivo!\n\n");
        return NULL;
    }
    while(fscanf(file, "%d", &num) != EOF)
        T7
    fclose(file);
    return raiz;
}

//Função para imprimir os valores do campo Num da ABP em ordem crescente
void imprimirInOrder(TABP *raiz){
    if (raiz != NULL){
        T8
        printf("%d, ", raiz->Num);
        T9
    }
}

void exibirMenu(){
    printf("\n--- Menu de Opções ---\n");
    printf("1. Carregar Dados\n");
    printf("2. Buscar\n");
    printf("3. Imprimir\n");
    printf("4. Encerrar\n");
}
int main(){
    setlocale(LC_ALL, "en_US.UTF-8");
    TABP *raiz = NULL;
    int opcao, valor;
    char nomeArquivo[100];
    do{
        exibirMenu();
        printf("Escolha uma opção: \n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("\nDigite o nome do arquivo para carregar os números: \n");
                scanf("%s", nomeArquivo);
                raiz = carregarDados(nomeArquivo); break;
            case 2:
                printf("\nDigite o valor a ser buscado: \n");
                scanf("%d", &valor);
                TABP *resultado = buscar(raiz, valor);
                if (resultado != NULL){
                    printf("\nValor encontrado: %d\n", resultado->Num);
                } else printf("\nValor não encontrado!\n");
                break;
            case 3:
                imprimirInOrder(raiz);
                break;
            case 4:
                liberarArvore(raiz);
                printf("\nÁrvore desalocada e programa encerrado.\n"); break;
            default:
                printf("\nOpção inválida!\n");
        } 
    } while (opcao != 4);
return 0; }