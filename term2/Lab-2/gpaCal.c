#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char courseName[10][50]; // array of strings
  char grade[10][5];       // array of strings
  int credit[10];          // array of integers

  for (int i = 0; i < 10; i++)
  {
    credit[i] = 0;              // initialize all elements to 0
    strcpy(courseName[i], "-"); // initialize all elements to "-"
    strcpy(grade[i], "-");      // initialize all elements to "-"
  }

  int position;    // integer
  char buffer[50]; // string
  int counter = 1; // integer 

  scanf("%d", &position); // read position

  while (position != 0)
  {
    if (counter != 11)
    {
      while (strcmp(courseName[position - 1], "-") != 0)
      {
        position++; // increment position
        if (position > 10)
        {
          position = 0; // reset position
        }
      }

      fgetc(stdin);                             // read newline
      gets(buffer);                             // gets course name
      strcpy(courseName[position - 1], buffer); // copy course name to array
      scanf("%s", grade[position - 1]);         // scan grade
      scanf("%d", &credit[position - 1]);       // scan credit
      counter++;                                // increment counter
    }
    else
    {
      position = 0; // reset position
    }

    if (counter != 11)
    {
      scanf("%d", &position); // read position
    }
  }

  for (int i = 0; i < 10; i++)
  {
    printf("%2d %-50s %-3s %3d\n", i + 1, courseName[i], grade[i], credit[i]); // print array
  }
  printf("\n"); // print newline

  int greadCount = 0; // integer
  float GPA;          // float
  for (int i = 0; i < 10; i++)
  {
    if (strcmp(grade[i], "-") != 0)
    {
      greadCount++; // increment greadCount
    }

    if (strcmp(grade[i], "A") == 0)
    {
      GPA = GPA + (4 * credit[i]); // GPA = GPA + (4 * credit[i])
    }
    else if (strcmp(grade[i], "B+") == 0)
    {
      GPA = GPA + (3.5 * credit[i]); // GPA = GPA + (3.5 * credit[i])
    }
    else if (strcmp(grade[i], "B") == 0)
    {
      GPA = GPA + (3 * credit[i]); // GPA = GPA + (3 * credit[i])
    }
    else if (strcmp(grade[i], "C+") == 0)
    {
      GPA = GPA + (2.5 * credit[i]); // GPA = GPA + (2.5 * credit[i])
    }
    else if (strcmp(grade[i], "C") == 0)
    {
      GPA = GPA + (2 * credit[i]); // GPA = GPA + (2 * credit[i])
    }
    else if (strcmp(grade[i], "D+") == 0)
    {
      GPA = GPA + (1.5 * credit[i]); // GPA = GPA + (1.5 * credit[i])
    }
    else if (strcmp(grade[i], "D") == 0)
    {
      GPA = GPA + (1 * credit[i]); // GPA = GPA + (1 * credit[i])
    }
    else if (strcmp(grade[i], "F") == 0)
    {
      GPA = GPA + (0 * credit[i]); // GPA = GPA + (0 * credit[i])
    }
  }
  int sumCredit = 0; // integer
  for (int i = 0; i < 10; i++)
  {
    sumCredit = sumCredit + credit[i]; // sumCredit = sumCredit + credit[i]
  }
  GPA = GPA / sumCredit;       // GPA = GPA / sumCredit
  printf("GPA = %.2f\n", GPA); // print GPA

  return 0; // return 0
}