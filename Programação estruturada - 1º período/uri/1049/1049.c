#include <stdio.h>
int main(){
    char tipo1[20], tipo2[20], tipo3[20];
    scanf("%s",tipo1);
    scanf("%s",tipo2);
    scanf("%s",tipo3);
    if (tipo1[0] == 'v'){
        if (tipo2[0] == 'a'){
            if (tipo3[0] == 'c'){
                printf("aguia\n");
            }
            if (tipo3[0] == 'o'){
                printf("pomba\n");
            }
        }
        if (tipo2[0] == 'm'){
            if (tipo3[0] == 'o'){
                printf("homem\n");
            }
            if (tipo3[0] == 'h'){
                printf("vaca\n");
            }
        }
        
    }
    if (tipo1[0] == 'i'){
        if (tipo2[0] == 'i'){
            if (tipo3[2] == 'm'){
                printf("pulga\n");
            }
            if (tipo3[2] == 'r'){
                printf("lagarta\n");
            }
        }
        if (tipo2[0] == 'a'){
            if (tipo3[0] == 'h'){
                printf("sanguessuga\n");
            }
            if (tipo3[0] == 'o'){
                printf("minhoca\n");
            }
        }
        
    }
    return 0;
}