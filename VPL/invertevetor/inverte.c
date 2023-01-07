#include <stdio.h>
int main(){
    int n, i;
    scanf("%d",&n);
    int x[n];
    if (n>1 && n<1000){
        for (i=0; i<n; i++){
            scanf("%d",&x[i]);
        }
        i--;
        for (;i>=0; i--){
            printf("%d ",x[i]);
        }
    }
    return 0;
}