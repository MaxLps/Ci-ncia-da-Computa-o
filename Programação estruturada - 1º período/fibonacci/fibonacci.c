#include <stdio.h>
int main(){
    int n, cont,f, x=1, y=2, z, soma=2;
    scanf("%d",&n);
    while (f<n){
        z = x + y;
        x = y;
        y = z;
        f = z;
        if (z>n){
            break;
        }
        if (z%2==0){
            soma = soma + z;
        }
    }
    printf("%d\n",soma);
    return 0;
}