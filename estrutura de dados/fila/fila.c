#include <stdio.h>
#include <stdlib.h>
struct fila{
    int info;
    struct fila* prox;
};
typedef struct fila Fila;
Fila* fila_cria(){
    return NULL;
}
Fila* fila_insere(Fila* fila, int n){
    Fila* novo = (Fila*)malloc(sizeof(Fila));
    Fila* f = fila;
    if(fila != NULL ){
        while(fila->prox != NULL){
            fila = fila->prox;
        }
        novo->prox = fila->prox;
        novo->info = n;
        fila->prox = novo;
        return f;
    }
    else{
        novo->info = n;
        novo->prox = fila;
        return novo;
    }
}
Fila* fila_remove(Fila* fila, int* n){
    Fila* f = fila;
    *n = f->info;
    fila = f->prox;
    free(f);
    return fila;
}
void imprime_fila(Fila* fila){
    Fila* f = fila;
    while(f != NULL){
        printf("| %d | ",f->info);
        f = f->prox;
    }
    printf("\n");
}
int main(){
    int i, n, aux;
    int* retirado;
    Fila* fila = fila_cria();
    printf("Qual é o tamanho da fila?\n");
    scanf("%d",&n);
    printf("Insira os elementos da fila\n");
    for(i=0; i<n; i++){
        scanf("%d",&aux);
        fila = fila_insere(fila, aux);
    }
    imprime_fila(fila);
    printf("Quantos elementos devem ser removidos?\n");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        fila = fila_remove(fila, retirado);
        imprime_fila(fila);
        printf("retirado: %d\n\n",*retirado);
    }
    return 0;
}