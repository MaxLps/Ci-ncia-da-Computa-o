#include <stdio.h>
int main (){
    int cont, testep, contp, div, maiorfp, rept;
    unsigned long long int n=600851475143;
    for (cont=1; 100000000>=cont; cont++){
        div = 1;
        if ((n%cont)==0){
            testep = cont;
            if (rept==cont){}
            else {
                if (testep%2==0 || testep%3==0){}
                else{
                    for (contp=0; testep>=div; div++){
                        if ((testep%div)==0){
                            contp++; 
                        }
                    }
                    if (contp == 2){
                        maiorfp = testep;
                        rept = maiorfp;
                    }
                }
            }
        }
    }
        printf("%d\n",maiorfp);
    return 0;
}