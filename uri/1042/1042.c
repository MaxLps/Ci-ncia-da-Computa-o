#include <stdio.h>
int main(){
    int a, b, c, d, e, f, aux;
    scanf("%d %d %d",&a, &b, &c);
    d = a;
    e = b;
    f = c;
    if (a>b){
        aux = b;
        b = a;
        a = aux;
    }
    if (b>c){
        aux = c;
        c = b;
        b = aux;
    }
    if (a>b){
        aux = a;
        a = b;
        b = aux;

    }
    printf("%d\n%d\n%d\n\n",a, b, c);
    printf("%d\n%d\n%d\n",d, e, f);
    return 0;
}