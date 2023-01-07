#include <stdio.h>
#include <math.h>
int main(){
float A, B, C, D;
    scanf("%f %f %f",&A,&B,&C);
    if (A<B) {
        D = A;
        A = B;
        B = D;
    }
    if (B<C) {
        D = B;
        B = C;
        C = D;
    }
    if (B>A) {
        D = B;
        B = A;
        A = D;
    }
    if (A >= B+C){
	    printf("NAO FORMA TRIANGULO\n");
    }
    else {
        if (pow(A,2) == (pow(B,2) + pow(C,2))){
	    printf("TRIANGULO RETANGULO\n");
        } 
        if (pow(A,2) > (pow(B,2) + pow(C,2))){
	        printf("TRIANGULO OBTUSANGULO\n"); 
        }                
        if (pow(A,2) < (pow(B,2) + pow(C,2))){
	        printf("TRIANGULO ACUTANGULO\n");
        }
        if ((A==B) && (B==C)){
	        printf("TRIANGULO EQUILATERO\n");
        }
        else {
            if ((A == B) ^ (A == C) ^ (B == C)){
	            printf("TRIANGULO ISOSCELES\n");
            }
        }
    }
    return 0;
}