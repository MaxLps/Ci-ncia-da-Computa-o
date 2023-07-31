#include <stdio.h>
int main(){
    char nome[200];
    int i;
    scanf("%s",nome);
    for (i=0; i<200; i++){
        if (nome[i]>=97){}
        else {
            if (nome[i]>=65 && nome[i]<=91){
                nome[i] = nome[i] + 32;
            }
        }
    }
        printf("%s\n",nome);
    return 0;
}