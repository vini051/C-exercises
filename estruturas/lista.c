#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int info;
    struct no *prox;
}No;

typedef struct lista {
    No *inicio;
}Lista;

Lista* criaLista(){
    Lista *lista = malloc(sizeof(Lista));

    if (lista == NULL)
        fprintf(stderr, "Falha na alocação de memória para a lista\n");

    lista->inicio = NULL;
    
    return lista;
}

bool isEmpty(Lista *lista){
    if (lista->inicio == NULL)
        return true;
    else 
        return false;
}

void insereInicio(int info, Lista *lista){
    No *no = malloc(sizeof(No));
    
    if (no == NULL)
        fprintf(stderr, "Falha na alocação de memória para o nó\n");

    no->info = info;
    no->prox = lista->inicio;
    lista->inicio = no;
}

void insereFim(int info, Lista *lista){
    if (isEmpty(lista)){
        insereInicio(info, lista);
    } else {
        No *no = malloc(sizeof(No));
        no->info = info;

        No *aux = lista->inicio; 

        while (aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = no;
        no->prox = NULL;
    }
}

int getTamanho(Lista *lista){
    int count = 0;
    No *aux = lista->inicio;
    while(aux != NULL){
        aux = aux->prox;
        count ++;
    }
    return count;
}

No *buscaNo(int info, Lista *lista){
    No *aux = lista->inicio;
    int count = 0,
        tamanhoLista = getTamanho(lista);
    bool encontrado = false;

    for (int i = 0; i < tamanhoLista; i ++){
        count ++;
        
        if (aux->info == info){
            encontrado = true;
            break;
        }

        aux = aux->prox;
    }

    if (encontrado){
        printf("O primeiro nó que contém o dado %d é o %dº nó da lista.\n", info, count);
        return aux;
    }

    else printf("Não foi encontrado um nó com o dado %d.\n", info);
}

void imprimeLista(Lista *lista){
    if (isEmpty(lista)){
        printf("A lista está vazia.\n");
        return;
    }

    No *aux = lista->inicio;
    while(aux != NULL){
        printf("%d", aux->info);
        
        if (aux->prox != NULL)
            printf(" -> ");
        
        aux = aux->prox;
    }
    printf("\n");
}

//TODO: implementar funções de remoção da lista

void removeElemento(int info, Lista *lista){
    
    if(isEmpty(lista)){
        printf("A lista está vazia.\n");
        return;
    }

    No *aux = lista->inicio;
    int tamanhoLista = getTamanho(lista);
    bool encontrado = false;

    if ( /* tamanhoLista == 1 && */ aux->info == info){
        encontrado = true;
        lista->inicio = aux->prox;
        free(aux);
        aux = NULL;
        printf("O nó que continha o dado %d foi removido do início da lista.\n", info);
        return;
    }

    for (int i = 0; i < tamanhoLista; i ++){
        if (aux->prox != NULL && aux->prox->info == info){
            encontrado = true;
            No *rmv = aux->prox;
            aux->prox = aux->prox->prox;
            free(rmv);
            rmv = NULL;
            printf("O nó que continha o dado %d foi removido.\n", info);
            break;
        }
        aux = aux->prox;
    }

    if (!encontrado)
        printf("Não foi encontrado um nó com o dado %d para ser removido.\n", info);
}

int main(){
    Lista *lista1 = criaLista();
    insereInicio(5, lista1);
    imprimeLista(lista1);
    insereInicio(6, lista1);
    imprimeLista(lista1);
    insereFim(6, lista1);
    imprimeLista(lista1);
    buscaNo(5, lista1);
    buscaNo(6, lista1);
    buscaNo(13, lista1);
    removeElemento(6, lista1);
    imprimeLista(lista1);
    removeElemento(6, lista1);
    imprimeLista(lista1);
    removeElemento(13, lista1);
    removeElemento(5, lista1);
    imprimeLista(lista1);
    removeElemento(13, lista1);
    imprimeLista(lista1);
    
    return 0;
}