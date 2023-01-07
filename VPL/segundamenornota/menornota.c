#include <stdio.h>
int main(){
    int n, cont, nota, aux1=11, aux2=11, aux3;
    scanf("%d",&n);
    for (cont=0; cont!=n; cont++){
        scanf("%d",&nota);
        if (nota<0 || nota>10){
            cont--;
        }
        else{
            if(aux1>nota){
                aux1 = nota;
            }
            if(aux1<aux2){
                aux2 = aux1;
            }
        }
    }
    if(aux1<aux2){
        printf("%d\n",aux1);
    }
    else{
        printf("%d\n",aux2);
    }
    return 0;
}