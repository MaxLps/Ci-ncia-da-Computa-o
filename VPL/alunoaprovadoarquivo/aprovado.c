#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *a;
    char nome[50], fim;
    double nota1, nota2, media;
    int i, j, k;
    a = fopen("arquivoo.txt", "r");
    if (a == NULL){
        perror("Erro ao abrir o arquivo.\n");
        return 1;
    }
    else {
        while(fscanf(a, "%c", &fim) != EOF){
            for (j=0; j<50; j++){
                fscanf(a, "%c", &nome[j]);
                if(nome[j] ==';'){
                    break;
                }
            }
            fscanf(a, "%lf; ",&nota1);
            fscanf(a, "%lf; ",&nota2);
            media = (nota1 + nota2)/2;
            printf("%c",fim);
            for (k=0; nome[k]!=';'; k++){
                printf("%c",nome[k]);
            }
            printf(" %.1lf ",nota1);
            printf("%.1lf ",nota2);
            printf("%.1lf ",media);
            if(media>=5){
                printf("aprovado\n");
            }
            else{
                printf("reprovado\n");
            }
        }
    }
    fclose(a);
    return 0;
}