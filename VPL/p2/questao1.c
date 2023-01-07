#include <stdio.h>
int main(){
    int l, c, i, j, inicio, final, passagem=0, continua=0;
    scanf("%d" "%d",&l, &c);
    char caminho[l][c];
    for (i=0; i<l; i++){
        for (j=0; j<c; j++){
            scanf(" %c",&caminho[i][j]);
        }
    }
    for (i=0; i<l; i++){
        for (j=0; j<c; j++){
            if (caminho[i][j] == 'I'){
                inicio = i;
            }
            if (caminho[i][j] == 'F'){ 
                final = i;
            }
        }
    }
    if (final<inicio){
        for (i = inicio-1; i<=l; i--){
            if (continua>0){
                break;
            }
            for (j=0; j<c; j++){
                if (continua>0){
                break;
            }
                if (caminho[i][j] == 'B'){
                    passagem++;
                }
                if (caminho[i][j] == 'F'){
                    printf("S\n");
                    continua++;
                    break;
                }
            }
            if (passagem == 0){
                printf("N\n");
                continua++;
                break;
            }
            passagem = 0;
        }
    }
    if (final>inicio){
        for (i = inicio+1; i<=l; i++){
            if (continua>0){
                break;
            }
            for (j=0; j<c; j++){
                if (continua>0){
                    break;
                }
                if (caminho[i][j] == 'B'){
                    passagem++;
                }
                if (caminho[i][j] == 'F'){
                    printf("S\n");
                    continua++;
                    break;
                }
            }
            if (passagem == 0){
                printf("N\n");
                continua++;
                break;
            }
            passagem = 0;
        }
    }
    return 0;
}