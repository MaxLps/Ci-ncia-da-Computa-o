#include <stdio.h>

void calcular_nota(){
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
}

int cont(int x){
    printf("novo calculo (1-sim 2-nao)\n");
    scanf("%d",&x);
    if(x==1){
        return x;
    }
    if(x==2){
        return x;
    }
    return cont(x);
}

int main(){
    int x=1;
    while(x==1){
        calcular_nota();
        x = cont(x);
    }
    return 0;
}