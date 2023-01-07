#include <stdio.h>
int main (){
    float c, f;
    printf("Digite a temperatura em °C\n");
        scanf("%f",&c);
    f = 9*(c/5)+32;
    printf("%.2f°C são %.2f°F\n",c,f);
    return 0;
}