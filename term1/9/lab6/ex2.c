#include<stdio.h>
#include<math.h>

double hcal(double x, double y)
{
    return sqrt(pow(x,2)+pow(y,2));
}

int main()
{
    double a, b, c;
    //a^2 = b^2 + c^2

    printf("Enter two side : ");
    scanf("%lf %lf",&a, &b); //recieve 2 numbers
    c = hcal(a, b); //use function hcal

    printf("A = %.3lf, B = %.3lf, C = %.3lf", a, b, c);
    return 0;
}
