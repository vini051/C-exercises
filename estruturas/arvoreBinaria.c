#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int info;
    struct No *esquerda;
    struct No *direita;
} No;

typedef struct Arv {
    No *raiz;
} Arv;

No *criaNo(int info){
    No *novo = malloc(sizeof(No));
    novo->info = info;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

Arv *criaArv(int info){
    Arv *arv = malloc(sizeof(Arv));
    arv->raiz->info = info;
    arv->raiz->esquerda = arv->raiz->direita = NULL;
}

void insereEsq(int info, Arv *arv){
    No *novoesq = criaNo(info);
    arv->raiz->esquerda = novoesq;
}

void insereDir(int info, Arv *arv){
    No *novodir = criaNo(info);
    arv->raiz->direita = novodir;
}

void imprimeArv(Arv *arv){
    No *aux;
    aux = arv->raiz;
    if (aux == NULL)
        return;
    printf("Nó: %d\n", aux->info);
    imprimeArv(arv);   
    imprimeArv(arv);   
}

int main(){

    return 0;
}