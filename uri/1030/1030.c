#include <stdio.h>
#include <stdlib.h>
struct LC{
    int info;
    int posicao;
    struct LC* prox;
};
typedef struct LC lc;
lc* criaLC(){
    return NULL;
}
lc* insereLC(lc* lista, int posicao, int n){
    lc* novo = (lc*) malloc(sizeof(lc));
    novo->info = 1;
    novo->posicao = posicao;
    if(lista == NULL){
        novo->prox = novo;
    }
    else{
        novo->prox = lista->prox;
        lista->prox = novo;
    }
    if(posicao==n){
        lc* novo1 = (lc*) malloc(sizeof(lc));
        novo1->info = 10;
        novo1->posicao = 0;
        novo1->prox = novo->prox;
        novo->prox = novo1;
        return novo1;
    }
    return novo;
}
lc* morre(lc* lista, int k){
    lc* aux;
    aux = lista;
    int i=0;
    while(i!=k){
        if(aux->info == 1){
            //printf("%d\n",aux->posicao);
            i++;
        }
        if(i==k){
            //printf("%d\n",aux->posicao);
            aux->info = 0;
            break;
        }
        aux = aux->prox;
    }
    return aux;
}
int parada(lc* lista, int n, int* ind){
    int i, cont=0;
    lc* aux = lista;
    for(i=0; i<n; i++){
        if(aux->info == 1){
            cont++;
            ind = aux->posicao;
        }
        aux = aux->prox;
    }
    printf("TESTE :C %d\n", cont);
    if(cont > 1){
        return 1;
    }
    else{
        return 0;
    }
}
void imprime(lc* lista){
    lc* aux = lista;
    int i = 1;
    while(i!=6){
        printf("indice:%d = %d\n",aux->posicao, aux->info);
        aux = aux->prox;
        i++;
    }
    printf("\n");
}
int main(){
    int q, n, k, i, j, indice=0, p=1;
    int* ind = &indice;
    lc* Josephus;
    scanf("%d",&q);
    for(i=0; i<q; i++){
        Josephus = criaLC();
        scanf("%d %d",&n, &k);
        for(j=n; j!=0; j--){
            Josephus = insereLC(Josephus, j, n);
        }
        Josephus = morre(Josephus, k);
        imprime(Josephus);
        Josephus = morre(Josephus, k);
        imprime(Josephus);
        Josephus = morre(Josephus, k);
        imprime(Josephus);
        Josephus = morre(Josephus, k);
        imprime(Josephus);
        Josephus = morre(Josephus, k);
        imprime(Josephus);
        /*while(p){
            Josephus = morre(Josephus, k);
            //imprime(Josephus);
            p = parada(Josephus, n, ind);
        }
        printf("case %d: %d",q+1, indice);*/
    }
    return 0;
}