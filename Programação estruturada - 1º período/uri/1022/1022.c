#include <stdio.h>

void simplificacao(int* n, int* d){
    int i;
    for(i=2; i<=*n && i<=*d; i++){
        while((*n % i == 0) && (*d % i == 0)){
            *n = *n/i;
            *d = *d/i;
        }
    }
}
int main(){
    int numerador, denominador;
    int* n=&numerador;
    int* d=&denominador;
    scanf("%d""%d",&numerador,&denominador);
    simplificacao(n,d);
    printf("%d / %d\n",numerador, denominador);
    return 0;
}