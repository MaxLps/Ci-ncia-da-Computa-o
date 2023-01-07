#include <stdio.h>
#define TAM 12
int main(){
    char operacao;
    int i, j, aux = 0, cont = 0;
    float matriz[TAM][TAM];
    scanf("%c",&operacao);
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            scanf("%f",&matriz[i][j]);
        }
    }
    for(i=0; i<TAM; i++){
        for(j=i+1; j<TAM; j++){
           aux = aux + matriz[i][j];
           cont++;
        }
    }
    if(operacao == 'S'){
        printf("%d\n",aux);
    }
    if(operacao == 'M'){
        printf("%d\n",aux/cont);
    }
    return 0;
}