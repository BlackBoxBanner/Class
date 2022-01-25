#include<stdio.h>
#include<math.h>
#define MAX 10

int main()
{
    int i;
    double sum = 0, mean, inb = 0, SD;
    double x[MAX] = {1,2,3,4,5,6,7,8,9,10};

    for (i = 0; i < MAX; i++) 
    {
        sum += x[ i ]; //find sum
    }

    mean = sum/MAX;

    for (i = 0; i < MAX; i++) 
    {
        inb += pow(x[i]-mean,2); //find in the breaket^2
    }
    
    SD = (inb/MAX); //find SD

    printf("Standard Deviation is %.2lf\n", sqrt(SD));
    return 0;
}