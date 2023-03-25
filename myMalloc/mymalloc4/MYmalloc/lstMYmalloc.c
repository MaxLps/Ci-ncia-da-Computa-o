#include <stdio.h>
#include <time.h>
#include "mymalloc.h"
#include "mymalloc.c"

struct lista{
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* criaLista(){
    return NULL;
}

Lista* insereLista(Lista* lst, int x){
    Lista* novo = (Lista*) MYmalloc(sizeof(Lista));  //criando novo nó     
    novo->info = x;                                  //novo nó recebendo valor                                                                         
    novo->prox = lst;                                //novo nó apontando para o antigo primeiro nó |novo2|  ->  |novo1|  ->  NULL
    return novo;                                     //retorna endereço do novo nó               
}


void apagaLista(Lista* lst) {
    Lista* prox = lst;
    while(lst != NULL){                             //verifica se o nó é NULL (lista vazia)   
        prox = lst->prox;                           //prox receve o endereço do prox nó
        MYfree(lst);                                //livera o nó atual 
        lst = prox;                                 //lst recebe o nó seguinte
    }
}

void imprimeLista(Lista* lst){
    Lista* aux = lst;
    while(aux != NULL){                             //verifica se o nó é NULL (lista vazia)
        printf("| %d |  ->  ",aux->info);           //imprime valor do nó
        aux = aux->prox;                            //aux recebe endereço do nó seguinte
    }
    printf("NULL\n");
}


int main(){
    clock_t inicio, fim;
    long double tempo;
    int i, j, n=10000, m=20000; //n = quantidade de listas   m = tamanho das lista


    printf("TESTE LISTA ENCADEADA\n");

    inicio = clock();
        
        for (i = 1; i <= n; i++){
            Lista *lista1 = criaLista();
            for (j = 1; j <= m; j++) {
                lista1 = insereLista(lista1, j);
                //printf("%p\n",lista1);
            }
            //imprimeLista(lista1);
            apagaLista(lista1);
            //printf("\n");
        }
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo MYmalloc: %Lf segundos\n", tempo);
    
    //percorreLista(lista);  
    return 0;
}