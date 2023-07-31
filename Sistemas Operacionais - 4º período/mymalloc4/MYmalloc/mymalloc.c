#include "mymalloc.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO_BLOCO sizeof(bloco_de_memoria) //Definindo tamanho do bloco


Bloco *lista = (Bloco*) NULL; //Criando lista para gerenciar os blocos livres

void percorreLista(Bloco *lst){
    Bloco *aux = lst;
    int i=1;
    if(aux == NULL){
        printf("\nLista de blocos livre Vazia\n");
    }
    else{
        while(aux != NULL){
            printf("\nnó: %d\nEndereço: %p\nTamanho: %d\n\n",i,aux, aux->tamanho);
            aux = aux->prox;
            i++;
        }
    }
}

void *MYmalloc(int q_memoria) {
    void *endereco = NULL; // variável que guarda o endereço de memória
    Bloco *bloco_atual, *bloco_anterior, *bloco_novo = NULL;
    
    // percorre a lista de blocos livres procurando um bloco com tamanho suficiente
    for (bloco_atual = lista, bloco_anterior = NULL; bloco_atual != NULL; bloco_anterior = bloco_atual, bloco_atual = bloco_atual->prox) {
        if (bloco_atual->tamanho >= q_memoria){                                                // encontrou um bloco livre com tamanho suficiente
            if (bloco_atual->tamanho > q_memoria ) {
                bloco_novo = (Bloco *)((char *)bloco_atual + q_memoria + TAMANHO_BLOCO);      // cria um novo bloco livre
                bloco_novo->tamanho = bloco_atual->tamanho - q_memoria;
                bloco_novo->prox = bloco_atual->prox;
            }
            bloco_atual->tamanho = q_memoria;
            endereco = (void *)(bloco_atual + 1);
        }
        // remove o bloco da lista de blocos livres
        if (bloco_novo != NULL) {
            if (bloco_anterior != NULL) {
                bloco_anterior->prox = bloco_novo;
            } 
            else {
                lista = bloco_novo;
            }
            break;
        }
        else {
            if (bloco_anterior != NULL) {
                bloco_anterior->prox = bloco_atual->prox;
            } 
            else {
                lista = bloco_atual->prox;
            }
            break;
        }
    }
    // se não encontrou um bloco livre com tamanho suficiente, aloca um novo bloco de memória
    if (bloco_atual == NULL) {
        bloco_novo = (Bloco *)sbrk(TAMANHO_BLOCO + q_memoria);
        //printf("Chamou sbrk\n");
        if (bloco_novo == (void *)-1) {
            printf("sbrk falhou\n");
            return NULL;
        }
        
        bloco_novo->tamanho = q_memoria;
        bloco_novo->prox = NULL;
        endereco = (void *)(bloco_novo + 1);
    }
    
    return endereco;
}

void MYfree(void *endereco) {
    Bloco *bloco_atual = (Bloco*)endereco - 1;
    bloco_atual->prox = lista;
    lista = bloco_atual;
}

