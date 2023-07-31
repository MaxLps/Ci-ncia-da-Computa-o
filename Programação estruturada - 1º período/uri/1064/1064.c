#include <stdio.h>
int main(){
    int i, positivo=0;
    float n, soma=0, media;
    for (i=0; i<6; i++){
        scanf("%f",&n);
        if (n>0){
            positivo++;
            soma = soma + n;
        }
    }
    media = soma/positivo;
    printf("%d valores positivos\n%.1f\n", positivo, media);
    return 0;
}