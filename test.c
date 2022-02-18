#include <stdio.h>
#include <string.h>

int main()
{
/*   char input[50];
  char courseName[10][50];
  char grade[10][5];
  int credit[10];
  double newGrade;
  double newCredit;
  double total;

  for (int i = 0; i < 10; i++)
  {
    credit[i] = 0;
    strcpy(courseName[i], "-");
    strcpy(grade[i], "-");
  }

  int position;
  scanf("%d", &position);
  while (position != 0)
  {
    int n;
    int count = 0;
    while (count < 10)
    {
      scanf("%d", &n);
      fgetc(stdin);

      if (n == 0)
      {
        break;
      }
      while (strcmp(courseName[position - 1], "-") != 0)
      {
        n++;
        if (n > 10)
        {
          n = 0;
        }
      }
      gets(input);
      strcpy(courseName[position - 1], input);
      scanf("%s", grade[position - 1]);
      scanf("%d", &credit[position - 1]);

      count++;
    }
  }

  for (int i = 0; i < 10; i++)
  {
    printf("%2d %-50s %-3s %3d\n", i + 1, courseName[i], grade[i], credit[i]);
  }

  for (int i = 0; i < 10; i++)
  {
    if (strcmp(grade[i], "-") == 0)
    {
      continue;
    }
    else if (strcmp(grade[i], "A") == 0)
    {
      newGrade += 4 * credit[i];
      newCredit += credit[i];
    }
    else if (strcmp(grade[i], "B+") == 0)
    {
      newGrade += 3.5 * credit[i];
      newCredit += credit[i];
    }
    else if (strcmp(grade[i], "B") == 0)
    {
      newGrade += 3 * credit[i];
      newCredit += credit[i];
    }
    else if (strcmp(grade[i], "C+") == 0)
    {
      newGrade += 2.5 * credit[i];
      newCredit += credit[i];
    }
    else if (strcmp(grade[i], "C") == 0)
    {
      newGrade += 2 * credit[i];
      newCredit += credit[i];
    }
    else if (strcmp(grade[i], "D+") == 0)
    {
      newGrade += 1.5 * credit[i];
      newCredit += credit[i];
    }
    else if (strcmp(grade[i], "D") == 0)
    {
      newGrade += 1 * credit[i];
      newCredit += credit[i];
    }
    else if (strcmp(grade[i], "F") == 0)
    {
      newGrade += 0 * credit[i];
      newCredit += credit[i];
    }
  }

  total = newGrade / newCredit;

  printf("\nGPA = %.2lf\n", total); */
  
  double x,h;

  h = ('x'-'W')/3;
  printf("%lf",h);

  return 0;
}