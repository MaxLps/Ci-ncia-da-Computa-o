#include <stdio.h>
int main(){
    int q, n, i, j, m, s=110;
    float x, real[110], k,  prox, prox1, menor[110], menorv[110], mv;
    scanf("%d",&q);
    if(q>0 && q<=10){
        for (i=0; i<q; i++){
            scanf("%d %f",&n, &x);
            if (n>0 && n<100){
                for (j=0; j<n; j++){
                    scanf("%f",&real[j]);
                    if (real[j]>x){
                        for (k=real[j]; k<x; k = k - 0.1){
                            prox = k - real[j];
                        }
                        menor[j] = prox;
                        menorv[j] = real[j];
                    }
                    if (real[j]<=x){
                        for (k=real[j]; k<x; k = k + 0.1){
                            prox1 = k - real[j];
                        }
                        menor[j] = prox1;
                        menorv[j] = real[j];
                    }
                }
                for (m=0;m<q;m++){
                    if(menor[m]<=s){
                        mv = menor[m];
                        
                    }
                }
                printf("%.1f >:C\n",mv);
            }
        }
    }
    return 0;
}