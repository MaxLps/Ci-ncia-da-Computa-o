#include <stdio.h>
int main(){
    int n, i;
    scanf("%d",&n);
    for (i=0; i<6; i++){
        if (n%2 != 0){
            printf("%d\n",n);
            n = n + 2;
        }
        else {
            n = n + 1;
            printf("%d\n",n);
            n = n + 2;
        }
    }
    return 0;
}