#include <stdio.h>
int main(){  
    int n, i, p, u, d, c, m, dm, cm, palindromo=0, testep[6];
    for (i=999; i>99; i--){
        for (n=999;n>99;n--){
            p = n*i;
            u = p%10;
            d = ((p%100)-u)/10;
            c = ((p%1000)-u)/100;
            m = ((p%10000)-u)/1000;
            dm = ((p%100000)-u)/10000;
            cm = ((p%1000000)-u)/100000;
            if (u>=0){
            testep[5] = u;
            }
            if (d>=0){
            testep[4] = d;
            }
            if (c>=0){
            testep[3] = c;
            }
            if (m>=0){
            testep[2] = m;
            }
            if (dm>=0){
            testep[1] = dm;
            }
            if (cm>=0){
            testep[0] = cm;
            }
            if (testep[0]==testep[5] && testep[1]==testep[4] && testep[2]==testep[3]){
                if (p>palindromo){
                    palindromo = p;
                }
            }
        }
    }
    u = palindromo%10;
    d = ((palindromo%100)-u)/10;
    c = ((palindromo%1000)-u)/100;
    m = ((palindromo%10000)-u)/1000;
    dm = ((palindromo%100000)-u)/10000;
    cm = ((palindromo%1000000)-u)/100000;
    if (u>=0){
    testep[5] = u;
    }
    if (d>=0){
    testep[4] = d;
    }
    if (c>=0){
    testep[3] = c;
    }
    if (m>=0){
    testep[2] = m;
    }
    if (dm>=0){
    testep[1] = dm;
    }
    if (cm>=0){
    testep[0] = cm;
    }
    printf("%d%d%d%d%d%d\n",testep[0],testep[1],testep[2],testep[3],testep[4],testep[5]);
    return 0;
}
