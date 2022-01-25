#include<stdio.h> //standard input output
#include<math.h> //math function sqrt() pow()
#define MAX 10 //int MAX = 10;

int main()
{
    int i; //declare int variable name i
    float sum, mean, inb, SD; //declare float variable name ~~~~~
    float x[MAX] = {1,2,3,4,5,6,7,8,9,100}; //create array that have maximum cantainner at MAX

    for (i = 0; i <= MAX; i++) mean += x[ i ]/MAX; //find mean
    /*
    for (i = 0; i <= MAX; i++) //i++ = i + 1
    {
        mean = (mean + x[ i ])/MAX;
    }
    */
    for (i = 0; i <= MAX; i++) inb += (x[i]-mean)*(x[i]-mean); //find in the breaket^2
    SD = (inb/MAX); //find SD

    printf("Standard Deviation is %.2f\n", sqrt(SD));
    return 0;
}