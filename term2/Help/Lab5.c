#include <stdio.h>

// int main()
// {
//   int num1, num2, space,sum;
//   scanf("%d %d", &num1, &num2);
//   space = num2 - num1;
//   for (int i = 0; i < (space); i++)
//   {
//     sum = num1 + num2;
//     num1++;
//   }
//   printf("%d", sum);
//   return 0;
// }

// int main()
// {
//   int i, j, sum = 0;
//   scanf("%d %d", &i, &j);
//   for (i = i + 1; i < j; i++)
//   {
//     sum += i;
//     printf("%d = %d + %d\n", sum , i, sum);
//   }
//   printf("%d\n", sum);
//   return 0;
// }

int main()
{
  double i, j, sum = 0;
  scanf("%lf %lf", &i, &j);
  if (i < j)
  {
    for (i = i + 1; i < j; i++)
    {
      sum += i;
    }
  }
  else
  {
    for (j = j + 1; j < i; j++)
    {
      sum += j;
    }
  }
  printf("%.0lf\n", sum);
  return 0;
}

// int main()
// {
//   int i, sum = 0;
//   scanf("%d %d", &i, &sum);
//   for (i = i + 1; i < sum; i++)
//   {
//     sum += i;
//     printf("%d = %d + %d\n", sum, i, sum);
//   }
//   printf("%d\n", sum);
//   return 0;
// }

// int main()
// {
//   int i, num1, num2;
//   scanf("%d %d", &num1, &num2);
//   for (i = num1 + 1; i <= num2; i++)
//   {
//     if (i % 7 == 0)
//     {
//       printf("%d\n", i);
//     }
//   }
//   return 0;
// }
