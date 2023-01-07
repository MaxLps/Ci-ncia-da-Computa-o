#include <stdio.h>
int main(){
    int /*n, i,*/ j, abrep, fechap;
    char expressao[1000], lixo;
    //scanf("%d",&n);
    //for (i=0; i<n; i++){
        scanf("%s",expressao);
        abrep = 0;
        fechap = 0;
        for (j=0; expressao[j]!='\0'; j++){
            if(expressao[j]=='('){
                abrep++;
            }
            if(expressao[j]==')'){
                fechap++;
            }
        }
        if (abrep==fechap){
            if(expressao[0]==')' || expressao[j--]=='('){
                printf("incorrect\n");
            }
            else{
                printf("correct\n");
            }
        }
        else {
            printf("incorrect\n");
        }
    //}
    return 0;
}