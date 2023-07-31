#include <stdio.h>
int main(){
int numero;
printf("Digite um número\n");
scanf("%d",&numero);
if (numero%2 == 0){
    printf("%d é par\n", numero);}
else{
    printf("%d é impar",numero);}
    return 0;
}