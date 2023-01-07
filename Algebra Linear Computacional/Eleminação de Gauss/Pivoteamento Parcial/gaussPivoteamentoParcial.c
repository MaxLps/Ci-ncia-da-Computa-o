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
void pivoteamento_parcial(int n, double A[n][n], double b[], int k){
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
        }
        aux = b[indiceM];
        b[indiceM] = b[k];      //trocando as posições do vetor b para ficar de acordo com nova posições das linhas
        b[k] = aux;
}
void eliminacaoGauss(int n,double A[n][n], double b[]){
    int k, i, j=0;
    double m;
    for(j=0; j<n; j++){
        pivoteamento_parcial(n,A,b,j); 
        for(i=j+1; i<n; i++){ 
            m = -(A[i][j] / A[j][j]);        //Encontrando o multiplicador para zerar as colunas
            for(k=0; k<n; k++){
                A[i][k] = A[i][k] + (m * A[j][k]);  //Subtraindo a linha abaixo do pivo pela linha do pivo multiplicada pelo multiplicador
            }
            b[i] = b[i] + (m * b[j]);          //Subtraindo a linha abaixo do pivo em b pela linha do pivo multiplicada pelo multiplicador
        }
    }
}
void solucao_sistema(int n, double A[n][n], double b[], double x[]){
    double somatorio;
    int i, j;
    x[n-1] = b[n-1]/A[n-1][n-1];  //Como A virou uma matriz triangular superior podemos
    for(i=n-2; i>=0; i--){                             //achar o valor de xn diretamente com xn = bn/Ann
        somatorio=0;
        for(j=n-1; j>=i; j--){
            somatorio = somatorio + (A[i][j] * x[j]); //Realizando as substuiçoes sucessivas para encontrar
        }                                                   //os valores de todas as incógnitas x
        x[i] = (b[i] - somatorio)/A[i][i];
    }
    printf("Solução com Pivoteamento Parcial: \n");
    imprimir_matrizAmpliada(n,A,b);
    for(i=0; i<n; i++){
        printf("x%d = %.4lf\n",i+1, x[i]);    
    }
}
int main (){
    int n;
    printf("Digite a ordem da Matriz\n");
    scanf("%d",&n);
    double A[n][n], b[n], x[n];
    printf("\nPreencha a matriz ampliada\n");
    preenche_matrizAmpliada(n,A,b);
    imprimir_matrizAmpliada(n,A,b);
    eliminacaoGauss(n,A,b);
    solucao_sistema(n,A,b,x);
    return 0;
}