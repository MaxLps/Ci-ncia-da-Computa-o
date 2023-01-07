#include <stdio.h>
int main(){
    int quantidade, lanche; 
    double valor;
    scanf("%d %d",&lanche, &quantidade);
    switch (lanche*1){
        case 1:
        valor = 4.00;
        break;
        case 2:
        valor = 4.50;
        break;
        case 3:
        valor = 5.00;
        break;
        case 4:
        valor = 2.00;
        break;
        case 5:
        valor = 1.50;
        break;
    }
    valor = valor * quantidade;
    printf("Total: R$ %.2lf\n",valor);
    return 0;
}