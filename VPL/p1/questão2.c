#include <stdio.h>
int main(){
    int x, i, n, j, zero=0;
    scanf("%d",&x);
    if (x<=10){
        for (i=0; i<x; i++){
            j = 0;
            scanf("%d",&n);
            if (n>0 && n<100){
                if (n == 1){
                    printf("0\n");
                }
                else{
                    if (n<100 && n>0){
                        do {
                            if (n%2 == zero){
                                n = n/2;
                                j++;
                            }
                            else {
                                if (n!=1){
                                    n = 3*n+1;
                                    j++;
                                }
                            }
                        }   
                        while (n!=1);
                        printf("%d\n",j);
                    }
                }
            }
        }
    }
    return 0;
}