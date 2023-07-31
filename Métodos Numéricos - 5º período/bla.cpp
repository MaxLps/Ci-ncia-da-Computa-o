#include <stdio.h>

int main(){
    int n = 1000;
    double h = 0.001;
    double aux=0;
    double x = 0;
    double vet[1000];
    int i;
    for(i=0; i<n+1; i++){
        x = x + h;
        vet[i] = x * x;
    }
    for(i=1;i<n; i++){
        aux = aux + vet[i];
    }
    aux = aux + vet[0] + vet[n];
    aux = aux * (h/2);
    printf("\n%lf\n",aux);
}