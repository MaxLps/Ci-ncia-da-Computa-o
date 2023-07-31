#include <stdio.h>
int main(){
    int n, i, j, diaA, mesA, diaH, mesH, anoH, dias=0, aux;
    int mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //janeiro=0 fevereiro=1 ...
    scanf("%d",&n);
    if (n<=10){
        for (i=0; i<n; i++){
        scanf("%d %d, %d %d %d",&diaA, &mesA, &diaH, &mesH, &anoH);
        mesA--;
        mesH--;
            if (mesH<mesA){
                dias = mes[mesH]-diaH;
                aux = mes[mesA] - diaA;
                dias = dias + mes[mesA] - aux;
                if (mesH<=1 && anoH%4==0 && mesA>=1){
                    dias++;
                }
                printf("%d\n",dias);
            }
            if (mesH<mesA){
                dias = 365;
                dias = dias + mes[mesH]-diaH;
                dias = dias + mes[mesA] - aux;
                if (mesH<=1 && anoH%4==0 && mesA>=1){
                    dias++;
                }
                printf("%d\n",dias);
            }
            if (mesA==mesA){
                if(diaA>=diaH){
                    dias = diaA - diaH;
                    printf("%d\n",dias);
                }
                if (diaA<diaH){
                    dias = 365;
                    dias = dias + (diaA - diaH);
                    if (mesH<=1 && anoH%4==0 && mesA>=1){
                        dias++;
                    }
                    printf("%d\n",dias);
                }
            }
        }
    }
    return 0;
}