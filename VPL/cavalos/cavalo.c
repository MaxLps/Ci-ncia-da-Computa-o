#include <stdio.h>
int main(){
    int i, j, prancha, protegidos=0, posicao;
    int baia[50];
    for (i=0; i<=49; i++){
        baia[i] = 0;
    }
    baia[2] = 1;
    baia[3] = 1;
    baia[5] = 1;
    baia[7] = 1;
    baia[11] = 1;
    baia[13] = 1;
    baia[17] = 1;
    baia[19] = 1;
    baia[23] = 1;
    baia[29] = 1;
    baia[31] = 1;
    baia[37] = 1;
    baia[41] = 1;
    baia[43] = 1;
    baia[47] = 1;
    for (i=0; i<=49; i++){
        prancha = 0;
        for (j=0; j<20; j++){
            prancha = prancha + baia[j];
        }
        if(prancha>protegidos){
            protegidos = prancha;
            posicao = i;
        }
    }
    printf("Maior = %d inicio %d\n", protegidos, posicao);
    return 0;
}