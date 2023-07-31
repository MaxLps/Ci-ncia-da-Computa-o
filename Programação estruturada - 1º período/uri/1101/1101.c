#include <stdio.h>
int main(){
    int m, n, i, soma=0;
    scanf("%d%d",&m,&n);
    if (m<=0 || n<=0){
    }
    else{
        if (m>n){
            for (i=n; i<=m; i++){
                printf("%d ",i);
                soma = soma + i;
            }
        }
        if (n>m){
            for (i=m; i<=n; i++){
                printf("%d ",i);
                soma = soma + i;
            }
        }
        printf("Sum=%d\n",soma);
    }
    return 0;
}