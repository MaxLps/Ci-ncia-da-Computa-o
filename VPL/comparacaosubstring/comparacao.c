#include <stdio.h>
int rept(char frase1[50], char frase2[50]){
    int i, j, k, cont=0, teste;
    char iguais[200];
    for (i=0; frase1[i]!='\0'; i++){
        for (j=0; frase2[j]!='\0'; j++){
            if (frase1[i] == frase2[j] && frase1[i] != 10){
                iguais[i] = frase1[i];
                printf("%d iguais\n",iguais[i]);
                teste = 0;
                for (k=0; iguais[k]!='\0'; k++){
                    if(iguais[k] == iguais[i]){
                        teste++;
                    }
                }
                if(teste==0){
                cont++;
                }
            }
        }
    }
    return cont;
}
int main(){
    char frase1[50], frase2[50], lixo;
    int repeticao;
    fgets(frase1, 50, stdin);
    //scanf("%c",&lixo);
    fgets(frase2, 50, stdin);
    //scanf("%c",&lixo);
    repeticao = rept(frase1, frase2);
    printf("%d\n", repeticao--);
    return 0;
}