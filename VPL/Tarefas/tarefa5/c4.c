#include <stdio.h>
int main(){
    float cm, m, dm;
    printf("Digite o comprimento em centimetros\n");
        scanf("%f",&cm);
    dm = cm/10;
    m = dm/10;
    printf("%.2f metros\n%.2f decímetros\n%.2f centímetros\n",m,dm,cm);
    return 0;
}