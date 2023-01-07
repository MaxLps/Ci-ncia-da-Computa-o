#include <stdio.h>
int main(){
    int n, cont, nota, a=0;
    scanf("%d",&n);
    for (cont=0;cont!=n;cont++){
        scanf("%d",&nota);
        if (nota<0 || nota>10){
            cont--;
            nota = 0;
        }
        else{
            if(nota>=5){
                a++;
            }
        }
    }
    printf("%d\n",a);
    return 0;
}