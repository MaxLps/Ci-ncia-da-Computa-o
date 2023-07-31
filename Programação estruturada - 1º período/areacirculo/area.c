#include <stdio.h>
#define pi 3.14159
int main(){
	double raio, area;
	scanf("%lf", &raio);
	area = raio * raio * pi;
	printf("A=%.4lf", area);
	return 0;
}
