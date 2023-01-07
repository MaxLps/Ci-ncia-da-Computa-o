#include <stdio.h>
#include <math.h>
int main (){
	int a, b, c, delta;
	double x1, x2;
	printf("Digite o valor de A\n");
		scanf("%d", &a);
	printf("Digite o valor de B\n");
                scanf("%d", &b);
	printf("Digite o valor de C\n");
                scanf("%d", &c);
	delta = pow(b,2)-4*a*c;
	x1 = (-b + sqrt(delta)) / (2*a);
	x2 = (-b - sqrt(delta)) / (2*a);
	printf("As raízes são %.2lf e %.2lf\n",x1 ,x2);
	return 0;
}
