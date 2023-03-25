#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int vertice;
    struct no* proximo;
} No;

typedef struct grafo {
    int num_vertices;
    No** lista_adj;
} Grafo;

No* cria_no(int vertice) {
    No* no = (No*) malloc(sizeof(No));
    no->vertice = vertice;
    no->proximo = NULL;
    return no;
}

Grafo* cria_grafo(int num_vertices) {
    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));
    grafo->num_vertices = num_vertices;
    grafo->lista_adj = (No**) malloc(num_vertices * sizeof(No*));
    for (int i = 0; i < num_vertices; i++) {
        grafo->lista_adj[i] = NULL;
    }
    return grafo;
}

void adiciona_aresta(Grafo* grafo, int origem, int destino) {
    No* no = cria_no(destino);
    no->proximo = grafo->lista_adj[origem];
    grafo->lista_adj[origem] = no;

    no = cria_no(origem);
    no->proximo = grafo->lista_adj[destino];
    grafo->lista_adj[destino] = no;
}

void remove_no(Grafo* grafo, int vertice) {
    // iterar sobre a lista de adjacências do vértice a ser removido
    No* atual = grafo->lista_adj[vertice];
    while (atual != NULL) {
        int vertice_adjacente = atual->vertice;
        // remover a referência ao nó a ser removido na lista de adjacências do vértice adjacente
        No* aux = grafo->lista_adj[vertice_adjacente];
        if (aux->vertice == vertice) {
            grafo->lista_adj[vertice_adjacente] = aux->proximo;
            free(aux);
        } else {
            while (aux->proximo != NULL && aux->proximo->vertice != vertice) {
                aux = aux->proximo;
            }
            if (aux->proximo != NULL) {
                No* removido = aux->proximo;
                aux->proximo = removido->proximo;
                free(removido);
            }
        }
        atual = atual->proximo;
    }

    // remover o nó da lista de adjacências do grafo
    atual = grafo->lista_adj[vertice];
    while (atual != NULL) {
        No* removido = atual;
        atual = atual->proximo;
        free(removido);
    }
    grafo->lista_adj[vertice] = NULL;
}



void apaga_grafo(Grafo* grafo) {
    // percorre a lista de adjacências de cada vértice e remove todos os nós adjacentes
    for (int i = 0; i < grafo->num_vertices; i++) {
        remove_no(grafo, i);
    }

    // libera a memória alocada para cada lista de adjacências
    free(grafo->lista_adj);

    // libera a memória alocada para o grafo
    free(grafo);
}


void imprime_grafo(Grafo* grafo) {
    printf("Lista de adjacencia:\n");
    for (int i = 0; i < grafo->num_vertices; i++) {
        printf("%d: ", i);
        No* no = grafo->lista_adj[i];
        while (no != NULL) {
            printf("%d ", no->vertice);
            no = no->proximo;
        }
        printf("\n");
    }
}


int main() {
    clock_t inicio, fim;
    long double tempo;
    int num_vertices = 150, i, j, k;

    printf("TESTE GRAFO\n");

    inicio = clock();

    for(i=0; i<100; i++){
        Grafo* grafo = cria_grafo(num_vertices);   
        for (j = 0; j < num_vertices; j++) {
            for (k = 0; k < num_vertices; k++) {
                adiciona_aresta(grafo, j, k);
            }
            //imprime_grafo(grafo);
        }
        apaga_grafo(grafo);
    }


    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo malloc: %10Lf segundos\n", tempo);

    return 0;
}

