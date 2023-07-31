#include <stdio.h>
int main(){
    int dinheiro, p, o, m, g, a, t, pp; //100, 50, 20, 10, 5, 2 e 1
    scanf("%d",&dinheiro);
    printf("%d\n",dinheiro);
    p = dinheiro/100;
    printf("%d nota(s) de R$ 100,00\n",p);
    o = (dinheiro-p*100)/50;
    printf("%d nota(s) de R$ 50,00\n",o);
    m = (dinheiro-p*100-o*50)/20;
    printf("%d nota(s) de R$ 20,00\n",m);
    g = (dinheiro-p*100-o*50-m*20)/10;
    printf("%d nota(s) de R$ 10,00\n",g);
    a = (dinheiro-p*100-o*50-m*20-g*10)/5;
    printf("%d nota(s) de R$ 5,00\n",a);
    t = (dinheiro-p*100-o*50-m*20-g*10-a*5)/2;
    printf("%d nota(s) de R$ 2,00\n",t);
    pp = (dinheiro-p*100-o*50-m*20-g*10-a*5-t*2)/1;
    printf("%d nota(s) de R$ 1,00\n",pp);
    return 0;
}