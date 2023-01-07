#include <stdio.h>
int main(){
    int n, i, j, k, x, teste=0, fib[47];
    scanf("%d",&n);
    if (n<=10){
        fib[0] = 0;
        fib[1] = 1;
        for (i=2; i<47; i++){
            fib[i] = fib[i-1] + fib[i-2];
        }
        for (j=0; j<n; j++){
            scanf("%d",&x);
            if (x<1079741824){
                teste = 0;
                for (k=0; k<48; k++){
                    for (i=0; i<48; i++){
                        if (fib[k] + fib[i] == x){
                        teste++;
                        }
                    }
                }
                if (k==48 && teste == 0){
                    printf("N\n");
                }
                if (k==48 && teste>0){
                    printf("S\n");
                }
            }   
        }
    }
    return 0;
}