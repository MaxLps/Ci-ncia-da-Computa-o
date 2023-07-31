#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

#define N 1000
#define IMPRIMIR false

std::vector<std::mutex> colMutexes(N);

void imprimir_matrizAmpliada(double **A, double b[]);
void imprimir_matriz(double **A);
void geraMAtriz(double** a, double** as, double b[], double bs[]);
void pivoteamento_parcial(double** A, double** L, double b[], int k);
void pivoteamento_parcialThread(double** A, double** L, double b[]);
void decomposicao_LU(double** A, double** L, double** U, double b[]); 
void decomposicao_LUthread(double** A, double** L, double** U, double b[]);
void solucao_sistema(double** L, double** U, double b[], double x[]);
void verificaS(double** A, double b[], double x[]);

int main (){
    double b[N], bs[N], x[N];
    double** A = new double*[N];
    double** As = new double*[N];
    double** L = new double*[N];
    double** U = new double*[N];

    for (int i=0; i<N; i++) {
        A[i] = new double[N];
        As[i] = new double[N];
        L[i] = new double[N];
        U[i] = new double[N];
        x[i] = 0.0;
    }

    geraMAtriz(A,As,b,bs);

    auto inicio = std::chrono::high_resolution_clock::now();

    decomposicao_LUthread(A, L, U, b);
    solucao_sistema(L, U, b, x);
    

    auto fim = std::chrono::high_resolution_clock::now();
    auto duracaoCT = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio).count();
    
    //verificaS(As,bs,x);

    std::cout << "Tempo de execucao com thread: " << duracaoCT << " microssegundos" << std::endl;


 for (int i = 0; i < N; i++) {
        delete[] A[i];
        delete[] As[i];
        delete[] L[i];
        delete[] U[i];
    }
    delete[] A;
    delete[] As;
    delete[] L;
    delete[] U;

    return 0;
}


void imprimir_matrizAmpliada(double **A, double b[]){
    //função que imprime matriz ampliada
    int i, j;
    printf("Matriz Ampliada:\n\t");
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            printf("%16.8lf ",A[i][j]);
        }
        printf("| %6.4f\n\t",b[i]);
    }
    printf("\n");
}
void imprimir_matriz(double **A){
    //função que imprime matriz ampliada
    int i, j;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            printf("\t%9.8lf ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void geraMAtriz(double** a, double** as, double b[], double bs[]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = std::sin((i + 1) * (j + 1));
            as[i][j] = a[i][j];
        }
        b[i] = 0.01; 
        bs[i] = b[i];
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         std::cout << "Informe o valor para a posição [" << i << "][" << j << "] da matriz: ";
    //         std::cin >> a[i][j];
    //         at[i][j] = a[i][j];
    //         as[i][j] = a[i][j];
    //     }
    //     std::cout << "Informe o valor para a posição [" << i << "] do vetor: ";
    //     std::cin >> b[i];
    //     bt[i] = b[i];
    //     bs[i] = b[i];
    // }

    if(IMPRIMIR){
        imprimir_matrizAmpliada(a,b);
    }
}

void pivoteamento_parcial(double** A, double** L, double b[], int k){
    //Função que realiza o pivoteamento parcial na matriz
    //k é a posição do pivo na matriz
    int i, j, indiceM = k;
    double aux;
    for(i=k; i<N; i++){
        if(fabs(A[i][k]) > fabs(A[indiceM][k])){  //Bucando um elemento da mesma coluna maior que o pivô
            indiceM = i; //Gurdnado o indice da linha do maior elemento da coluna para realizar a permutação
        }
    }
    for(j=0; j<N; j++){                  
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

void pivoteamento_parcialThread(double** A, double** L, double b[], int k){
    int i, j, indiceM = k;
    double aux;

    #pragma omp parallel for shared(A, L, b, indiceM) private(i)
    for(i = k; i < N; i++){
        if(fabs(A[i][k]) > fabs(A[indiceM][k])){
            #pragma omp critical
            {
                if (fabs(A[i][k]) > fabs(A[indiceM][k])) {
                    indiceM = i;
                }
            }
        }
    }

    #pragma omp parallel for shared(A, L) private(j, aux)
    for(j = 0; j < N; j++){                  
        aux = A[k][j];
        A[k][j] = A[indiceM][j];
        A[indiceM][j] = aux;
        
        aux = L[k][j];
        L[k][j] = L[indiceM][j];
        L[indiceM][j] = aux;
    }

    #pragma omp critical
    {
        aux = b[indiceM];
        b[indiceM] = b[k];
        b[k] = aux;
    }
}

void decomposicao_LU(double** A, double** L, double** U, double b[]){
    int k, i, j=0;
    double m;
    for(j=0; j<N; j++){
        pivoteamento_parcial(A,L,b,j);
        for(i=j+1; i<N; i++){ 
            if(A[j][j] == 0.0){
                std::cout << "A matriz tem determinante nulo.\n";
                exit(0);
            }
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
            if(i > j){
                U[i][j] = 0;
            }
        }
    }
    if(IMPRIMIR){
        printf("Matriz L:\n");
        imprimir_matriz(L);
        printf("Matriz U:\n");
        imprimir_matriz(U);
    }
    
}  

void decomposicao_LUthread(double** A, double** L, double** U, double b[]){
    int k, i, j=0;
    double m; 
    for(j=0; j<N; j++){
        // colMutexes[j].lock();
        pivoteamento_parcial(A,L,b,j);
        for(i=j+1; i<N; i++){ 
            m = -(A[i][j] / A[j][j]);   //Encontrando o multiplicador para zerar as colunas
            L[i][j] = -m;               //Preenchendo a matriz L com multiplicador
            for(k=0; k<N; k++){
                A[i][k] = A[i][k] + (m * A[j][k]);  //Subtraindo a linha abaixo do pivo pela linha do pivo multiplicada pelo multiplicador 
                U[i][k] = A[i][k];                  //preenchendo a matriz U com o resultado da operação
            }
        }
    }                                                                       
    #pragma omp parallel num_threads(4)
{
    #pragma omp for private(j)
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(i == j) {
                L[i][j] = 1;
                U[i][j] = A[i][j];
            } else if(i < j) {
                U[i][j] = A[i][j];
                L[i][j] = 0;
            }
        }
    }
}
    if(IMPRIMIR){
        printf("Matriz L:\n");
        imprimir_matriz(L);
        printf("Matriz U:\n");
        imprimir_matriz(U);
    }
}

void solucao_sistema(double** L, double** U, double b[], double x[]){
    double somatorio;
    int i, j;
    double y[N];            //primeiro resolvemos Ly = b
    y[0] = b[0];            //como a primeira linha de L é 1 0 0, podemos achar o valor de y1 diretamente com y1 = b1 
    for(i=1; i<N; i++){
        somatorio = 0.0;
        for(j=0; j<i; j++){
            somatorio += L[i][j]*y[j];  //Realizando as substiruições nas linhas de baixo para encontrar
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
   if(IMPRIMIR){
        for(i=0; i<N; i++){
            printf("\t   x%d = %12.15lf\n",i+1, x[i]);    
        }
        printf("\n");
    }
}

void verificaS(double** A, double b[], double x[]) {
    printf("Verificando solução:\n\n\t        B       |       Sol.\n");
    double sol[N];
    double somab, somaSol;
    somab = somaSol = 0;
    for (int i = 0; i < N; i++) {
        sol[i] = 0.0;
        for (int j = 0; j < N; j++) {
            sol[i] += A[i][j] * x[j];
        }
        printf("\t%12.15lf    |   %12.15lf\n", b[i], sol[i]);
        somab += b[i];
        somaSol += sol[i];
    }
}
