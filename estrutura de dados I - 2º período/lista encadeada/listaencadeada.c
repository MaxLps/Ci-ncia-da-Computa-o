#include <stdio.h>
#include <stdlib.h>
struct lista{
    int info;
    struct lista* prox;
};
typedef struct lista Lista;
Lista* lst_cria(){
    return NULL;
}
Lista* lst_insere(Lista* lst, int n){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = n;
    novo->prox = lst;
    return novo;
}
void lst_imprime(Lista* lst){
    Lista* aux;
    for(aux = lst; aux!=NULL; aux = aux->prox){
        printf("| %d | ",aux->info);
    }
    printf("\n");
    free(aux);
}
Lista* lst_remove(Lista* l, int n){
    Lista* aux = l;
    Lista* ant = NULL;
    while(aux != NULL && aux->info != n){
       ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL){
        return l;
    }
    if(ant == NULL){
        l = aux->prox;
    }
    else{
        ant->prox = aux->prox;
    }
    free(aux);
    return l;
}
int main(){
    int n, remove;
    int i;
    Lista* lista;
    lista = lst_cria();
    printf("Digite os elementos da lista\n");
    for(i=0; i<10; i++){
        scanf("%d",&n);
        lista = lst_insere(lista,n);
    }
    lst_imprime(lista);
    printf("Quem você quer remover da lista?\n");
    scanf("%d",&remove);
    lista = lst_remove(lista,remove);
    lst_imprime(lista);
    return 0;
}