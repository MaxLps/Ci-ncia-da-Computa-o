#include <stdio.h>
int main(){
    int x, y, tempo;
    scanf("%d %d",&x, &y);
    if (x==y){
        printf("O JOGO DUROU 24 HORA(S)\n");
    }
    if (x>y){
        tempo = (24-x) + y;
        printf("O JOGO DUROU %d HORA(S)\n",tempo);
    }
    if (x<y){
        tempo = y-x;
        printf("O JOGO DUROU %d HORA(S)\n",tempo);
    }
    return 0;
}