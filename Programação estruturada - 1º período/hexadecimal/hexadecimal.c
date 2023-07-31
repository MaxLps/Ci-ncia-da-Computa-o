#include <stdio.h>
int main(){
    long long int v;
    int i;
    char hex[101];
    scanf("%lld",&v);
    if (v<1 || v>2000000000){}
    else {
        if (v>9 && v<16){
            if (v==10){
                hex[100] = 65;
            }
            if (v==11){
                hex[100] = 66;
            }
            if (v==12){
                hex[100] = 67;
            }
            if (v==13){
                hex[100] = 68;
            }
            if (v==14){
                hex[100] = 69;
            }
            if (v==15){
                hex[100] = 70;
            }
            if(v==9){
                hex[100] = 57;
            }
            if(v==8){
                hex[100] = 56;
            }
            if(v==7){
                hex[100] = 55;
            }
            if(v==6){
                hex[100] = 54;
            }
            if(v==5){
                hex[100] = 53;
            }
            if(v==4){
                hex[100] = 52;
            }
            if(v==3){
                hex[100] = 51;
            }
            if(v==2){
                hex[100] = 50;
            }
            if(v==1){
                hex[100] = 49;
            }
            if(v==0){
                hex[100] = 48;
            }
            printf("%c",hex[100]);
        }
        else {
            for (i=100; v>15; i--){
                if (v%16==10){
                    hex[i] = 65;
                }
                if (v%16==11){
                    hex[i] = 66;
                }
                if (v%16==12){
                    hex[i] = 67;
                }
                if (v%16==13){
                    hex[i] = 68;
                }
                if (v%16==14){
                    hex[i] = 69;
                }
                if (v%16==15){
                    hex[i] = 70;
                }
                if(v%16==9){
                    hex[i] = 57;
                }
                if(v%16==8){
                    hex[i] = 56;
                }
                if(v%16==7){
                    hex[i] = 55;
                }
                if(v%16==6){
                    hex[i] = 54;
                }
                if(v%16==5){
                    hex[i] = 53;
                }
                if(v%16==4){
                    hex[i] = 52;
                }
                if(v%16==3){
                    hex[i] = 51;
                }
                if(v%16==2){
                    hex[i] = 50;
                }
                if(v%16==1){
                    hex[i] = 49;
                }
                if(v%16==0){
                    hex[i] = 48;
                }   
                v = v/16;
            }
            if (v==10){
                hex[i] = 65;
            }
            if (v%16==11){
                hex[i] = 66;
            }
            if (v%16==12){
                hex[i] = 67;
            }
            if (v%16==13){
                hex[i] = 68;
            }
            if (v%16==14){
                hex[i] = 69;
            }
            if (v%16==15){
                hex[i] = 70;
            }
            if(v==9){
                hex[i] = 57;
            }
            if(v==8){
                hex[i] = 56;
            }
            if(v==7){
                hex[i] = 55;
            }
            if(v==6){
                hex[i] = 54;
            }
            if(v==5){
                hex[i] = 53;
            }
            if(v==4){
                hex[i] = 52;
            }
            if(v==3){
                hex[i] = 51;
            }
            if(v==2){
                hex[i] = 50;
            }
            if(v==1){
                hex[i] = 49;
            }
            if(v==0){
                hex[i] = 48;
            }
            for (;i<=100; i++){
                printf("%c",hex[i]);
            }
        }
    }
    printf("\n");
    return 0;
}