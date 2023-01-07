#include <stdio.h>
int main(){
    int n, numero, i;
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d",&numero);
        if (numero == 0){
            printf("NULL\n");
        }
        if (numero%2 == 0){
            if (numero > 0){
            printf("EVEN POSITIVE\n");
            }
            if (numero < 0) {
                printf("EVEN NEGATIVE\n");
            }
        }
        if (numero%2 != 0){
            if (numero < 0){
                printf("ODD NEGATIVE\n");
            }
            if (numero > 0){
                printf("ODD POSITIVE\n");
            }
        }
    }
    return 0;
}