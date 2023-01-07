#include <stdio.h>
int main(){
    double salario, imposto;
    scanf("%lf",&salario);
    if (salario<=2000){
        printf("Isento\n");
    }
    if (salario<=3000 && salario>2000){
        imposto = (salario - 2000) * 0.08;
        printf("R$ %.2lf\n",imposto);
    }
    if (salario>3000 && salario<=4500){
        salario = (salario - 2000);
        imposto = (1000 * 0.08) + (salario-1000) * 0.18; 
        printf("R$ %.2lf\n",imposto);
    }
    if (salario>4500){
        salario = salario - 2000;
        imposto = 1000 * 0.08;          
        imposto = imposto + 1500 * 0.18; 
        imposto = imposto + (salario - 2500) * 0.28;
        printf("R$ %.2lf\n",imposto);
    }
    return 0;
}