#include <stdio.h>
#include <math.h>
#define pi 3.14159
int main(){
    double a, raio;
    scanf("%lf",&raio);
    a = pow(raio,2)*pi;
    printf("A=%.4lf\n",a);
    return 0;
}