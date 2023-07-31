#include <stdio.h>
int main(){
    int numero, horas;
    float valor, salario;
    scanf("%d",&numero);
    scanf("%d",&horas);
    scanf("%f",&valor);
    salario = valor * horas;
    printf("NUMBER = %d\nSALARY = U$ %.2f\n",numero, salario);
    return 0;
}