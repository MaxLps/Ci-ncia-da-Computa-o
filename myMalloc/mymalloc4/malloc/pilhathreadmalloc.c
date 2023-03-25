#include <stdio.h>
#include <pthread.h>
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

void *teste(void *arg){
    int i, j, n=20, m=20;      //n = quantidade de pilhas   m = quantiade de elementos
    for (i = 1; i <= n; i++){
        arg = cria_pilha();
        for (j = 1; j <= m; j++) {
            push(arg, j);
            //printf("%p\n",pilha1);
        }
        //imprime_pilha(arg);
        apaga_pilha(arg);
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
    
    return 0;
}






/*#define SIZE 10

int v[SIZE];

void *function(void *arg){
    int *valor = (int*)(arg);
    if( *valor == 1){
        printf("thread 1 executando\n");
        for(int i=0; i< SIZE/2; i++){
            v[i] = 1;
        }
    }
    else{
        printf("thread 2 executando\n");
        for(int i = SIZE/2; i<SIZE; i++){
            v[i] = 2;
        }
    }
}

int main(){
    pthread_t t1, t2;
    int a1 = 1, a2 = 2;

    pthread_create(&t1, NULL, function, (void*)(&a1));
    pthread_create(&t2, NULL, function, (void*)(&a2));
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;

}*/