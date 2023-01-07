#include <stdio.h>
#include <math.h>
int main (){
	int x1, y1, x2, y2;
	double dp;
	scanf("%d %d",&x1, &y1);
	scanf("%d %d",&x2, &y2);
	dp = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
	printf("A distância entre os pontos = %.2lf\n", dp);
	return 0;
}
