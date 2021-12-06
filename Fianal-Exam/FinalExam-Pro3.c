#include <stdio.h>
#include <math.h>
typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
} linear;

//
void inputLine(linear *line)
{
    scanf("(%d,%d), (%d,%d)", &line->x1, &line->y1, &line->x2, &line->y2);
}
void setSlopeAndLength(linear *line)
{
    double slope = 0;
    double length = 0;
    slope = (line->y2 - line->y1) / (line->x2 - line->x1);
    length = (float)sqrt((line->y2 - line->y1) * (line->y2 - line->y1) + (line->x2 - line->x1) * (line->x2 - line->x1));
    if (slope > 9999)
    {
        slope = 9999;
    }
    printf("Slope = %.2f\nLength = %.2f", slope, length);
}

int main()
{
    linear line;
    inputLine(&line);
    setSlopeAndLength(&line);
}
