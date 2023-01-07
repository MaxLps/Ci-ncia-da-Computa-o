#include <stdio.h>
#include <stdlib.h>
struct elemento{
    int info;
    struct elemento* prox;
};
typedef struct elemento Elemento;
struct pilha{
    Elemento* topo;
};
typedef struct pilha Pilha;
Pilha* pilha_cria(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}
void pilha_push(Pilha* p, int n){
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->info = n;
    novo->prox = p->topo;
    p->topo = novo;
}
int pilha_pop(Pilha* p){
    Elemento* aux;
    int n;
    aux = p->topo;
    n = aux->info;
    p->topo = aux->prox;
    return n;
}
void imprime_pilha(Pilha* pilha){
    int aux;
    Pilha* p = pilha_cria(); 
    printf("\n");
    if(pilha->topo == NULL){
        printf("VAZIA\n");
    }
    while(pilha->topo != NULL){
        aux = pilha_pop(pilha);
        printf("| %d |\n",aux);
        pilha_push(p, aux);
    }
    while(p->topo != NULL){
        pilha_push(pilha, pilha_pop(p));
    }
    free(p);
}
int main(){
    Pilha* pilha = pilha_cria();
    int i, n, aux;
    printf("Qual é o tamanho da pilha?\n");
    scanf("%d",&n);
    printf("Insira os elementos da pilha\n");
    for(i=0; i<n; i++){
        scanf("%d",&aux);
        pilha_push(pilha, aux);
    }
    imprime_pilha(pilha);
    printf("Quantos elementos devem ser removidos?\n");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        aux = pilha_pop(pilha);
        imprime_pilha(pilha);
        printf("retirado: %d\n",aux);
    }
    return 0;
}