#include <stdio.h>
int main(){
    int anos,  dias, meses;
    printf("Digite o número de dias\n");
        scanf("%d",&dias);
    anos = dias/365; 
    meses = (dias%365)/30;
    dias = (dias%365)-(meses*30);
    printf("%d ano(s)\n%d mese(s)\n%d dia(s)",anos, meses, dias);
    return 0;
}