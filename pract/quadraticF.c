#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    double a, b, c, x, sqa, invb, rep, ren, powb, ac4, insq, und;
    printf("Enter number constant : \n");
    printf ("Enter a = ");
    scanf("%lf",&a);
    printf ("Enter b = ");
    scanf("%lf",&b);
    printf ("Enter c = ");
    scanf("%lf",&c);

    if (a == 0)
    {
        printf("Error");
    }
    
    powb = pow(b,2);
    ac4 = a * c * 4;
    insq = powb - ac4;
    sqa = sqrt(insq);
    invb = -1 * b;
    und = a * 2;

    rep = (invb + sqa)/und;
    ren = (invb - sqa)/und;

    if(sqa <= 0 ){
        printf("Error");
    }
    else
    {
        printf("The answer of this quadratic fomula is %f or %f.", rep, ren);
    }
    return 0;
}
