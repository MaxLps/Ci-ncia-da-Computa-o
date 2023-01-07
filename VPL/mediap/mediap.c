#include <stdio.h>
int main (){
    int n, cont;
    double media, valor1, valor2, valor3;
    scanf("%d",&n);
    for (cont=0; cont!=n; cont++){
        scanf("%lf",&valor1);
        scanf("%lf",&valor2);
        scanf("%lf",&valor3);
        media = ((valor1*2)+(valor2*3)+(valor3*5))/10;
        printf("%.1lf\n",media);
    }
    return 0;
}