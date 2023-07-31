#include <stdio.h>
#include <math.h>
int main(){
    double raio, volume;
    scanf("%lf",&raio);
    raio = pow(raio,3);
    volume = (4.0/3.0)*3.14159*raio;
    printf("VOLUME = %.3lf\n",volume);
    return 0;
}