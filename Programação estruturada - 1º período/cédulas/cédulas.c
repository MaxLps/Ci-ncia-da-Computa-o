#include <stdio.h>
int main(){
    int dinheiro, p, o, m, a, g, t, pp;
    scanf("%d",&dinheiro);
    p = dinheiro/100;
    o = (dinheiro-(p*100))/50;
    m = (dinheiro-(p*100)-(o*50))/20;
    a = (dinheiro-(p*100)-(o*50)-(m*20))/10;
    g = (dinheiro-(p*100)-(o*50)-(m*20)-(a*10))/5;
    t = (dinheiro-(p*100)-(o*50)-(m*20)-(a*10)-(g*5))/2;
    pp = dinheiro-(p*100)-(o*50)-(m*20)-(a*10)-(g*5)-(t*2);
    printf("%d\n%d nota(s) de R$100,00\n%d nota(s) de R$50,00\n%d nota(s) de R$20,00\n%d nota(s) de R$10,00\n%d nota(s) de R$5,00\n%d nota(s) de R$2,00\n%d nota(s) de R$1,00\n",dinheiro,p, o, m, a, g, t, pp);
    return 0;
}