#include <stdio.h>
int main(){
    int m, f1, f2, f3, aux;
    scanf("%d",&m);
    scanf("%d",&f1);
    scanf("%d",&f2);
    f3 = m - (f1+f2);
    if (f1>f2){
        aux = f2;
        f2 = f1;
        f1 = aux;
    }
    if (f2>f3){
        aux = f3;
        f3 = f2;
        f2 = aux;
    }
    if (f1>f2){
        aux = f2;
        f1 = f2;
        f2 = aux;
    }
    printf("%d\n",f3);
    return 0;
}