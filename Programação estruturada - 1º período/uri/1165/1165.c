#include <stdio.h>
int TestePrimo(int n){
    int i, cont=0;
    for (i=1; i<=n; i++){
        if (n%i==0){
            cont++;
        }
    }
    return cont;
}
int main(){
    int q, i, n;
    scanf("%d",&q);
    for (i=0; i<q; i++){
        scanf("%d",&n);
        if (TestePrimo(n) == 2){
            printf("%d eh primo\n",n);
        }
        else{
            printf("%d nao eh primo\n", n);
        }
    }
    return 0;
}