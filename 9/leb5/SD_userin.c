#include<stdio.h>
#include<math.h>
#define MAX 10

int main()
{
    int counter;
    float sum, mean, inb, SD;
    float x[MAX] = {1,4,3,5,8,3,4,9,6,4};

    for (counter = 0; counter <= MAX; counter++) mean += x[ counter ]/MAX; //find sum
    for (counter = 0; counter <= MAX; counter++) inb += (x[counter]-mean)*(x[counter]-mean); //find in the breaket^2
    SD = (inb/MAX); //find SD

    printf("Standard Deviation is %.2f\n", sqrt(SD));
    return 0;
}