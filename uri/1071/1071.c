#include <stdio.h>
int main (){
    int x, aux, y, soma;
    scanf("%d",&x);
    scanf("%d",&y);
    if (x>y){
        aux = x;
        x = y;
        y = aux;
    }
    if (x%2 == 0){
        x++;
    }
    if (y%2 == 0){
        if (y<0){
            y++;
        }
        else{
            y--;
        }
    }
    if (x+2 == y){
        printf("%d\n",x);
    }
    else{
        for (soma = 0 ;x<y; soma = x ){
            x = x + 2;
        }
        printf("%d\n",soma);
    }
    return 0;
}