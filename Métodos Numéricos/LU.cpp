#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#define N 15

std::vector<std::mutex> colMutexes(N);


void imprimir_matrizAmpliada(double A[N][N], double b[]){
    //função que imprime matriz ampliada
    int i, j;
    printf("Matriz Ampliada:\n");
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            printf("%6.2lf ",A[i][j]);
        }
        printf("| %6.2f\n",b[i]);
    }
    printf("\n");
}
void imprimir_matriz(double A[N][N]){
    //função que imprime matriz ampliada
    int i, j;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            printf("\t%6.2lf ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// void pivoteamento_parcial(double A[N][N], double L[N][N], double b[], int k){
//     //Função que realiza o pivoteamento parcial na matriz
//     //k é a posição do pivo na matriz
//     int i, j, indiceM = k;
//     double aux;
//     for(i=k; i<N; i++){
//         if(fabs(A[i][k]) > fabs(A[indiceM][k])){  //Bucando um elemento da mesma coluna maior que o pivô
//             indiceM = i; //Gurdnado o indice da linha do maior elemento da coluna para realizar a permutação
//         }
//     }
//     for(j=0; j<N; j++){                  
//             aux = A[k][j];
//             A[k][j] = A[indiceM][j];    //Realizando o permutação das linhas
//             A[indiceM][j] = aux;
            
//             aux = L[k][j];
//             L[k][j] = L[indiceM][j];
//             L[indiceM][j] = aux;
//         }
//     aux = b[indiceM];
//     b[indiceM] = b[k];      //trocando as posições do vetor b para ficar de acordo com nova posições das linhas
//     b[k] = aux;
// }
void pivoteamento_parcial(double A[N][N], double L[N][N], double b[]) {
    for (int k = 0; k < N; k++){
        int indiceM = k;
        for (int i = k; i < N; i++) {
            if (fabs(A[i][k]) > fabs(A[indiceM][k])) {
                indiceM = i;
            }
        }

        for (int j = 0; j < N; j++) {
            double aux = A[k][j];
            A[k][j] = A[indiceM][j];
            A[indiceM][j] = aux;

            aux = L[k][j];
            L[k][j] = L[indiceM][j];
            L[indiceM][j] = aux;
        }

        double aux = b[indiceM];
        b[indiceM] = b[k];
        b[k] = aux;

        printf("oiiiiiiiiiiiiiiiii\n");
        colMutexes[k].unlock();
    }
}
void decomposicao_LU(double A[N][N], double L[N][N], double U[N][N], double b[]){
    int k, i, j=0;
    double m; 
    for(j=0; j<N; j++){
        colMutexes[j].lock();
        printf("%d\n",j);
        for(i=j+1; i<N; i++){ 
            m = -(A[i][j] / A[j][j]);   //Encontrando o multiplicador para zerar as colunas
            L[i][j] = -m;               //Preenchendo a matriz L com multiplicador
            for(k=0; k<N; k++){
                A[i][k] = A[i][k] + (m * A[j][k]);  //Subtraindo a linha abaixo do pivo pela linha do pivo multiplicada pelo multiplicador 
                U[i][k] = A[i][k];                  //preenchendo a matriz U com o resultado da operação
            }
        }
    }                                                                       
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){                            
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
    imprimir_matriz(L);
    printf("Matriz U:\n");
    imprimir_matriz(U);
}
// void decomposicao_LU(double A[N][N], double L[N][N], double U[N][N], double b[]){
//     int k, i, j=0;
//     double m;
//     for(j=0; j<N; j++){
//         std::thread pivoteamentoThreadT(pivoteamento_parcialT, A, L, b);
//         for(i=j+1; i<N; i++){ 
//             m = -(A[i][j] / A[j][j]);   //Encontrando o multiplicador para zerar as colunas
//             L[i][j] = -m;               //Preenchendo a matriz L com multiplicador
//             for(k=0; k<N; k++){
//                 A[i][k] = A[i][k] + (m * A[j][k]);  //Subtraindo a linha abaixo do pivo pela linha do pivo multiplicada pelo multiplicador 
//                 U[i][k] = A[i][k];                  //preenchendo a matriz U com o resultado da operação
//             }
//         }
//     }                                                                       
//     for(i=0; i<N; i++){
//         for(j=0; j<N; j++){                            
//             if(i == j){                     //Terminando o preenchimento das matrizes L e U de acordo com suas propriedades
//                 L[i][j] = 1;                //Quando i=j Lij recebe 1 e U recebe Aij
//                 U[i][j] = A[i][j];          
//             }
//             if(i < j){
//                 U[i][j] = A[i][j];         //Quando i<j U recebe Aij e Lij recebe 0
//                 L[i][j] = 0;
//             }
//         }
//     }
//     printf("Matriz L:\n");
//     imprimir_matriz(L);
//     printf("Matriz U:\n");
//     imprimir_matriz(U);
// }   

void solucao_sistema(double L[N][N], double U[N][N], double b[], double x[]){
    double somatorio;
    int i, j;
    double y[N];            //primeiro resolvemos Ly = b
    y[0] = b[0];            //como a primeira linha de L é 1 0 0, podemos achar o valor de y1 diretamente com y1 = b1 
    for(i=1; i<N; i++){
        somatorio = 0;
        for(j=0; j<N; j++){
            somatorio = somatorio + L[i][j]*y[j];  //Realizando as substiruições nas linhas de baixo para encontrar
        }                                          //os valores de y
        y[i] = (b[i]-somatorio);
    }                                      //Resolvendo o sitema Ux = y
    x[N-1] = y[N-1] / U[N-1][N-1];   //Como U é triangular superior podemos achar o valor de xn diretamente com xn = yn/Unn
    for(i=N-2; i>=0; i--){                  
        somatorio=0;
        for(j=N-1; j>=0; j--){
            somatorio = somatorio + (U[i][j] * x[j]);  //Realizando as substuiçoes sucessivas para achar os
        }                                                    //os valores de todas as incógnitas (x)
        x[i] = (y[i] - somatorio)/U[i][i];
    }
    for(i=0; i<N; i++){
        printf("\t   x%d = %.10lf\n",i+1, x[i]);    
    }
    printf("\n");
}

void verificaS(double A[N][N], double b[], double x[]) {
    printf("Verificando solução:\n\n\t        B       |       Sol.\n");
    double sol[N];
    for (int i = 0; i < N; i++) {
        sol[i] = 0.0;
        for (int j = 0; j < N; j++) {
            sol[i] += A[i][j] * x[j];
        }
        printf("\t%12.15lf    |   %12.15lf\n", b[i], sol[i]);
    }
}

int main (){
    double L[N][N], U[N][N], x[N];

    //Como o pivoteamento altera a matriz e no vetor b, criamos copias para no fim comparar a solução encontrada com o vetor b

    //Matriz para teste 15x15

    double b[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    double bb[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    double A[N][N] = {
        {1.5, 2.3, -0.7, 4.2, 0.9, -3.1, 5.6, -2.8, 1.2, 0.3, -4.7, 3.8, -1.9, 2.1, 0.5},
        {0.8, -2.5, 3.6, -1.1, 5.3, -0.6, -4.2, 2.9, -1.3, 1.7, -0.9, 3.2, -2.4, 1.6, 0.2},
        {-3.7, 4.5, -1.8, 0.4, -5.1, 2.6, -1.9, 0.7, -4.3, 2.5, -1.6, 3.4, -0.5, -3.9, 1.8},
        {2.7, -1.6, 0.9, -4.5, 2.1, -0.3, 3.8, -2.2, 1.4, 0.6, -3.5, 1.9, -0.7, 2.4, -1.1},
        {0.3, -4.1, 3.9, -2.2, 1.6, 0.1, -3.4, 2.3, -1.5, 0.8, -4.6, 3.2, -2.8, 2.7, -1.9},
        {2.5, -0.8, 3.2, -2.4, 1.7, 0.4, -3.6, 2.9, -2.1, 0.5, -3.4, 2.2, -1.4, 1.1, -0.3},
        {-1.2, 3.7, -2.9, 1.3, 0.6, -3.8, 2.1, -0.9, 4.2, -2.6, 1.5, 0.2, -1.6, 3.4, -2.5},
        {2.3, -1.4, 0.7, -3.5, 2.9, -1.2, 0.9, -4.3, 3.5, -2.7, 1.9, -0.4, 3.2, -1.7, 0.8},
        {-3.9, 2.6, -1.8, 0.1, -3.3, 1.9, -0.7, 3.6, -2.5, 1.3, 0.5, -4.6, 3.4, -2.2, 1.1},
        {2.2, -1.5, 0.8, -4.1, 3.7, -2.5, 1.2, 0.6, -3.8, 2.1, -0.8, 4.5, -3.2, 2.4, -1.7},
        {-2.4, 3.2, -1.7, 1.1, -0.9, 4.1, -3.9, 2.6, -1.8, 0.1, -3.3, 1.9, -0.7, 3.6, -2.5},
        {1.1, -0.3, 2.7, -4.3, 3.9, -2.6, 1.8, -0.1, 4.4, -3.9, 2.6, -1.8, 0.1, -3.3, 1.9},
        {-4.6, 3.4, -2.2, 1.0, -2.4, 3.2, -1.7, 1.1, -0.9, 4.1, -3.9, 2.6, -1.8, 0.1, -3.3},
        {0.5, -4.6, 3.4, -2.2, 1.6, 0.8, -3.9, 2.1, -1.3, 0.4, -4.5, 3.1, -2.7, 2.3, -1.5},
        {-2.9, 1.2, 0.7, -3.3, 2.4, -1.6, 0.9, -4.4, 3.7, -2.5, 1.1, -0.5, 4.6, -3.8, 2.2}
    };
    double AA[N][N] = {
        {1.5, 2.3, -0.7, 4.2, 0.9, -3.1, 5.6, -2.8, 1.2, 0.3, -4.7, 3.8, -1.9, 2.1, 0.5},
        {0.8, -2.5, 3.6, -1.1, 5.3, -0.6, -4.2, 2.9, -1.3, 1.7, -0.9, 3.2, -2.4, 1.6, 0.2},
        {-3.7, 4.5, -1.8, 0.4, -5.1, 2.6, -1.9, 0.7, -4.3, 2.5, -1.6, 3.4, -0.5, -3.9, 1.8},
        {2.7, -1.6, 0.9, -4.5, 2.1, -0.3, 3.8, -2.2, 1.4, 0.6, -3.5, 1.9, -0.7, 2.4, -1.1},
        {0.3, -4.1, 3.9, -2.2, 1.6, 0.1, -3.4, 2.3, -1.5, 0.8, -4.6, 3.2, -2.8, 2.7, -1.9},
        {2.5, -0.8, 3.2, -2.4, 1.7, 0.4, -3.6, 2.9, -2.1, 0.5, -3.4, 2.2, -1.4, 1.1, -0.3},
        {-1.2, 3.7, -2.9, 1.3, 0.6, -3.8, 2.1, -0.9, 4.2, -2.6, 1.5, 0.2, -1.6, 3.4, -2.5},
        {2.3, -1.4, 0.7, -3.5, 2.9, -1.2, 0.9, -4.3, 3.5, -2.7, 1.9, -0.4, 3.2, -1.7, 0.8},
        {-3.9, 2.6, -1.8, 0.1, -3.3, 1.9, -0.7, 3.6, -2.5, 1.3, 0.5, -4.6, 3.4, -2.2, 1.1},
        {2.2, -1.5, 0.8, -4.1, 3.7, -2.5, 1.2, 0.6, -3.8, 2.1, -0.8, 4.5, -3.2, 2.4, -1.7},
        {-2.4, 3.2, -1.7, 1.1, -0.9, 4.1, -3.9, 2.6, -1.8, 0.1, -3.3, 1.9, -0.7, 3.6, -2.5},
        {1.1, -0.3, 2.7, -4.3, 3.9, -2.6, 1.8, -0.1, 4.4, -3.9, 2.6, -1.8, 0.1, -3.3, 1.9},
        {-4.6, 3.4, -2.2, 1.0, -2.4, 3.2, -1.7, 1.1, -0.9, 4.1, -3.9, 2.6, -1.8, 0.1, -3.3},
        {0.5, -4.6, 3.4, -2.2, 1.6, 0.8, -3.9, 2.1, -1.3, 0.4, -4.5, 3.1, -2.7, 2.3, -1.5},
        {-2.9, 1.2, 0.7, -3.3, 2.4, -1.6, 0.9, -4.4, 3.7, -2.5, 1.1, -0.5, 4.6, -3.8, 2.2}
    };

    imprimir_matrizAmpliada(A,b);
    //Bloquear todos os mutexes da lista
    for (int j = 0; j < N; j++) {
        colMutexes[j].lock();
    }
    std::thread decomposicaoThread(decomposicao_LU, A, L, U, b);
    std::thread pivoteamentoThread(pivoteamento_parcial, A, L, b);
    pivoteamentoThread.join();
    decomposicaoThread.join();

    std::thread solucaoThread(solucao_sistema, L, U, b, x);
    solucaoThread.join();

    verificaS(AA,bb,x);
    return 0;
}

//Matriz para teste 3x3

    // double b[N] = {8.0, -11.0, -3.0};
    // double bb[N] = {8.0, -11.0, -3.0};

    // double A[N][N] = {
    //     {2.0, 1.0, -1.0},
    //     {-3.0, -1.0, 2.0},
    //     {-2.0, 1.0, 2.0}
    // };
    // double AA[N][N] = {
    //     {2.0, 1.0, -1.0},
    //     {-3.0, -1.0, 2.0},
    //     {-2.0, 1.0, 2.0}
    // };

// Matriz para teste 10 x 10
    // double b[N] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    // double bb[N] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    // double A[N][N] = {
    //     {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    //     {0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    //     {0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    //     {0.0, 0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    //     {0.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    //     {0.0, 0.0, 0.0, 0.0, 0.0, 6.0, 0.0, 0.0, 0.0, 0.0},
    //     {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.0, 0.0, 0.0, 0.0},
    //     {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 8.0, 0.0, 0.0},
    //     {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 9.0, 0.0},
    //     {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0}
    // };

    // double AA[N][N] = {
    //     {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    //     {0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    //     {0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    //     {0.0, 0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    //     {0.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    //     {0.0, 0.0, 0.0, 0.0, 0.0, 6.0, 0.0, 0.0, 0.0, 0.0},
    //     {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.0, 0.0, 0.0, 0.0},
    //     {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 8.0, 0.0, 0.0},
    //     {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 9.0, 0.0},
    //     {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0}
    // };

//Matriz para teste 15x15

    // double b[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    // double bb[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    // double A[N][N] = {
    //     {1.5, 2.3, -0.7, 4.2, 0.9, -3.1, 5.6, -2.8, 1.2, 0.3, -4.7, 3.8, -1.9, 2.1, 0.5},
    //     {0.8, -2.5, 3.6, -1.1, 5.3, -0.6, -4.2, 2.9, -1.3, 1.7, -0.9, 3.2, -2.4, 1.6, 0.2},
    //     {-3.7, 4.5, -1.8, 0.4, -5.1, 2.6, -1.9, 0.7, -4.3, 2.5, -1.6, 3.4, -0.5, -3.9, 1.8},
    //     {2.7, -1.6, 0.9, -4.5, 2.1, -0.3, 3.8, -2.2, 1.4, 0.6, -3.5, 1.9, -0.7, 2.4, -1.1},
    //     {0.3, -4.1, 3.9, -2.2, 1.6, 0.1, -3.4, 2.3, -1.5, 0.8, -4.6, 3.2, -2.8, 2.7, -1.9},
    //     {2.5, -0.8, 3.2, -2.4, 1.7, 0.4, -3.6, 2.9, -2.1, 0.5, -3.4, 2.2, -1.4, 1.1, -0.3},
    //     {-1.2, 3.7, -2.9, 1.3, 0.6, -3.8, 2.1, -0.9, 4.2, -2.6, 1.5, 0.2, -1.6, 3.4, -2.5},
    //     {2.3, -1.4, 0.7, -3.5, 2.9, -1.2, 0.9, -4.3, 3.5, -2.7, 1.9, -0.4, 3.2, -1.7, 0.8},
    //     {-3.9, 2.6, -1.8, 0.1, -3.3, 1.9, -0.7, 3.6, -2.5, 1.3, 0.5, -4.6, 3.4, -2.2, 1.1},
    //     {2.2, -1.5, 0.8, -4.1, 3.7, -2.5, 1.2, 0.6, -3.8, 2.1, -0.8, 4.5, -3.2, 2.4, -1.7},
    //     {-2.4, 3.2, -1.7, 1.1, -0.9, 4.1, -3.9, 2.6, -1.8, 0.1, -3.3, 1.9, -0.7, 3.6, -2.5},
    //     {1.1, -0.3, 2.7, -4.3, 3.9, -2.6, 1.8, -0.1, 4.4, -3.9, 2.6, -1.8, 0.1, -3.3, 1.9},
    //     {-4.6, 3.4, -2.2, 1.0, -2.4, 3.2, -1.7, 1.1, -0.9, 4.1, -3.9, 2.6, -1.8, 0.1, -3.3},
    //     {0.5, -4.6, 3.4, -2.2, 1.6, 0.8, -3.9, 2.1, -1.3, 0.4, -4.5, 3.1, -2.7, 2.3, -1.5},
    //     {-2.9, 1.2, 0.7, -3.3, 2.4, -1.6, 0.9, -4.4, 3.7, -2.5, 1.1, -0.5, 4.6, -3.8, 2.2}
    // };
    // double AA[N][N] = {
    //     {1.5, 2.3, -0.7, 4.2, 0.9, -3.1, 5.6, -2.8, 1.2, 0.3, -4.7, 3.8, -1.9, 2.1, 0.5},
    //     {0.8, -2.5, 3.6, -1.1, 5.3, -0.6, -4.2, 2.9, -1.3, 1.7, -0.9, 3.2, -2.4, 1.6, 0.2},
    //     {-3.7, 4.5, -1.8, 0.4, -5.1, 2.6, -1.9, 0.7, -4.3, 2.5, -1.6, 3.4, -0.5, -3.9, 1.8},
    //     {2.7, -1.6, 0.9, -4.5, 2.1, -0.3, 3.8, -2.2, 1.4, 0.6, -3.5, 1.9, -0.7, 2.4, -1.1},
    //     {0.3, -4.1, 3.9, -2.2, 1.6, 0.1, -3.4, 2.3, -1.5, 0.8, -4.6, 3.2, -2.8, 2.7, -1.9},
    //     {2.5, -0.8, 3.2, -2.4, 1.7, 0.4, -3.6, 2.9, -2.1, 0.5, -3.4, 2.2, -1.4, 1.1, -0.3},
    //     {-1.2, 3.7, -2.9, 1.3, 0.6, -3.8, 2.1, -0.9, 4.2, -2.6, 1.5, 0.2, -1.6, 3.4, -2.5},
    //     {2.3, -1.4, 0.7, -3.5, 2.9, -1.2, 0.9, -4.3, 3.5, -2.7, 1.9, -0.4, 3.2, -1.7, 0.8},
    //     {-3.9, 2.6, -1.8, 0.1, -3.3, 1.9, -0.7, 3.6, -2.5, 1.3, 0.5, -4.6, 3.4, -2.2, 1.1},
    //     {2.2, -1.5, 0.8, -4.1, 3.7, -2.5, 1.2, 0.6, -3.8, 2.1, -0.8, 4.5, -3.2, 2.4, -1.7},
    //     {-2.4, 3.2, -1.7, 1.1, -0.9, 4.1, -3.9, 2.6, -1.8, 0.1, -3.3, 1.9, -0.7, 3.6, -2.5},
    //     {1.1, -0.3, 2.7, -4.3, 3.9, -2.6, 1.8, -0.1, 4.4, -3.9, 2.6, -1.8, 0.1, -3.3, 1.9},
    //     {-4.6, 3.4, -2.2, 1.0, -2.4, 3.2, -1.7, 1.1, -0.9, 4.1, -3.9, 2.6, -1.8, 0.1, -3.3},
    //     {0.5, -4.6, 3.4, -2.2, 1.6, 0.8, -3.9, 2.1, -1.3, 0.4, -4.5, 3.1, -2.7, 2.3, -1.5},
    //     {-2.9, 1.2, 0.7, -3.3, 2.4, -1.6, 0.9, -4.4, 3.7, -2.5, 1.1, -0.5, 4.6, -3.8, 2.2}
    // };