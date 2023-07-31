#include <stdio.h>
int main(){
    int N, i;
    float nota1, nota2, nota3, notaf;
    scanf("%d",&N);
    for(i=0; i<N; i++){
        scanf("%f %f %f",&nota1, &nota2, &nota3);
        notaf = (nota1*2 + nota2*3 + nota3*5)/10;
        printf("%.1f\n",notaf);
    }
    return 0;
}