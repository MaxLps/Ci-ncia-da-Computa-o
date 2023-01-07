#include <stdio.h>
int main (){
    int a, b, c, d, e, aux, exc=1, cont;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);
    if (a>b && a>c && a>d && a>e){
        printf("%d\n%d\n",a,exc);
    }
    else{
        for (cont=1; a<b || a<c || a<d || a<e; cont++){
            aux = b;
            b = a;
            a = aux;
            aux = c;
            c = b;
            b = aux;
            aux = d;
            d = c;
            c = aux;
            aux = e;
            e = d;
            d = aux;
        }
        printf ("%d\n%d\n",cont,a);
    }
    return 0;
}