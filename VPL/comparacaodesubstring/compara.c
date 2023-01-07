#include <stdio.h>
int comparacao(char x[], char y[]){
    int v=0, v1=0, i, j, k, cont=0;
    char teste[50];
    for(i=0; x[i]!='\0'; i++){
        for (j=0; y[j]!='\0'; j++){
            if (x[i] == y[j]){
                teste[cont]=x[i];
                cont++;
                printf("%c",teste[cont--]);
            }
        }
    }
    return v;
}
int main(){
    char string1[50], string2[50];
    fgets(string1, 50, stdin);
    fgets(string2, 50, stdin);
    comparacao(string1, string2);
    //printf("%d\n",comparacao(string1,string2));
    return 0;
}