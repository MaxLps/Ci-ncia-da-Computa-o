#include <stdio.h>
int soma(int n[], int x){
    if (x == 1){
        return n[0];
    }
    else {
        return  n[x-1] + soma(n, x-1);
    }
}
int main(){
    int q, n[50], i, j, tam, r;
    scanf("%d",&q);
    for (i=0; i<q; i++){
        scanf("%d",&tam);
        for (j=0; j<tam; j++){
            scanf("%d",&n[j]);
        }
        r = soma(n, tam);
        printf("%d\n",r);
    }
    return 0;
}
