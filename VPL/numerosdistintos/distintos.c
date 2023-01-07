#include <stdio.h>
int main(){
    int n, i, ii;
    scanf("%d",&n);
    int x[n];
    for (i=0; i<n; i++){
        scanf("%d",&x[i]);
        for (ii=-1; ii<i; ii++){
            if (x[i]==x[ii]){
                scanf("%d",&x[i]);
                ii=-1;
            }
        }
        printf("%d ",x[i]);
    }
    return 0;
}