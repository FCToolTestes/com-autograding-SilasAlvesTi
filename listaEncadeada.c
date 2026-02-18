#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

void inicializar(TListaEncadeada* lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void exibir(TListaEncadeada* lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    printf("Lista:");
    No* atual = lista->inicio;
    while (atual != NULL) {
        printf(" %d", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

void esvaziar(TListaEncadeada* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserirInicio(TListaEncadeada* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}

void inserirFinal(TListaEncadeada* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No* atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    lista->tamanho++;
}

void inserirPosicao(TListaEncadeada* lista, int valor, int posicao) {
    if (posicao <= 1) {
        inserirInicio(lista, valor);
        return;
    }
    if (posicao > lista->tamanho + 1) {
        posicao = lista->tamanho + 1;
    }

    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;

    No* atual = lista->inicio;
    for (int i = 1; i < posicao - 1; i++) {
        atual = atual->proximo;
    }
    novo->proximo = atual->proximo;
    atual->proximo = novo;
    lista->tamanho++;
}

void removerValor(TListaEncadeada* lista, int valor) {
    No* atual = lista->inicio;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == valor) {
            No* proximo = atual->proximo;
            if (anterior == NULL) {
                lista->inicio = proximo;
            } else {
                anterior->proximo = proximo;
            }
            free(atual);
            lista->tamanho--;
            atual = proximo;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

int removerPosicao(TListaEncadeada* lista, int posicao) {
    if (lista->inicio == NULL || posicao < 1 || posicao > lista->tamanho) {
        return -1;
    }

    No* atual = lista->inicio;
    No* anterior = NULL;

    for (int i = 1; i < posicao; i++) {
        anterior = atual;
        atual = atual->proximo;
    }

    int valor = atual->dado;

    if (anterior == NULL) {
        lista->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    lista->tamanho--;
    return valor;
}

int buscar(TListaEncadeada* lista, int valor) {
    No* atual = lista->inicio;
    int posicao = 1;

    while (atual != NULL) {
        if (atual->dado == valor) {
            return posicao;
        }
        atual = atual->proximo;
        posicao++;
    }
    return -1;
}

int tamanho(TListaEncadeada* lista) {
    return lista->tamanho;
}