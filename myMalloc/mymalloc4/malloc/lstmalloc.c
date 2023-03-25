#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* criaLista(){
    return NULL;
}

Lista* insereLista(Lista* lst, int x){
    Lista* novo = (Lista*) malloc(sizeof(Lista));         
    novo->info = x;                                                                                              
    novo->prox = lst;               
    return novo;                    
}

void apagaLista(Lista* lst) {
    Lista* prox = lst;
    while(lst != NULL){
        prox = lst->prox;
        free(lst);
        lst = prox;
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

        for (i =  1; i <= n; i++){
            Lista *lista = criaLista();
            for (j = 1; j <= m; j++) {
                lista = insereLista(lista, j);
                //printf("%p\n",lista2);
            }
            //imprimeLista(lista2);
            apagaLista(lista);
            //printf("\n");
        }
    
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo malloc: %10Lf segundos\n", tempo); 
    return 0;
}