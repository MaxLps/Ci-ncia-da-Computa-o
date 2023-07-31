//Grupo: MAXWEL BATALHA DA SILVA LOPES, HUGO VIDAL ALVES REZENDE, JULIANA NOGUEIRA PEIXOTO

#include <stdio.h>
#include <math.h>
#include <chrono>
#include <iostream>

#define N 1000
#define IMPRIMIR false

void imprimir_matrizAmpliada(double **A, double b[]);
void imprimir_matriz(double **A);
void geraMAtriz(double** a, double** as, double b[], double bs[]);
void pivoteamento_parcial(double** A, double b[], int k);
void eliminacaoGauss(double** A, double b[]);
void solucao_sistema(double** A, double b[], double x[]);
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

    eliminacaoGauss(A,b);
    solucao_sistema(A,b,x);

    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio).count();

    std::cout << "Tempo de execucao sem thread: " << duracao << " microssegundos" << std::endl;

    //verificaS(As,bs,x);
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
    //         as[i][j] = a[i][j];
    //     }
    //     std::cout << "Informe o valor para a posição [" << i << "] do vetor: ";
    //     std::cin >> b[i];
    //     bs[i] = b[i];
    // }

    if(IMPRIMIR){
        imprimir_matrizAmpliada(a,b);
    }
}

void pivoteamento_parcial(double** A, double b[], int k){
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
        }
        aux = b[indiceM];
        b[indiceM] = b[k];      //trocando as posições do vetor b para ficar de acordo com nova posições das linhas
        b[k] = aux;
}
void eliminacaoGauss(double** A, double b[]){
     int k, i, j;
    double m;
    for (j = 0; j < N; j++) {
        for (i = j + 1; i < N; i++) {
            m = -(A[i][j] / A[j][j]);
            for (k = j; k < N; k++) {
                A[i][k] = A[i][k] + (m * A[j][k]);
            }
            b[i] = b[i] + (m * b[j]);
        }
    }
}

void solucao_sistema(double** A, double b[], double x[]){
    double somatorio;
    int i, j;
    x[N-1] = b[N-1]/A[N-1][N-1];  //Como A virou uma matriz triangular superior podemos
    for(i=N-2; i>=0; i--){                             //achar o valor de xn diretamente com xn = bn/Ann
        somatorio=0;
        for(j=N-1; j>=i; j--){
            somatorio = somatorio + (A[i][j] * x[j]); //Realizando as substuiçoes sucessivas para encontrar
        }                                                   //os valores de todas as incógnitas x
        x[i] = (b[i] - somatorio)/A[i][i];
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