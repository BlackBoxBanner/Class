#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define SSMax 4

void ex1()
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
    printf("x = %.2lf\n\n", x7);
}

double hcal(double x, double y)
{
    return sqrt(pow(x,2)+pow(y,2));
}

void ex2()
{
    double a, b, c;
    //a^2 = b^2 + c^2

    printf("Enter two side : ");
    scanf("%lf %lf",&a, &b); //recieve 2 numbers
    c = hcal(a, b); //use function hcal

    printf("A = %.3lf, B = %.3lf, C = %.3lf\n\n", a, b, c);

}

double cTf(double cel)
{
    double far;
    far = ( cel * 1.8 ) + 32;
    return far;
}

double fTc(double far)
{
    double cel;
    cel = ( far - 32 ) * 0.5555555;
    return cel;
}

void ex3()
{
    int i;
    int j;
    double fahrenheit;
    double celsius;
    printf("%7s%12s%3s%12s%10s", "Celsius" , "Fahrenheit" , "|" , "Fahrenheit" , "Celsius\n" );
    j = 32;
    for (i = 0; i < 300; i++)
    {
        if (i <= 100 )
        {
            printf("%7d%12.2lf", i, cTf(i));
        }
        if (j <= 212)
        {
            if (i <= 100)
            {
                printf("%3s", "|");
                printf("%12d%9.2lf\n", j, fTc(j));
                j++;
            }
            else
            {
                printf("%22s", "|");
                printf("%12d%9.2lf\n", j, fTc(j));
                j++;
            }
            
        }
        
    }
    printf("\n");
}

void simpleSort(double num1, double num2, double num3, double num4)
{
    double simsort[SSMax] = { num1 , num2 , num3 , num4 };
    int i, j, temp;
    for (i = 0; i < SSMax; ++i)
    {
        for (j = i + 1; j < SSMax; ++j)
        {
            if (simsort[i] < simsort[j])
            {
                temp =  simsort[i];
                simsort[i] = simsort[j];
                simsort[j] = temp;
            }
        }
    }
    printf("Sort number are :");
    for (i = 0; i < SSMax; i++)
    {
        printf("\t%.2lf", simsort[i] );
    }
    
}

void ex4()
{
    double num1, num2, num3, num4, finalnum;
    printf("Enter 4 unsorted numbers : ");
    scanf("%lf %lf %lf %lf", &num1, &num2, &num3, &num4 );
    simpleSort(num1, num2, num3, num4);
    printf("\n\n");
}

void menu(int *a)
{
    int b;
    printf("Exercise\n\n");
    printf("[1]\tBuilt-in Functions\n");
    printf("[2]\tHypotenuse\n");
    printf("[3]\tTemperature Conversion\n");
    printf("[4]\tSimple Sort\n");
    printf("[5]\tExit");
    printf("\n\nEnter the number to select the exercise : ");
    scanf("%d", &b);
    system("cls");
    if (b>0 && b<6)
    {
        switch (b)
        {
        case 1:
        printf("[1]\tBuilt-in Functions\n\n\n");
        ex1();
        puts("");
            break;
        case 2:
        printf("[2]\tHypotenuse\n\n\n");
        ex2();
        puts("");
            break;
        case 3:
        printf("[3]\tTemperature Conversion\n\n\n");
        ex3();
        puts("");
            break;
        case 4:
        printf("[4]\tSimple Sort\n\n\n");
        ex4();
        puts("");
            break;
        case 5:
        *a = 0;
            break;
        default:
            break;
        }
    }
    else
    {
        printf("Error. Try put another number.\n\n\n");
    }
    
}

int main()
{
    int a = 1;
    system("cls");
    do
    {
        menu(&a);
    } while (a == 1);

    system("cls");
    return 0;
}
