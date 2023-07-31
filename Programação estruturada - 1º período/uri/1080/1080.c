#include <stdio.h>
int maiorp(int vetor[], int n){
    int i, aux=0, indiceM;
    for(i=0; i<n; i++){
        if(vetor[i] > aux){
            aux = vetor[i];
            indiceM = i;
        }
    }
    return indiceM;
}
int main(){
    int maior[100], i, indieceM;
    for(i=0; i<100; i++){
        scanf("%d",&maior[i]);
    }
    indieceM = maiorp(maior, 100);
    printf("%d\n%d\n",maior[indieceM], indieceM+1);
    return 0;
}