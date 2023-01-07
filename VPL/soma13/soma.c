#include <stdio.h>
int main(){
    int x, y, cont, inic, soma=0, aux;
    scanf("%d %d",&x,&y);
    if (x>=y){
        inic = x;
        aux = y;
        cont = y;
    }
    else{
        inic = y;
        aux = x;
        cont = x;
    }
    for (; cont<=inic; cont++){
        if ((aux%13)!=0){
            soma = soma + aux;
        }
        aux = aux + 1;
    }
    printf("%d\n",soma);
    return 0;
}