#include <stdio.h>
int main (){
    int n, cont, div=1;
    scanf("%d",&n);
    for (cont=0; n>=div; div++){
        if ((n%div)==0){
        cont++;
        }
    }
    if (cont == 2){
        printf("primo\n");
    }
    else{
        printf("nao\n");
    }
    return 0;
}