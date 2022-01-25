#include <stdio.h>

//Function fahrenheit returns the Fahrenheit equivalent of a Kelvin temperature. float fahrenheit(int kelvin)
float fahrenheit(int kelvin)
{
    return (kelvin - 273.15) * 9 / 5 + 32;
}

// Function kelvin returns the Kelvin equivalent of a Fahrenheit temperature. float kelvin(int fahrenheit)
float kelvin(int fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

//In the main function, two inputs are entered at the same line. The first input is a float which is the temperature. The second input is a character which is the unit of temperature. 
//For the character input, If the character is 'K', you must call fahrenheit function and print the result in the main function. If the character is 'F', you must call kelvin function and print the result in the main function. Otherwise, print the value of the temperature input.
//Use only the single-selection form of the if statement (if...if...if...)

int main()
{
    float temp;
    char unit;
    scanf("%f %c", &temp, &unit);
    if (unit == 'K'|| unit == 'k')
    {
        printf("%.2f\n", fahrenheit(temp));
        return 0;
    }
    if (unit == 'F'|| unit == 'f')
    {
        printf("%.2f\n", kelvin(temp));
        return 0;
    }
    if (unit == 'C'|| unit == 'c')
    {
        printf("%.2f", temp);
        return 0;
    }
    return 0;
}