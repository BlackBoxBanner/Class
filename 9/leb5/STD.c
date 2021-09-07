#include<stdio.h>
#include<math.h>
#define MAX 10

int main()
{
    int counter;
    double sum = 0, mean, inb = 0, SD;
    double x[MAX] = {1,2,3,4,5,6,7,8,9,10};

    for (counter = 0; counter < MAX; counter++) 
    {
            sum += x[ counter ]; //find sum
    }

    mean = sum/MAX;

    for (counter = 0; counter < MAX; counter++) 
    {
        inb += pow(x[counter]-mean,2); //find in the breaket^2
    }
    
    SD = (inb/MAX); //find SD

    printf("Standard Deviation is %.2lf\n", sqrt(SD));
    return 0;
}