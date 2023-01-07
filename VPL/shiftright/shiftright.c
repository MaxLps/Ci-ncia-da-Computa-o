#include <stdio.h>
int main(){
    int n, i, aux;
    scanf("%d",&n);
    int numero[n];
    if (n>5){
        for(i=0; i<n; i=i+2){
            scanf("%d",&numero[i]);
        }
        aux = numero[0];
        numero[0] = numero[n-1];
        numero[n-1] = aux;
        for (i=0; i<n; i++){
            printf("%d ",numero[i]);
        }
    }
    printf("\n");
    return 0;
}