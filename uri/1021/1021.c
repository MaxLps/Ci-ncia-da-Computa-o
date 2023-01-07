#include <stdio.h>
int main(){
    int p, o, m, g, a, t, umr, cc, vc, dc, cinc, umc; //100, 50, 20, 10, 5, 2, 1, 0.50, 0.25, 0.10, 0.05, 0.01
    double dinheiro;
    scanf("%lf",&dinheiro);
    if (0<=dinheiro && dinheiro<=1000000){
        p = dinheiro/100;
        o = (dinheiro-p*100)/50;
        m = (dinheiro-p*100-o*50)/20;
        g = (dinheiro-p*100-o*50-m*20)/10;
        a = (dinheiro-p*100-o*50-m*20-g*10)/5;
        t = (dinheiro-p*100-o*50-m*20-g*10-a*5)/2;
        umr = (dinheiro-p*100-o*50-m*20-g*10-a*5-t*2)/1;
        cc = (dinheiro-p*100-o*50-m*20-g*10-a*5-t*2-umr*1)/0.50;
        vc = (dinheiro-p*100-o*50-m*20-g*10-a*5-t*2-umr*1-cc*0.50)/0.25;
        dc = (dinheiro-p*100-o*50-m*20-g*10-a*5-t*2-umr*1-cc*0.50-vc*0.25)/0.10;
        cinc = (dinheiro-p*100-o*50-m*20-g*10-a*5-t*2-umr*1-cc*0.50-vc*0.25-dc*0.10)/0.05;
        umc = (dinheiro-p*100-o*50-m*20-g*10-a*5-t*2-umr*1-cc*0.50-vc*0.25-dc*0.10-cinc*0.05)/0.01;
        printf ("NOTAS:\n");
        printf ("%d nota(s) de R$ 100.00\n",p);
        printf ("%d nota(s) de R$ 50.00\n",o);
        printf ("%d nota(s) de R$ 20.00\n",m);
        printf ("%d nota(s) de R$ 10.00\n",g);
        printf ("%d nota(s) de R$ 5.00\n",a);
        printf ("%d nota(s) de R$ 2.00\n",t);
        printf ("MOEDAS:\n");
        printf ("%d moeda(s) de R$ 1.00\n",umr);
        printf ("%d moeda(s) de R$ 0.50\n",cc);
        printf ("%d moeda(s) de R$ 0.25\n",vc);
        printf ("%d moeda(s) de R$ 0.10\n",dc);
        printf ("%d moeda(s) de R$ 0.05\n",cinc);
        printf ("%d moeda(s) de R$ 0.01\n",umc);
    }
    return 0;
}