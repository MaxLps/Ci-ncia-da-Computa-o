#include <stdio.h>
int main(){
    int n, i, soma=0, num; 
    char painel[50];
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%s",painel);
        if (soma!=0){
            printf("%d leds\n",soma);
            soma = 0;
        }
        for (num=0; painel[num]>=48 && painel[num]<=57 ; num++){
            if (painel[num]==48){
                soma = soma + 6;
            }
            if (painel[num]==49){
                soma = soma + 2;
            }
            if (painel[num]==50){
                soma = soma + 5;
            }
            if (painel[num]==51){
                soma = soma + 5;
            }
            if (painel[num]==52){
                soma = soma + 4;
            }
            if (painel[num]==53){
                soma = soma + 5;
            }
            if (painel[num]==54){
                soma = soma + 6;
            }
            if (painel[num]==55){
                soma = soma + 3;
            }
            if (painel[num]==56){
                soma = soma + 7;
            }
            if (painel[num]==57){
                soma = soma + 6;
            } 
        }
    }
    printf("%d leds\n",soma);
    return 0;
}