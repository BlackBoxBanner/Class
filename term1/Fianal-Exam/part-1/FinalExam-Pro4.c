#include <stdio.h>
#include <math.h>

int calSum(double A[], int n, double *sum, double *Asum)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        *sum += A[i];
        *Asum += (A[i] * A[i]);
    }
}

void calMeanSD(double A[], int n, double *mean, double *sd)
{
    int i;
    double sum = 0;
    double Asum = 0;
    calSum(A, n, &sum, &Asum);
    *mean = sum / n;
    *sd = sqrt((Asum - (sum * sum) / n) / (n - 1));
}
int main()
{
    double A[10000];
    double mean = 0;
    double sd = 0;
    int n = 0;
    int loop;
    scanf("%d", &n);
    for (loop = 0; loop < n; loop++)
    {
        scanf("%lf", &A[loop]);
    }
    calMeanSD(A, n, &mean, &sd);
    printf("%.2f   %.2f", mean, sd);
}
