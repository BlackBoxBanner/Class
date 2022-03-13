/* #include <stdio.h>
int main()
{
  int n, factor, sum;

  while (-1)
  {
    sum = 0;
    printf("Please input a positive integer(n):");
    scanf("%d", &n);
    if (n < 0)
    {
      printf("\nProgram End.");
      break;
    }
    printf("Factors of n:");
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
} */

/* #include <stdio.h>
int main()
{
  int n, factor, sum = 0;
  int choose;

  printf("Please input a positive integer(n):");
  scanf("%d", &n);

  while (choose > 0)
  {
    sum = 0;
    printf("Factors of n:", n);
    for (factor = 1; factor <= n; factor++)
    {
      if (n % factor == 0)
      {
        printf("%d ", factor);
        sum += factor;
      }
    }
    printf("\nSummation of factors is %d.\n\n", sum);
    printf("Please input a positive integer(n):");
    scanf("%d", &n);
    choose = n;
  }

  printf("Program End.");

  return 0;
} */


/* #include<stdio.h>
int main()
{
    int n,factor,sum=0 ;
    printf("Please input a positive integer(n):");
    scanf("%d",&n);
    printf("Factors of n:",n);
    for (factor=1; factor<=n; factor++)
    {
        if(n%factor==0)
        {
            printf("%d ",factor);
            sum +=factor;
        }
    }
    printf("\nSummation of factors is %d.",sum);

    return 0;
} */