#include <stdio.h>
int main(){
    int i, j, k, l, ii, conts=0, ocorrencia=0;
    char sg[100], sub[100];
    fgets(sg, 100, stdin);
    fgets(sub, 100, stdin);
    for (i=0; sub[i]!='\0'; i++){
        conts++;
    }
    conts--;
    char aux[conts];
    for (i=0; sg[i]!='\0'; i++){
        k=0;
        ii=i;
        for (j=i; j<conts; j++){
            aux[k] = sg[ii];
            k++;
            ii++;
            printf("%c",aux[k-1]);
        }
        printf("\n---------\n");
        for (l=0; l<conts; l++){
            if (aux[l] == sub[l]){
                ocorrencia++;
            }
        }
    }
    printf("%d\n",ocorrencia);
    return 0;
}