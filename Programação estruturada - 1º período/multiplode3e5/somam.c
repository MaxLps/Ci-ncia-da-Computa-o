#include <stdio.h>
int main(){
    int x, cont, aux, soma=0;
    scanf("%d",&x);
    if (x==0){
        printf("0\n");
    }
    else{
        x--;
        aux = x;
        for(cont=0; cont!=aux; cont++){
            if (x%3==0 && x!=1){
                soma = soma + x;
            }
            if (x%5==0 && x!=1){
                soma = soma + x;
            }
            if ((x%3==0) && (x%5==0)){
             soma = soma - x;
                }
            x--;
        }
    
        printf("%d\n",soma);
    }
    return 0;
}