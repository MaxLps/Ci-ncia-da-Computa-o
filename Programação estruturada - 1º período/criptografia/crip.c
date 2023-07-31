#include <stdio.h>
int main(){
    char crip[1000], cripIn[1000];
    int n, i, j=0, k, inverte, metade;
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%s",crip);
        for (i=0; i<n; i++){
            if (crip[i]>=0 || crip[j]<=127){
                printf("%c :P ",crip[i]);
                j++;               
            }
        }
        printf("%d :) ",j);
        for (k=0; k<=j; k++){
            if (crip[k]>=97 && crip[k]<=122){
                crip[k] = crip[k] + 3;
                printf("%c",cripIn[k]);
            }
        }
        inverte=0;
        for (k=j; k>=0; k--){
            cripIn[inverte] = crip[k];
            inverte++;
        }
        metade = j/2;
        for (;metade<=j; metade++){
            cripIn[metade] = cripIn[metade] + 1;
        }
    }
    for (i=0; i<=j; i++){
        printf("%c",cripIn[i]);
    }
    printf("\n");
    return 0;
}