#include <stdio.h>
int teste_senha(int senha){
    if(senha == 2002){
        printf("Acesso Permitido\n");
        return 0;
    }
    printf("Senha Invalida\n");
    return 1;
}
int main(){
    int senha;
    do{
        scanf("%d",&senha);
    }
    while(teste_senha(senha));
    return 0;
}