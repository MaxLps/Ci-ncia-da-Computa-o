#include <stdio.h>
void hanoi(int n, int a, int c, int b){
    if (n==1){
        printf("%d %d\n",a,c);
    }
    else {
        hanoi(n-1, a, b, c);
        printf("%d %d\n", a, c);
        hanoi(n-1, b, c, a);
    }
}
int main(){
    int n, a=1, b=2, c=3;
    scanf("%d",&n);
    hanoi(n, a, c, b);
    return 0;
}