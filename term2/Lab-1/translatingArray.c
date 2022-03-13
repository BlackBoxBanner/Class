// Create a program for translating, scaling, and rotating points in cartesian coordinates.

// Sueksit Vachirakumthorn 64070503450
#include <stdio.h>
#include <math.h>

// declare function
double translate(double lp[][2]);
double scaling(double lp[][2]);
double rotation(double lp[][2]);
double multiplyMatrix(double lp[][2], double x);

// main function
int main()
{
  // declare valiable
  double lp[][2] = {{1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1}, {8, 1}, {9, 1}, {10, 1}, {10, 2}, {10, 3}, {10, 4}, {10, 5}, {10, 6}, {10, 7}, {10, 8}, {10, 9}, {10, 10}, {9, 9}, {8, 8}, {7, 7}, {6, 6}, {5, 5}, {4, 4}, {3, 3}, {2, 2}};
  // declare x as getchar
  int x = getchar();

  // using switch case
  switch (x)
  {
  case 49:         // aski 49 is equal to 1 on the keyboard
    translate(lp); // call function
    break;         // break
  case 50:         // aski 50 is equal to 2 on the keyboard
    scaling(lp);   // call function
    break;         // break
  case 51:         // aski 51 is equal to 3 on the keyboard
    rotation(lp);
    break; // break
  default: // if not 1, 2, 3
    // error message
    printf("Error"); // print error message
    break;
  }
  return 0;
}

// function translate
double translate(double lp[][2])
{
  double x, y;                 // declare x and y
  scanf("%lf", &x);            // scanf x
  scanf("%lf", &y);            // scanf y
  for (int i = 0; i < 27; i++) // for loop
  {
    lp[i][0] += x;                                  // add x to lp[i][0]
    lp[i][1] += y;                                  // add y to lp[i][1]
    printf("(%.2lf, %.2lf)\n", lp[i][0], lp[i][1]); // print lp[i][0] and lp[i][1]
  }
  return 0;
}

// function scaling
double scaling(double lp[][2])
{
  double x, y;      // declare x and y
  scanf("%lf", &x); // scanf x
  scanf("%lf", &y); // scanf y
  // for loop
  for (int i = 0; i < 27; i++)
  {
    lp[i][0] *= x;                                  // multiply x to lp[i][0]
    lp[i][1] *= y;                                  // multiply y to lp[i][1]
    printf("(%.2lf, %.2lf)\n", lp[i][0], lp[i][1]); // print lp[i][0] and lp[i][1]
  }
  return 0;
}

// function rotation
double rotation(double lp[][2])
{
  double x;         // declare x
  scanf("%lf", &x); // scanf x

  // double pi = 3.14159265358979323846;
  // double radian = pi / 180;
  // for (int i = 0; i < 27; i++)
  // {
  //   buffer = (lp[i][0] * cos(x * radian)) - (lp[i][1] * sin(x * radian));
  //   lp[i][1] = (lp[i][0] * sin(x * radian)) + (lp[i][1] * cos(x * radian));
  //   lp[i][0] = buffer;
  //   printf("(%.2lf, %.2lf)\n", lp[i][0], lp[i][1]);
  // }
  multiplyMatrix(lp, x); // call function
  return 0;
}

double multiplyMatrix(double lp[][2], double x)
{
  double buffer; // declare buffer

  double pi = 3.14159265358979323846; // declare pi
  double radian = pi / 180;           // declare radian
  // for loop
  for (int i = 0; i < 27; i++)
  {
    buffer = (lp[i][0] * cos(x * radian)) - (lp[i][1] * sin(x * radian));   // buffer = (lp[i][0] * cos(x * radian)) - (lp[i][1] * sin(x * radian))
    lp[i][1] = (lp[i][0] * sin(x * radian)) + (lp[i][1] * cos(x * radian)); // lp[i][1] = (lp[i][0] * sin(x * radian)) + (lp[i][1] * cos(x * radian))
    lp[i][0] = buffer;                                                      // lp[i][0] = buffer
  }
  // for loop
  for (int x = 0; x < 27; x++)
  {
    printf("(%.2lf, %.2lf)\n", lp[x][0], lp[x][1]); // print lp[i][0] and lp[i][1]
  }
  return 0;
}