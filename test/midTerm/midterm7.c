#include <stdio.h>

double kelvin(int tem)
{
    double kelvin;
    kelvin = ((tem - 32.0) / 1.8) + 273.0;

    return kelvin;
}

double fahren(int tem)
{
    double fahren;
    fahren = 1.8 * (tem - 273.0) + 32.0; 

    return fahren;
}

int main()
{
    int tem;
    double temp;
    char KFC;

    scanf("%d %c", &tem, &KFC);

    if (KFC == 'C')
    {
        printf("%.2f", tem);
    }
    
    if (KFC == 'K')
    {
        temp = fahren(tem);
        printf("%.2f", temp);
    }

    if (KFC == 'F')
    {
        temp = kelvin(tem);
        printf("%.2f", temp);
    }

    
    return 0;
}