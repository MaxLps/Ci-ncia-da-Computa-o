#include <stdio.h>
int main (){
    int n, cont, nota, aux;
    double notat=0;
    double media;
    scanf("%d",&n);
    for (cont=0;cont<n; cont++){
        scanf("%d",&nota);
        if (nota<0 || nota>10){
            nota = 0;
            cont--;
            n--;
        }
        notat = notat + nota;
    }
    media = notat/n;
    printf("%.1lf\n", media);
    return 0;
}