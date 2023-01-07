#include <stdio.h>
#include <math.h>
void preenche_matrizAmpliada(int n, double A[n][n], double b[]){
    //função que preenche matriz
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("a%d%d: ",i+1,j+1);
            scanf("%lf",&A[i][j]);
        }
        printf("b%d: ",i+1);
        scanf("%lf",&b[i]);
        printf("\n");
    }
}
void imprimir_matrizAmpliada(int n, double A[n][n], double b[]){
    //função que imprime matriz ampliada
    int i, j;
    printf("Matriz Ampliada:\n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf("%6.2lf ",A[i][j]);
        }
        printf("| %5.2lf\n",b[i]);
    }
    printf("\n");
}
void imprimir_matriz(int n, double A[n][n]){
    //função que imprime matriz ampliada
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf("%6.2lf ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void pivoteamento_parcial(int n, double A[n][n], double L[n][n], double b[], int k){
    //Função que realiza o pivoteamento parcial na matriz
    //k é a posição do pivo na matriz
    int i, j, indiceM = k;
    double aux;
    for(i=k; i<n; i++){
        if(fabs(A[i][k]) > fabs(A[indiceM][k])){  //Bucando um elemento da mesma coluna maior que o pivô
            indiceM = i; //Gurdnado o indice da linha do maior elemento da coluna para realizar a permutação
        }
    }
    for(j=0; j<n; j++){                  
            aux = A[k][j];
            A[k][j] = A[indiceM][j];    //Realizando o permutação das linhas
            A[indiceM][j] = aux;
            
            aux = L[k][j];
            L[k][j] = L[indiceM][j];
            L[indiceM][j] = aux;
        }
        aux = b[indiceM];
        b[indiceM] = b[k];      //trocando as posições do vetor b para ficar de acordo com nova posições das linhas
        b[k] = aux;
}
void decomposicao_LU(int n, double A[n][n], double L[n][n], double U[n][n], double b[]){
    int k, i, j=0;
    double m;
    for(j=0; j<n; j++){
        pivoteamento_parcial(n,A,L,b,j);
        for(i=j+1; i<n; i++){ 
            m = -(A[i][j] / A[j][j]);   //Encontrando o multiplicador para zerar as colunas
            L[i][j] = -m;               //Preenchendo a matriz L com multiplicador
            for(k=0; k<n; k++){
                A[i][k] = A[i][k] + (m * A[j][k]);  //Subtraindo a linha abaixo do pivo pela linha do pivo multiplicada pelo multiplicador 
                U[i][k] = A[i][k];                  //preenchendo a matriz U com o resultado da operação
            }
        }
    }                                                                       
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){                            
            if(i == j){                     //Terminando o preenchimento das matrizes L e U de acordo com suas propriedades
                L[i][j] = 1;                //Quando i=j Lij recebe 1 e U recebe Aij
                U[i][j] = A[i][j];          
            }
            if(i < j){
                U[i][j] = A[i][j];         //Quando i<j U recebe Aij e Lij recebe 0
                L[i][j] = 0;
            }
        }
    }
    printf("Matriz L:\n");
    imprimir_matriz(n,L);
    printf("Matriz U:\n");
    imprimir_matriz(n,U);
}    
void solucao_sistema(int n, double L[n][n], double U[n][n], double b[], double x[]){
    double somatorio;
    int i, j;
    double y[n];            //primeiro resolvemos Ly = b
    y[0] = b[0];            //como a primeira linha de L é 1 0 0, podemos achar o valor de y1 diretamente com y1 = b1 
    for(i=1; i<n; i++){
        somatorio = 0;
        for(j=0; j<n; j++){
            somatorio = somatorio + L[i][j]*y[j];  //Realizando as substiruições nas linhas de baixo para encontrar
        }                                          //os valores de y
        y[i] = (b[i]-somatorio);
    }                                      //Resolvendo o sitema Ux = y
    x[n-1] = y[n-1] / U[n-1][n-1];   //Como U é triangular superior podemos achar o valor de xn diretamente com xn = yn/Unn
    for(i=n-2; i>=0; i--){                  
        somatorio=0;
        for(j=n-1; j>=0; j--){
            somatorio = somatorio + (U[i][j] * x[j]);  //Realizando as substuiçoes sucessivas para achar os
        }                                                    //os valores de todas as incógnitas (x)
        x[i] = (y[i] - somatorio)/U[i][i];
    }
    for(i=0; i<n; i++){
        printf("x%d = %.4lf\n",i+1, x[i]);    
    }
    printf("\n");
}
int main (){
    int n;
    printf("Digite a ordem da Matriz\n");
    scanf("%d",&n);
    double A[n][n], L[n][n], U[n][n], b[n], x[n];
    printf("\nPreencha a matriz ampliada\n");
    preenche_matrizAmpliada(n,A,b);
    imprimir_matrizAmpliada(n,A,b);
    decomposicao_LU(n,A,L,U,b);
    solucao_sistema(n,L,U,b,x);
    return 0;
}