#include <stdio.h>
int main(){
    char palavra[100];
    scanf("%s",palavra);
    if (palavra[0]>96 && palavra[0]<113){
        palavra[0] = palavra[0] - 32;
    }
    printf("%s\n",palavra);
    return 0;
}
