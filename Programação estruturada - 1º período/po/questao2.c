#include <stdio.h>
int main(){
    int a, b, x, i, j;
    scanf("%d",&x);
    for (i=0; i<100000; i++){
        for (j=0; j<100000; j++){
            a=i;
            b=j;
            if ( ((a*2) + (b*5)) == x){
                if (b>=1  a>= 7){
                    printf("%d %d\n",a, b);
                    i = 100001;
                    break;
                }
            }
        }
    }
    return 0;
}