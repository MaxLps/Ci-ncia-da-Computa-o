#include <stdio.h>
int teste_quadrante(int x, int y){
    if(x>0 && x!=0 && y!=0){
        if(y>0){
            printf("primeiro\n");
        }
        else{
            printf("quarto\n");
        }
    }
    else{
        if(x!=0 && y!=0){
            if(y>0){
                printf("segundo\n");
            }
            else{
                printf("terceiro\n");
            }
        }
    }
    if(x==0 || y==0){
        if(x>0){
            
        }
    }
    return 1;
}
int main(){
    int x, y;
    do{
        scanf("%d %d",&x,&y);
    }
    while(teste_quadrante(x,y));
    return 0;
}