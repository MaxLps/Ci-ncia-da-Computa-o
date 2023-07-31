#include <stdio.h>
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
double determinante(int n, double L[n][n]){
    int i;
    double det;
    for(i=1, det=L[0][0]; i<n; i++){
        det *= L[i][i];
    }
    return det;
}
int main (){
    int n;
    printf("Digite a ordem da Matriz\n");
    scanf("%d",&n);
    double A[n][n], L[n][n], U[n][n], b[n];
    printf("\nPreencha a matriz\n");
    preenche_matriz(n,A);
    imprimir_matriz(n,A);
    decomposicao_LU(n,A,L,U,b);
    printf("Determinante = %.2lf\n",determinante(n,U));
    return 0;
}