#include <stdio.h>
int main(){
    double x, y, kml;
    scanf("%lf %lf",&x, &y);
    kml = x/y;
    printf("%.3lf km/l\n",kml);
    return 0;
}