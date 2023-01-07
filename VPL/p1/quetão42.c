#include <stdio.h>
int main(){
    int q, n, i, j, k, sim=0, nao=0;
    float x, real[110], distancia[110], mdistancia=110;
    scanf("%d",&q);
    if(q>0 && q<=10){
        for (i=0; i<q; i++){
            scanf("%d %f",&n, &x);
            if (n>0 && n<100){
                for (j=0; j<n; j++){
                    scanf("%f",&real[j]);
                    if (real[j]>=x){
                        distancia[j] = real[j]-x;
                        }
                    if (real[j]<=x){
                        distancia[j] = x - real[j];
                    }
                }
                mdistancia=110;
                sim = 0;
                for (k=0;k<n;k++){
                    if (distancia[k] < mdistancia){
                        mdistancia = distancia[k];
                        sim++;
                    }
                }
                printf("%.1f\n",real[sim-1]);
            }
        }
    }    
    return 0;
}