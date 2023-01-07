#include <stdio.h>
int main(){
    int q, i, troca, aux, aux2, aula;
    int inicio[1000], fim[1000];
    scanf("%d",&q);
    for (i=0; i<q; i++){
        scanf("%d %d",&inicio[i], &fim[i]);
    }
    do {
        troca = 0;
        for (i=0; i<q-1; i++){
            if (fim[i] > fim[i+1]){
                aux = fim[i];
                aux2 = inicio[i];
                fim[i] = fim[i+1];
                inicio[i] = inicio[i+1];
                fim[i+1] = aux;
                inicio[i+1] = aux2;
                troca = 1;
            }
        }
        q--;
    }
    while (troca);
    aula = q;
    for (i=1; i<q; i++){
        if (fim[0]>=inicio[i]){
            aula--;
        }
    }    
    printf("%d\n",aula);
    return 0;
}