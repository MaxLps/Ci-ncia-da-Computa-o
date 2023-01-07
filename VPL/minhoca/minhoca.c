#include <stdio.h>
int main(){
    int n, i, j, k=0;
    scanf("%d",&n);
    char caminho[n][n];
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            scanf(" %c",&caminho[i][j]);
        }
    }
    int inicio=0, fim=n-1, aux=1;
    while (aux <= n*n){
        for (i=inicio; i<=fim; i++){
            aux++;
            if (caminho[inicio][i]!='o'){
                k++;
            }
            else {
                aux = n*n+1;
                break;
            }
        }
        for (i=inicio+1; i<=fim; i++){
            aux++;
            if (caminho[i][fim]!='o'){
                k++;
            }
            else {
                aux = n*n+1;
                break;
            }
        }
        for (i=fim-1; i>=inicio; i--){
            aux++;
            if (caminho[fim][i]!='o'){
                k++;
            }
            else {
                aux = n*n+1;
                break;
            }
        }
        for (i=fim-1; i>=inicio+1; i--){
            aux++;
            if (caminho[i][inicio]!='o'){
                k++;
            }
            else {
                aux = n*n+1;
                break;
            }
        }
        inicio++;
        fim--;
    }
    
    printf("%d\n",k);
    /*printf("\n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf("%c",caminho[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}