#include <stdio.h>
int numeroSorte(int s){
    int u, d, c, m, soma;
    u = s%10;
    d = ((s%100)-u)/10;
    c = (s-(d*10)-u)/100;
    m = (s-(c*100)-(d*10)-u)/1000;
    soma = m + c + d + u;
    if (soma > 9){
        return numeroSorte(soma);
    }
    return soma;
}
int main(){
    int i, soma=0, sorte;
    char nome[200];
    fgets(nome, 200, stdin);
    for (i=0; nome[i]!='\0'; i++){
        switch (nome[i]){
            case 'a':
            soma = soma + 1;
            break;
            case 'b':
            soma = soma + 2;
            break;
            case 'c':
            soma = soma + 3;
            break;
            case 'd':
            soma = soma + 4;
            break;
            case 'e':
            soma = soma + 5;
            break;
            case 'f':
            soma = soma + 6;
            break;
            case 'g':
            soma = soma + 7;
            break;
            case 'h':
            soma = soma + 8;
            break;
            case 'i':
            soma = soma + 9;
            break;
            case 'j':
            soma = soma + 10;
            break;
            case 'k':
            soma = soma + 11;
            break;
            case 'l':
            soma = soma + 12;
            break;
            case 'm':
            soma = soma + 13;
            break;
            case 'n':
            soma = soma + 14;
            break;
            case 'o':
            soma = soma + 15;
            break;
            case 'p':
            soma = soma + 16;
            break;
            case 'q':
            soma = soma + 17;
            break;
            case 'r':
            soma = soma + 18;
            break;
            case 's':
            soma = soma + 19;
            break;
            case 't':
            soma = soma + 20;
            break;
            case 'u':
            soma = soma + 21;
            break;
            case 'v':
            soma = soma + 22;
            break;
            case 'w':
            soma = soma + 23;
            break;
            case 'x':
            soma = soma + 24;
            break;
            case 'y':
            soma = soma + 25;
            break;
            case 'z':
            soma = soma + 26;
            break;
        }
    }
    sorte = numeroSorte(soma);
    printf("%d\n",sorte);
    return 0;
}

