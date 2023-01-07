#include <stdio.h>
int main(){
    int n, i, p, menor; //p = posição
    scanf("%d",&n);
    int x[n];
    for (i=0; n>i; i++){
        scanf("%d",&x[i]);
    }
    menor = x[0];
    for (i=0; i<n; i++){
        if (x[i] < menor){
            menor = x[i];
            p = i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", menor, p);
    return 0;
}