#include <stdio.h>
#include <string.h>
int main(){
    int n, i, t, j, k, l, m, o, igualdade=0, s;
    char palavra1[10], palavra2[10], palavra3[10], palavra4[10];
    scanf("%d",&n);
    if (n>0 && n<=10){
        for (s=0; s<n; s++){
            scanf("%d",&t);
            palavra1[t]=9;
            scanf("%s",palavra1);
            if (palavra1[t]==9){
            igualdade = 0;
            for (i=0; i<=t; i++){
                switch (palavra1[i]){
                    case 65:
                    palavra1[i] = palavra1[i] - 13;
                    break;
                    case 97:
                    palavra1[i] = palavra1[i] - 45;
                    break;
                    case 69:
                    palavra1[i] = palavra1[i] - 18;
                    break;
                    case 101:
                    palavra1[i] = palavra1[i] - 50;
                    break;
                    case 73:
                    palavra1[i] = palavra1[i] - 24;
                    break;
                    case 105:
                    palavra1[i] = palavra1[i] - 56;
                    break;
                    case 79:
                    palavra1[i] = palavra1[i] - 31;
                    break;
                    case 111:
                    palavra1[i] = palavra1[i] - 53;
                    break;
                    case 90:
                    palavra1[i] = palavra1[i] - 40;
                    break;
                    case 122:
                    palavra1[i] = palavra1[i] - 72;
                    break;
                }
            }
            }
            palavra2[t]=9;
            scanf("%s",palavra2);
            if (palavra2[t]==9){
            for (i=0; i<=t; i++){
                switch (palavra2[i]){
                    case 65:
                    palavra2[i] = palavra2[i] - 13;
                    break;
                    case 97:
                    palavra2[i] = palavra2[i] - 45;
                    break;
                    case 69:
                    palavra2[i] = palavra2[i] - 18;
                    break;
                    case 101:
                    palavra2[i] = palavra2[i] - 50;
                    break;
                    case 73:
                    palavra2[i] = palavra2[i] - 24;
                    break;
                    case 105:
                    palavra2[i] = palavra2[i] - 56;
                    break;
                    case 79:
                    palavra2[i] = palavra2[i] - 31;
                    break;
                    case 111:
                    palavra2[i] = palavra2[i] - 53;
                    break;
                    case 90:
                    palavra2[i] = palavra2[i] - 40;
                    break;
                    case 122:
                    palavra2[i] = palavra2[i] - 72;
                    break;
                }
            }
            }
            palavra3[t] = 9;
            scanf("%s",palavra3);
            if (palavra1[t]==9){
            for (i=0; i<=t; i++){
                switch (palavra3[i]){
                    case 65:
                    palavra3[i] = palavra3[i] - 13;
                    break;
                    case 97:
                    palavra3[i] = palavra3[i] - 45;
                    break;
                    case 69:
                    palavra3[i] = palavra3[i] - 18;
                    break;
                    case 101:
                    palavra3[i] = palavra3[i] - 50;
                    break;
                    case 73:
                    palavra3[i] = palavra3[i] - 24;
                    break;
                    case 105:
                    palavra3[i] = palavra3[i] - 56;
                    break;
                    case 79:
                    palavra3[i] = palavra3[i] - 31;
                    break;
                    case 111:
                    palavra3[i] = palavra3[i] - 53;
                    break;
                    case 90:
                    palavra3[i] = palavra3[i] - 40;
                    break;
                    case 122:
                    palavra3[i] = palavra3[i] - 72;
                    break;
                }
            }
            }
            palavra4[t] = 9;
            scanf("%s",palavra4);
            if (palavra1[t]==9){
            for (i=0; i<=t; i++){
                switch (palavra4[i]){
                    case 65:
                    palavra4[i] = palavra4[i] - 13;
                    break;
                    case 97:
                    palavra4[i] = palavra4[i] - 45;
                    break;
                    case 69:
                    palavra4[i] = palavra4[i] - 18;
                    break;
                    case 101:
                    palavra4[i] = palavra4[i] - 50;
                    break;
                    case 73:
                    palavra4[i] = palavra4[i] - 24;
                    break;
                    case 105:
                    palavra4[i] = palavra4[i] - 56;
                    break;
                    case 79:
                    palavra4[i] = palavra4[i] - 31;
                    break;
                    case 111:
                    palavra4[i] = palavra4[i] - 53;
                    break;
                    case 90:
                    palavra4[i] = palavra4[i] - 40;
                    break;
                    case 122:
                    palavra4[i] = palavra4[i] - 72;
                    break;
                }
            }
            }
            for(i=0; i<t; i++){
                if(palavra1[i] == palavra2[i]){
                    igualdade++;
                }
                if(palavra2[i] == palavra3[i]){
                    igualdade++;
                }
                if(palavra3[i] == palavra4[i]){
                    igualdade++;
                }
            }
            if (igualdade == 3*t){
                printf("S\n");
            }
            else {
                printf("N\n");
            }
        }
    }
    return 0;
}