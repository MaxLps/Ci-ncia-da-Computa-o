#include <stdio.h>
int main(){
    int t, i, n, num, fib[60];
    fib[0] = 0;
    fib[1] = 1;
    scanf("%d",&t);
    for (i=0; i<t; i++){
        scanf("%d",&n);
        if (n<0 || n>60){}
        if (n==0){
            printf("fib(%d) = %d\n",n,fib[0]);
        }
        if (n==1){
            printf("fib(%d) = %d\n",n,fib[1]);
        }
        else{
            for (num=2; num<=n; num++){
                fib[num] = fib[num-1] + fib[num-2];
                if (num==n){
                    printf("fib(%d) = %d\n",n,fib[num]);
                }
                
            }
        }
    }
    return 0;
}