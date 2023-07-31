#include <stdio.h>

int main(){
    int i=0;
    float nota=0, aux;
    while(i!=2){
        scanf("%f",&aux);
        if(aux>=0 && aux<=10){
            i++;
            nota += aux;
        }
        else{
            printf("nota invalida\n");
        }
    }
    printf("media = %.2f\n",nota/2);
    return 0;
}