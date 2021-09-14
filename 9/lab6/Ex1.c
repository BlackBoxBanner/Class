#include<stdio.h>
#include<math.h>

int main()
{
    double x1 = fabs( 7.5 );
    double x2 = floor( 7.5 );
    double x3 = fabs( 0.0 );
    double x4 = ceil( 0.0 );
    double x5 = fabs( -6.4 );
    double x6 = ceil( -6.4 );
    double x7 = ceil( -fabs( -8 + floor( -5.5 )));

    printf("x = %.2lf\n", x1);
    printf("x = %.2lf\n", x2);
    printf("x = %.2lf\n", x3);
    printf("x = %.2lf\n", x4);
    printf("x = %.2lf\n", x5);
    printf("x = %.2lf\n", x6);
    printf("x = %.2lf\n", x7);
    return 0;
}

