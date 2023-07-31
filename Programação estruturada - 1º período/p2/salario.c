#include<stdio.h>

struct DATA {
    int dia;
    int mes;
    int ano;
};

struct FUNCIONARIO {
    int matricula;
    struct DATA contratacao;
    float salario;
};

int main(void) {
    FILE *a;
    a = fopen ("arquivo.txt", "r");
	return 0;
}
