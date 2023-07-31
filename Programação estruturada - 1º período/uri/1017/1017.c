#include <stdio.h>
int main(){
    double tempo, velocidade, combustivel;
    scanf("%lf %lf",&tempo, &velocidade);
    combustivel = (tempo*velocidade)/12;
    printf("%.3lf\n",combustivel);
    return 0;   
}