#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

void quatratic() {

    double a, b, c, discriminant, root1, root2, realPart, imagPart;
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    // condition for real and different roots
    if (discriminant > 0) {
        disM0(a, b, c, discriminant);
    }

    // condition for real and equal roots
    else if (discriminant == 0) {
        disE0(a, b, c, discriminant);
    }

    // if roots are not real
    else {
        disL0(a, b, c, discriminant);
    }
} 

void MenuList()
{
    printf("\n=================================\n\n");
    printf("\tCalculator\n\n");
    printf("[1]\tQuadratic Fomula\n");\
    printf("[0]\tExit");
    printf("\n\n=================================\n");
}

void menu(int *a)
{
    int b;
    printf("\n\nEnter the number to select the Calculator : ");
    scanf("%d", &b);
    system("cls");
    if (b>=0 && b<2)
    {
        switch (b)
        {
        case 1:
        MenuList();
        printf("\n[1]\tQuadratic Fomula\n\n\n");
        quatratic();
        puts("");
        
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
        if(b == 1)
        {   
            MenuList();
            b = 2;
        }
        menu(&a);
    } while (a == 1);

    system("cls");
    return 0;
}