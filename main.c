#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEncadeada.h"

int main() {
    TListaEncadeada lista;
    inicializar(&lista);

    char comando[10];

    while (scanf("%s", comando) == 1) {
        if (strcmp(comando, "-f") == 0) {
            break;
        } else if (strcmp(comando, "-s") == 0) {
            exibir(&lista);
        } else if (strcmp(comando, "-c") == 0) {
            esvaziar(&lista);
        } else if (strcmp(comando, "-t") == 0) {
            printf("Tamanho da lista: %d\n", tamanho(&lista));
        } else if (strcmp(comando, "-ii") == 0) {
            int x;
            scanf("%d", &x);
            inserirInicio(&lista, x);
        } else if (strcmp(comando, "-if") == 0) {
            int x;
            scanf("%d", &x);
            inserirFinal(&lista, x);
        } else if (strcmp(comando, "-i") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            inserirPosicao(&lista, x, y);
        } else if (strcmp(comando, "-r") == 0) {
            int x;
            scanf("%d", &x);
            removerValor(&lista, x);
        } else if (strcmp(comando, "-rp") == 0) {
            int x;
            scanf("%d", &x);
            removerPosicao(&lista, x);
        } else if (strcmp(comando, "-b") == 0) {
            int x;
            scanf("%d", &x);
            int pos = buscar(&lista, x);
            if (pos == -1) {
                printf("Elemento %d nao encontrado.\n", x);
            } else {
                printf("Elemento %d encontrado na posição %d.\n", x, pos);
            }
        }
    }

    esvaziar(&lista);
    return 0;
}