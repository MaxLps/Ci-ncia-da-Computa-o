#include <stdio.h>
int main(){
    int i, positivo=0;
    float n;
    for (i=0; i<6; i++){
        scanf("%f",&n);
        if (n>0){
            positivo++;
        }
    }
    printf("%d valores positivos\n", positivo);
    return 0;
}