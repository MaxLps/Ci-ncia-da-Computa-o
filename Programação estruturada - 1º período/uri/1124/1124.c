#include <stdio.h>
#include <math.h>
double hipotenusa(double L, double C){
    double h;
    h = sqrtf(pow(L,2) + pow(C,2));
    return h;
}
int parada(double L, double C, double R1, double R2){
    if(L==0 && C==0 && R1==0 && R2==0){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    double h, L, C, R1, R2, verticalN1, verticalN2;
    int p=1;
    while(p){
        scanf("%lf",&L); scanf("%lf",&C); scanf("%lf",&R1); scanf("%lf",&R2);
        p = parada(L, C, R1, R2);
        if(p==0){
            break;
        }
        if(L>=1 && L<=100 && C>=1 && C<=100 && R1>=1 && R1<=100 && R2>=1 && R2<100){
            verticalN1 = hipotenusa(R1, R1) + R1;
            verticalN2 = hipotenusa(R2, R2) + R2;
            h = hipotenusa(L, C);
            if(h >= verticalN1 + verticalN2){
                printf("%lf >= %lf\n", h , verticalN1 + verticalN2);
                printf("S\n");
            }
            //if(){
                printf("%lf >= %lf\n", h , verticalN1 + verticalN2);
                printf("N\n");
            }
        }
    //}
    return 0;
}