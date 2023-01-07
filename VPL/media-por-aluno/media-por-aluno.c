#include <stdio.h>
int main(){
	float grupo, p, t, prova1, prova2;
	printf("Digite a nota de participação do grupo\n");
		scanf("%f",&p);
	printf("Digite a nota do trabalho em grupo\n");
		scanf("%f",&t);
	printf("Digite a nota da prova1\n");
		scanf("%f",&prova1);
	printf("Digite a nota da prova2\n");
		scanf("%f",&prova2);
	grupo = (p+(2*t))/3;
	float media = ((2*prova1) + (2*prova2) + grupo)/5;
	printf("A média do aluno é: %.2f\n",media);
}
