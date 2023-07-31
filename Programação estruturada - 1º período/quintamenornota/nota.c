#include <stdio.h>
int main(){
    int n, i, j, aux, teste, troca;
    scanf("%d",&n);
    int nota[n];
    nota[0] = -1;
    if (n>5){
        for(i=0; i<n; i++){
            scanf("%d",&aux);
            teste = 0;
            for(j=0; j<=i; j++){
                if (aux==nota[j]){
                    teste++;
                    n--;
                }
            }
            if (teste==0){
                nota[i] = aux;
            }
            else {
                i--;
            }
        }
        do {
            troca = 0;
            for(i=0; i<n-1; i++){
                if (nota[i]>nota[i+1]){
                    aux = nota[i];
                    nota[i] = nota[i+1];
                    nota[i+1] = aux;
                    troca = 1;
                }
            }
            n--;
        }
        while (troca);
        printf("%d\n",nota[4]);
    }  
    return 0;
}