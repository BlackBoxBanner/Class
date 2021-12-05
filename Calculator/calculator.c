#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void menu(int *a);

double disM0(double x, double y, double z, double dis)
{
    double root1, root2;
    root1 = (-y + sqrt(dis)) / (2 * x);
    root2 = (-y - sqrt(dis)) / (2 * x);
    printf("root1 = %.2lf and root2 = %.2lf", root1, root2);
}

double disL0(double x, double y, double z, double dis)
{
    double root1, root2, realPart, imagPart;
    realPart = -y / (2 * x);
    imagPart = sqrt(-dis) / (2 * x);
    printf("root1 = %.2lf+%.2lfi and root2 = %.2f-%.2fi", realPart, imagPart, realPart, imagPart);
}

double disE0(double x, double y, double z, double dis)
{
    double root1, root2;
    root1 = root2 = -y / (2 * x);
    printf("root1 = root2 = %.2lf;", root1);
}

void quatratic()
{

    double a, b, c, discriminant, root1, root2, realPart, imagPart;
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    // condition for real and different roots
    if (discriminant > 0)
    {
        disM0(a, b, c, discriminant);
    }

    // condition for real and equal roots
    else if (discriminant == 0)
    {
        disE0(a, b, c, discriminant);
    }

    // if roots are not real
    else
    {
        disL0(a, b, c, discriminant);
    }
}

double factorial_cal(double num)
{
    if (num == 1)
    {
        return 1;
    }
    else
        return num * factorial_cal(num - 1);
}

void factorial()
{
    double fact, a;
    printf("Input the number for Factorial : ");
    scanf("%lf", &fact);
    printf("The factorial of %.0lf is %.0lf.", fact, factorial_cal(fact));
}

int fibonacci_cal_pos(int fib)
{
    int i = 0, a = 0, b = 1, c;
    printf("0 , 1 ");
    for (i = 2; i < fib; i++)
    {
        a += b;
        printf(", %d ", a);
        c = a;
        a = b;
        b = c;
    }
    return 0;
}

void fibonacci_pos()
{
    int fib;
    printf("Enter the number to fibonacci : ");
    scanf("%d", &fib);
    fibonacci_cal_pos(fib);
}

int fibonacci_cal_neg(int fib)
{
    int i = 0, a = 0, b = 1, c;
    printf("0 , 1 ");
    for (i = 2; i < fib; i++)
    {
        a -= b;
        printf(", %d ", a);
        c = a;
        a = b;
        b = c;
    }
    return 0;
}

void fibonacci_neg()
{
    int fib;
    printf("Enter the number to fibonacci : ");
    scanf("%d", &fib);
    fibonacci_cal_neg(fib);
}

void MenuList()
{
    printf("\n=================================\n\n");
    printf("Calculator\n\n");
    printf("[1]\tQuadratic Fomula\n");
    printf("[2]\tFactoiral\n");
    printf("[3]\tFibonacci\n");
    printf("[0]\tExit");
    printf("\n\n=================================\n");
}

void fibonacci_menu_list()
{
    system("cls");
    MenuList();
    printf("\nFibonacci Calculator\n\n");
    printf("[1]\tPositive Fibonacci\n");
    printf("[2]\tNegative Fibonacci\n");
    printf("[0]\tBack");
    printf("\n\n=================================\n");
}

void fibonacci_menu()
{
    int b;
    fibonacci_menu_list();
    printf("\n\nEnter the number to select the positive or negative Fibonacci : ");
    scanf("%d", &b);
    system("cls");
    if (b >= 0 && b < 3)
    {
        switch (b)
        {
        case 1:
            MenuList();
            fibonacci_menu_list();
            printf("\n[1]\tPositive Fibonacci\n\n\n");
            fibonacci_pos();
            break;

        case 2:
            fibonacci_menu_list();
            printf("\n[2]\tNegative Fibonacci\n\n\n");
            fibonacci_neg();
            break;

        case 0:
            break;
        default:
            break;
        }
    }
    else
    {
        MenuList();
        printf("\nError. Try put another number.");
    }
}

void menu(int *a)
{
    int b;
    printf("\n\nEnter the number to select the Calculator : ");
    scanf("%d", &b);
    system("cls");
    if (b >= 0 && b < 4)
    {
        switch (b)
        {
        case 1:
            MenuList();
            printf("\n[1]\tQuadratic Fomula\n\n\n");
            quatratic();
            puts("");
            break;

        case 2:
            MenuList();
            printf("\n[2]\tFactoiral\n\n\n");
            factorial();
            break;

        case 3:
            fibonacci_menu();
            break;

        case 0:
            *a = 0;
            break;
        default:
            break;
        }
    }
    else
    {
        MenuList();
        printf("\nError. Try put another number.");
    }
}

int main()
{
    int a = 1, b = 1;
    system("cls");
    do
    {
        if (b == 1)
        {
            MenuList();
            b = 2;
        }
        menu(&a);
    } while (a == 1);

    system("cls");
    return 0;
}