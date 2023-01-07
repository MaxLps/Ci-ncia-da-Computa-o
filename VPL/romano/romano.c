#include <stdio.h>
int main(){
    int n, u, d, c, i, romano[4];
    scanf("%d",&n);
    if (n<0 || n>1000){}
    else {
        u = n%10;
        d = ((n%100)-u)/10;
        c = (n-(d*10)-u)/100;
        romano[0] = c;
        romano[1] = d;
        romano[2] = u;
        switch (romano[0]){
            case 0:
            break;
            case 1:
            printf("C");
            break;
            case 2:
            printf("CC");
            break;
            case 3:
            printf("CCC");
            break;
            case 4:
            printf("XD");
            break;
            case 5:
            printf("D");
            break;
            case 6:
            printf("DC");
            break;
            case 7:
            printf("DCC");
            break;
            case 8:
            printf("DCCC");
            break;
            case 9:
            printf("CM");
            break;
        }
        switch (romano[1]){
            case 0:
            break;
            case 1:
            printf("X");
            break;
            case 2:
            printf("XX");
            break;
            case 3:
            printf("XXX");
            break;
            case 4:
            printf("XL");
            break;
            case 5:
            printf("L");
            break;
            case 6:
            printf("LX");
            break;
            case 7:
            printf("LXX");
            break;
            case 8:
            printf("LXXX");
            break;
            case 9:
            printf("XC");
            break;
        }
        switch (romano[2]){
            case 0:
            break;
            case 1:
            printf("I");
            break;
            case 2:
            printf("II");
            break;
            case 3:
            printf("III");
            break;
            case 4:
            printf("IV");
            break;
            case 5:
            printf("V");
            break;
            case 6:
            printf("VI");
            break;
            case 7:
            printf("VII");
            break;
            case 8:
            printf("VIII");
            break;
            case 9:
            printf("IX");
            break;
        }
    }
    return 0;
}