#include <stdio.h>


int main(){
    FILE *a;
    a = fopen ("arquivo.txt", "r");
    int c=0, p=0, f=0, aa=0;
    char caract;
    if (a == NULL){
        perror("Erro ao abrir o arquivo.\n");
        return 1;
    }
    else{
        while(fscanf(a, "%c", &caract) != EOF){
            if (caract!=32 && caract!=46){
                c++;
            }
            if (caract == 32 || caract == 46 || caract == 44 || caract == 46){
                p++;
            }
            if (caract == 46){
                f++;
            }
        }
    }
    printf("%d %d %d %d\n",c, p-1, f, aa);
    return 0;
}