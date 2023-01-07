#include <stdio.h>
int main(){
    int i;
    char texto[300];
    for(i=0; i<4; i++){
        scanf("%s",texto);
        if (texto[0]>96 && texto[0]<113){
            texto[0] = texto[0] - 32;
        }
        printf("%s ",texto);
    }
    printf("\n");
    return 0;
}