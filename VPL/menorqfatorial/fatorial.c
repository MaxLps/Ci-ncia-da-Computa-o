#include <stdio.h>
int menorf(int n) {
    int i;
    int fat[10];
    fat[0] = 1;
    for (i = 1; i <= 9; i++) {
        fat[i] = i*fat[i-1];
    }  
    int x = 0;
    int a;
    for (i = 1; i<=9; i++) {
        if (fat[i]>n) {
        a = i-1;
        break;
        }
    }
    for (i = a; i >= 0; i--) {
        x += (n/fat[i]);
        n = n%fat[i];
    }
    return x;
}
int main(){
	int n, r;
	scanf("%d",&n);
	r = menorf(n);
	printf("%d\n",r);
	return 0;
}