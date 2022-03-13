#include <stdio.h>

// Exercise 1
/* int main()
{
  int height;

  printf("Please input your height: ");
  scanf("%d", &height);

  if (height <= 120)
  {
    printf("Your ticket price is 250 baht");
  }
  else
  {
    printf("Your ticket price is 350 baht");
  }
  return 0;
} */

// Exercise 2
// Problem 2.1
/* int main()
{
  int x;
  printf("x = ");
  scanf("%d", &x);
  if (x >= 0)
    if (x <= 8)
      printf("A");
    else
      printf("B");
  return 0;

  // -3 : Nothin
  // 5 : A
  // 10 : B
}*/

// Problem 2.2
/* int main()
{
  int x;
  printf("x = ");
  scanf("%d", &x);
  if (x >= 0)
  {
    if (x <= 8)
      printf("A");
  }
  else
    printf("B");
  return 0;

  // -3 : B
  // 5 : A
  // 10 : Nothing
} */

/* Why do Program 2.1 and Program 2.2 obtain the different results? (Explain)
Ans : Program 2.1 and Program 2.2 obtain the different results because the if statement is not enclosed in the same block. */

// Exercise 3
/* int main()
{
  char ch;
  printf("Enter any alphabet:");
  scanf("%c", &ch);
  if (ch >= 'A' && ch <= 'Z')
    printf("Capital Letter");
  else if (ch >= 'a' && ch <= 'z')
    printf("Small Letter");
  else if (ch >= '0' && ch <= '9')
    printf("Digit");
  else
    printf("Special Character");
  return 0;
} */

// Exercise 4
/* int main()
{
  char ch;
  printf("Enter any alphabet:");
  scanf("%c", &ch);
  switch (ch)
  {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
    printf("Vowel");
    break;
  default:
    printf("Consonant");
    break;
  }
  return 0;
} */
