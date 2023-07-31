#include <stdio.h>
int main(){
	float a;
	float b;
	float c;
	float d;
	printf("Digite o primeiro número\n");
	scanf("%f",&a);
	printf("Digite o segundo número\n");
	scanf("%f",&b);
	printf("Digite o terceiro número\n");
	scanf("%f",&c);
	d = (a + b + c) / 3;
	printf("A média arimética entre os três números é: %.2f\n",d);
	return 0;
}


