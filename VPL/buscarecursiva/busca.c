#include <stdio.h>
int teste = 0;
int busca(int vetor[], int tam, int n){
    tam--;
    if (vetor[tam] == n){
    teste++;
    return tam;
    }
    else{
        return busca(vetor, tam, n);
    }
    if (teste == 0){
        return -1;
    }
}
int main(){
    int n, tam, i, b;
    scanf("%d",&n);
    scanf("%d",&tam);
    int vetor[tam];
    for (i=0; i<tam; i++){
        scanf("%d",&vetor[i]);
    }
    b = busca(vetor, tam, n);
    if (b<0){
        printf("-1\n");
    }
    else {
        printf("%d\n",b);
    }
    return 0;
}