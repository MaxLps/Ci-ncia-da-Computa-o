#include <stdio.h>
#include <math.h>
int fibonacci(int n){
    int fib;
    fib = (pow((1 + sqrt(5))/2,n) - pow((1 - sqrt(5))/2,n))/sqrt(5);
    return fib;
}
int main(){
    int n, i;
    scanf("%d",&n);
    for (i=0; i<n; i++){
        printf("%d ",fibonacci(i));
    }
    printf("\n");
    return 0;
}