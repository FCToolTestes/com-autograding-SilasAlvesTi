#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} TListaEncadeada;

void inicializar(TListaEncadeada* lista);
void exibir(TListaEncadeada* lista);
void esvaziar(TListaEncadeada* lista);
void inserirInicio(TListaEncadeada* lista, int valor);
void inserirFinal(TListaEncadeada* lista, int valor);
void inserirPosicao(TListaEncadeada* lista, int valor, int posicao);
void removerValor(TListaEncadeada* lista, int valor);
int removerPosicao(TListaEncadeada* lista, int posicao);
int buscar(TListaEncadeada* lista, int valor);
int tamanho(TListaEncadeada* lista);

#endif