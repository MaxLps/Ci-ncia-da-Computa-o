#include <stdio.h>
int organizador(int v[], int l){
    int i, j, aux, troca=0, cont=0;
    do {
        troca = 0;
        for (i=0; i<l-1; i++){
            if (v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                troca = 1;
                cont++;
            }
        }
        l--;
    }
    while (troca);
    return cont;
}
int main(){
    int q, n, i, j, l, s, vagao[50];
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d",&l);
        for (j=0; j<l; j++){
            scanf("%d",&vagao[j]);
        }
        s = organizador(vagao, l);
        printf("Optimal train swapping takes %d swaps.\n",s);
    }
    return 0;
}