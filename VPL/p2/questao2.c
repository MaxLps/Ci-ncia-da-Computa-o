#include <stdio.h>
int fat(int n) {
    if (n == 1 || n == 0){
        return 1;
    }
    else {
        return n * fat(n-1);
    }
}

int comb(int n, int p){
    int c, nf, pf;
    nf = fat(n);
    pf = fat(p);
    c = nf / (pf * fat(n-p));
    return c;
}
int main(){
    int n, p;
    scanf("%d""%d",&n, &p);
    printf("%d\n",fat(7));
}