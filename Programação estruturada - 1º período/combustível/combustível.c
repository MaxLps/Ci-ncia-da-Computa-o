#include <stdio.h>
int main (){
    int tempo, velocidade;
    double km;
    double combustivel;
    scanf("%d", &tempo);
    scanf("%d", &velocidade);
    km = tempo*velocidade;
    combustivel = km/12;
    printf("%.3lf", combustivel);
    return 0;
}