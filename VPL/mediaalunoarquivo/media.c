#include <stdio.h>
#include <stdlib.h>
int main (){
    FILE *a;
    a = fopen ("arquivo.txt", "r");
    int n, i;
    char nome[50];
    double nota1, nota2, media;
    if (a == NULL){
        perror("Erro ao abrir o arquivo.\n");
        return 1;
    }
    else {
        fscanf(a, "%d", &n);
        for (i=0; i<n; i++){
            media = 0;
            fgets(nome, 50, a);
            fscanf(a, "%lf ",&nota1);
            fscanf(a, "%lf ",&nota2);
            media = (nota1 + nota2)/2;
            if (media>7){
                printf("%s",nome);
            }
        }
    }
    fclose(a);
    return 0;
}