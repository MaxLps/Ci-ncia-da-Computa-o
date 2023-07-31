#include <stdio.h>
int main(){
    double a, b, c, aux, area;
    scanf("%lf %lf %lf",&a, &b, &c);
    if (a>0 && b>0 && c>0){
        if (a<b){
            aux = b;
            b = a;
            a = aux;
        }
        if (b<c){
            aux = c;
            c = b;
            b = aux;
        }
        if (a<b){
            aux = a;
            a = b;
            b = aux;
        }
        if (a >= b+c){
            area = ((a+b)*c)/2;
            printf("Area = %.1lf\n",area);
        }
        else{
            printf("Perimetro = %.1lf\n",a+b+c);
        }
    }
    return 0;
}