#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento* proximo;
} Elemento;

typedef struct pilha {
    Elemento* topo;
} Pilha;

Pilha* cria_pilha() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void push(Pilha* pilha, int valor) {
    Elemento* novo_elemento = (Elemento*) malloc(sizeof(Elemento));
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
    free(elemento_removido);
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
        free(elemento_removido);
    }
    free(pilha);
}



int main(){
    clock_t inicio, fim;
    long double tempo;
    int i, j, n=10000, m=640000; //n = quantidade de listas   m = tamanho das lista

    printf("TESTE PILHA:\n\n");
    inicio = clock();

       for (i = 1; i <= n; i++){
            Pilha *pilha = cria_pilha();
            for (j = 1; j <= m; j++) {
                push(pilha, j);
                //printf("%p\n",pilha2);
            }
            //imprime_pilha(pilha1);
            apaga_pilha(pilha);
            //printf("\n");
        }
    
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo malloc: %10Lf segundos\n", tempo);  
    return 0;
}