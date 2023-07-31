#include <stdio.h>
#define TAM 100
void insere_heap(int h[], int* ultm, int x){
    int aux;
    if(*ultm == 0){
        *ultm = 1;
        h[*ultm] = x;
    }
    else{
        *ultm = *ultm + 1;
        aux = *ultm;
        while(aux/2 && h[aux/2] < x){
            h[aux] = h[aux/2];
            aux = aux/2;
        }
        h[aux] = x;
    }
}
void imprime_heap(int h[], int* ultm){
    int i;
    printf("Vetor:\n");
    for(i=1; i<=*ultm; i++){
        printf("| %d ",h[i]);
    }
    printf("|\n");
}
int main(){
    int heap[TAM], x, i, zero=0;
    int* ultimo = &zero;
    for(i=0; i<10; i++){
        scanf("%d",&x);
        insere_heap(heap, ultimo, x);
    }
    imprime_heap(heap, ultimo);
    return 0;
}