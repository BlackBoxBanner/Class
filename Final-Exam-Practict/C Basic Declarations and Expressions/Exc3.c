/*
    Write a C program to print the roots of Bhaskara’s formula from the given three floating numbers. 
    Display a message if it is not possible to find the roots. 
    Test Data :
    Input the first number(a): 25
    Input the second number(b): 35
    Input the third number(c): 12
    Expected Output:
    Root1 = -0.60000
    Root2 = -0.80000
*/

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, root1, root2;
    printf("Input the first number(a): ");
    scanf("%f", &a);
    printf("Input the second number(b): ");
    scanf("%f", &b);
    printf("Input the third number(c): ");
    scanf("%f", &c);
    printf("Root1 = %f\n", root1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a));
    printf("Root2 = %f\n", root2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a));
    return 0;
}