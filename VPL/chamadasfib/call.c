#include<stdio.h>
int call = -1;
int fib(int n){
	call++;
    if(n == 0 || n == 1)
        return n;
    return fib(n-1) + fib(n-2);
}
int main(){
	int q, n, i, valorfib;
    scanf("%d", &q);
    for (i=0; i<q; i++){
        call = -1;
        scanf("%d",&n);
        valorfib = fib(n);
        printf("fib(%d) = %d calls = %d\n",n,call,valorfib);
    }
	return 0;
}