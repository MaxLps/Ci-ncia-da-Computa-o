#include <stdio.h>
int main(){
    int p1, qp1, p2, qp2;
    double valor1, valor2;
    scanf("%d",&p1);
    scanf("%d",&qp1);
    scanf("%lf",&valor1);
    scanf("%d",&p2);
    scanf("%d",&qp2);
    scanf("%lf",&valor2);
    printf ("VALOR A PAGAR: R$ %.2lf\n",(qp1*valor1)+(qp2*valor2));
    return 0;
}