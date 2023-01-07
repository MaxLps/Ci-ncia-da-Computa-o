#include <stdio.h>
int main(){
    int n, cont, menor1=11, nota, aux, menor2=11;
    scanf("%d",&n);
    for (cont=0; cont!=n; cont++){
        scanf("%d",&nota);
        if (nota<0 || nota>10){
            nota = 0;
        }
        else{
            if ((nota == menor1) || (nota == menor2)){
                nota = nota + 0;
            }
            else {
                if (nota<menor2){
                menor2= nota;
                }
                if (menor1>menor2){
                    aux = menor1;
                    menor1 = menor2;
                    menor2 = aux;
                }
            }
        }
    }
    printf("%d\n",menor2);
    return 0;
}