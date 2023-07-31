#include <stdio.h>
int main(){
    float salarioA, salario;
    scanf("%f",&salarioA);
    if (salarioA>=0){
        if (salarioA>=0 && salarioA<=400){
        salario = (salarioA * 0.15) + salarioA;
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 15 %%\n",salario, salario-salarioA);
        }
        if (salarioA>400 && salarioA<=800){
        salario = (salarioA * 0.12) + salarioA;
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 12 %%\n",salario, salario-salarioA);
        }
        if (salarioA>800 && salarioA<=1200){
        salario = (salarioA * 0.10) + salarioA;
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 10 %%\n",salario, salario-salarioA);
        }
        if (salarioA>1200.00 && salarioA<=2000){
        salario = (salarioA * 0.07) + salarioA;
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 7 %%\n",salario, salario-salarioA);
        }
        if (salarioA>2000){
        salario = (salarioA * 0.04) + salarioA;
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 4 %%\n",salario, salario-salarioA);
        }
    }
    return 0;
}