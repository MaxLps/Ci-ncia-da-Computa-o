#include <stdio.h>
int main(){
    int s, m, h;
    printf("Difite o tempo em segundos\n");
        scanf("%d",&s);
    h = s/3600;
    m = (s%3600)/60;
    s = s - (h*3600) - (m*60);
    printf("%02d:%02d:%02d\n",h,m,s); 
    return 0;
}