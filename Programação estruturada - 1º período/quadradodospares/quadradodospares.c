#include <stdio.h>
#include <math.h>
int main (){
int n, x, q;
    scanf("%d",&n);
    if ((n%2)!=0){
        n--;
    }
    for ( x=2 ; n>=x ; x = (x+2)){
        q = pow(x,2);
        printf("%d^2=%d\n",x,q);
    }
    return 0; 
}