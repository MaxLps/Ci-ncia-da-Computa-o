#include <stdio.h>
int main(){
    int anos,  dias, meses;
    scanf("%d",&dias);
    anos = dias/365;
    printf("%d ano(s)\n",anos);
    meses = (dias%365)/30;
    printf("%d mes(es)\n",meses);
    dias = (dias%365)-(meses*30);
    printf("%d dia(s)\n",dias);
    return 0;
}