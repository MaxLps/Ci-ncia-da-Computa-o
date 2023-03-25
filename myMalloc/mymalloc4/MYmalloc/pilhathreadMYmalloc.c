#include <stdio.h>
#include <pthread.h>
#include "mymalloc.h"
#include "mymalloc.c"

typedef struct elemento {
    int valor;
    struct elemento* proximo;
} Elemento;

typedef struct pilha {
    Elemento* topo;
} Pilha;

Pilha* cria_pilha() {
    Pilha* pilha = (Pilha*)MYmalloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void push(Pilha* pilha, int valor) {
    Elemento* novo_elemento = (Elemento*) MYmalloc(sizeof(Elemento));
    novo_elemento->valor = valor;
    novo_elemento->proximo = pilha->topo;
    pilha->topo = novo_elemento;
}

int pop(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("Erro: Pilha vazia.\n");
        exit(1);
    }
    Elemento* elemento_removido = pilha->topo;
    int valor = elemento_removido->valor;
    pilha->topo = elemento_removido->proximo;
    MYfree(elemento_removido);
    return valor;
}

void imprime_pilha(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia.\n");
    } else {
        printf("Pilha:");
        Elemento* elemento_atual = pilha->topo;
        while (elemento_atual != NULL) {
            printf(" %d", elemento_atual->valor);
            elemento_atual = elemento_atual->proximo;
        }
        printf("\n");
    }
}

void apaga_pilha(Pilha* pilha) {
    while (pilha->topo != NULL) {
        Elemento* elemento_removido = pilha->topo;
        pilha->topo = elemento_removido->proximo;
        MYfree(elemento_removido);
    }
    MYfree(pilha);
}

void *teste(void *arg){
    int i, j, n=2, m=20;      //n = quantidade de pilhas   m = quantiade de elementos
    for (i = 1; i <= n; i++){
        arg = cria_pilha();
        for (j = 1; j <= m; j++) {
            push(arg, j);
            //printf("%p\n",pilha1);
        }
        imprime_pilha(arg);
        //apaga_pilha2(pilha1);
        //printf("\n");
    }
}

int main(){
    pthread_t p1, p2;
    clock_t inicio, fim;
    long double tempo;
    Pilha* pilha1;
    Pilha* pilha2;
    inicio = clock();
        pthread_create(&p1, NULL, teste, pilha1);
        pthread_create(&p2, NULL, teste, pilha2);
        pthread_join(p1, NULL);
        pthread_join(p2, NULL);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo malloc: %Lf segundos\n", tempo);
}

