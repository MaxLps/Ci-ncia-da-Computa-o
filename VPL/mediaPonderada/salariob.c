#include <stdio.h>
int main(){
    char nome[20];
    double salario, vendas, montante;
    printf("Qual é o seu nome?\n");
        scanf("%s",nome);
    printf("Olá, %s. Qual é o seu salário fixo?\n", nome);
        scanf("%lf",&salario);
    printf("Qual foi o seu total de vendas?\n");
        scanf("%lf",&vendas);
    montante = salario+(0.15*vendas);
    printf("TOTAL = R$ %.2lf\n", montante);
    return 0;
}