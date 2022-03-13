#include <stdio.h>
int main()
{
  int n, factor, sum;

  while (-1)
  {
    sum = 0;
    printf("Please input a positive integer(n):");
    scanf("%d", &n);
    printf("\nFactors of n:");
    if (n < 0)
    {
      printf("Program End.");
      break;
    }
    
    for (factor = 1; factor <= n; factor++)
    {
      if (n % factor == 0)
      {
        printf("%d ", factor);
        sum += factor;
      }
    }
    printf("\nSummation of factors is %d.\n\n", sum);
  }

  return 0;
}
