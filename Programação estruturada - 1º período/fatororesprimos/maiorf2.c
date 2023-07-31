#include <stdio.h>
int main(){
    long long int n; //=600851475143;
    int cont, div, aux;
    scanf("%lld",&n);
    for (div=1; div<n; div++){
        aux = 1;
        for(cont=0; div>=aux; aux++){
            if (div%aux==0){
                cont++;
            }
            if (cont==2){
                while (div%n==0){
                    n = n/div;
                    printf("%lld*\n",n);
                }
            }
        }
    }
    printf("%d\n",div);   
    return 0;
}