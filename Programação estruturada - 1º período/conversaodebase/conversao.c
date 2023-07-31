#include <stdio.h>
int C;
void conversaobin(int x, int bin[]){
    int aux[32], cont=-1, i, aux1;
    for (i=0; x>=2; i++){
        aux[i] = x%2;
        x = x/2;
        cont++;
    }
    aux1 = cont + 1;
    C = aux1;
    bin[0] = x;
    for (i=1; i<=aux1; i++){
        bin[i] = aux[cont];
        cont--;       
    }
}
void conversaohex(int x, int hex[]){
    int aux[32], cont=-1, i, aux1;
    for (i=0; x>=16; i++){
        aux[i] = x%16;
        x = x/16;
        cont++;
    }
    aux1 = cont + 1;
    C = aux1;
    hex[0] = x;
    for (i=1; i<=aux1; i++){
        hex[i] = aux[cont];
        cont--;       
    }
}
int conversaodec(int x){
    int total=0;
    int p=1;
    while(x>0){
        total = total + (x % 10 * p);
        x = x / 10;
        p = p * 2;
    }
    return total;
}
int main(){
    int q, i, x, j, cont, num[32], digito, teste, inteiro;
    char tipo[3], hex[32];
    scanf("%d",&q);
    for (i=0; i<q; i++){
        scanf("%d",&x);
        hex[0] = (char) x;
        printf("%s",hex);
        scanf ("%s",tipo);
        if (tipo[0]=='d'){
            conversaohex(x, num);
            printf("caso %d:\n",i+1);
            for (j=0; j<=C; j++){
                if (num[j]>=10){
                    switch (num[j]){
                        case 10:
                        printf("A");
                        break;
                        case 11:
                        printf("B");
                        break;
                        case 12:
                        printf("C");
                        break;
                        case 13:
                        printf("D");
                        break;
                        case 14:
                        printf("E");
                        break;
                        case 15:
                        printf("F");
                        break;
                    }
                }
                else {
                printf("%d",num[j]);
                }
            }
            printf(" hex\n");            
            conversaobin(x, num);;
            for (j=0; j<=C; j++){
            printf("%d",num[j]);
            }
            printf(" bin\n");
        }
        if (tipo[0] == 'b'){
            printf("caso %d:\n",i+1);
            inteiro = conversaodec(x);
            printf("%d dec\n",inteiro);
            conversaohex(inteiro, num);
            for (j=0; j<=C; j++){
                if (num[j]>=10){
                    switch (num[j]){
                        case 10:
                        printf("A");
                        break;
                        case 11:
                        printf("B");
                        break;
                        case 12:
                        printf("C");
                        break;
                        case 13:
                        printf("D");
                        break;
                        case 14:
                        printf("E");
                        break;
                        case 15:
                        printf("F");
                        break;
                    }
                }
                else {
                printf("%d",num[j]);
                }
            }
            printf(" hex\n");           
        }
        if (i<q-1){
            printf("\n");
        }
    }
    return 0;
}