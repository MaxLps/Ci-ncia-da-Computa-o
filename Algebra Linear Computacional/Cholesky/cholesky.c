#include <stdio.h>
#include <math.h>
void preenche_matriz(int n, double A[n][n]){
    //função que preenche matriz
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("a%d%d: ",i+1,j+1);
            scanf("%lf",&A[i][j]);
        }
        printf("\n");
    }
}
void imprimir_matriz(int n, double A[n][n]){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%5.2lf  ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
} 
int cholesky(int n, double A[n][n]){
    double G[n][n], Gt[n][n], somatorio;
    int k, i, j;
    for(j=0; j<n; j++){                               
        somatorio = 0;
        for(k=0; k<j; k++){
            somatorio = somatorio + pow(G[j][k],2);
        }
        somatorio = A[j][j] - somatorio;
        if(somatorio <= 0 ){
            return 0;
        }
        G[j][j] = sqrt(somatorio);
        for(i=j+1; i<n; i++){
            somatorio = 0;
            for(k=0; k<j; k++){
                somatorio = somatorio + G[i][k] * G[j][k];
            }
            G[i][j] = (1/ G[j][j] * (A[i][j] - somatorio));
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            Gt[i][j] = G[j][i];
        }
    }
    printf("Matriz G: \n");
    imprimir_matriz(n,G);
    printf("Matriz G^t: \n");
    imprimir_matriz(n,Gt);
    return 1;
}
int main(){

    int n;
    printf("Digite a ordem da Matriz\n");
    scanf("%d",&n);
    double A[n][n]/* = {{4,-2,2},{-2,10,-7},{2,-7,6}}*/;
    int c;
    preenche_matriz(n,A);
    printf("Matriz A: \n");
    imprimir_matriz(n,A);
    c = cholesky(n,A);
    if(c == 1){
        printf("A é simétrica definida positiva.\n");
    }
    if(c == 0){
        printf("A não é simétrica definida positiva.\n");
    }
}
