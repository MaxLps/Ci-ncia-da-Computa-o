#include <stdio.h>
int aux1;
void sequencia(int vetor[], int n){
    int i, j, k, aux=1;
    vetor[0] = 0;
    for (i=1; i<=n; i++){
        j=0;
        for (k=i; j<k; j++){
            vetor[aux] = i;
            aux++;
        }
    }
    aux1 = aux;
}
int main(){
    int q, n, i, j, sequen[20101];
    scanf("%d",&q);
    for (i=1; i<=q; i++){
        scanf("%d",&n);
        if (n>=0 && n<=200){
            sequencia(sequen, n);
            if (n==0){
                printf("Caso %d: 1 numero\n0\n",i);
            }
            else {
                printf("Caso %d: %d numeros\n",i, aux1);
                for (j=0; j<aux1; j++){
                    printf("%d ",sequen[j]);
                }
                printf("\n");
            }
        }
        if (i<q){
            printf("\n");
        }
    }
    return 0;
}