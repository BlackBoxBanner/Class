#include<stdio.h>

double calMean(int x[])
{
    double temp;
    
    for (int i = 0; i < 9; i++)
    {
        if (x[i] > 0)
        {
            temp += x[i];
        }
        else
        {
            return -1;
        }
    }

    temp /= 9;
    return temp;
}

void printMatrix(int mat[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    
}

void createMatrix(int x[])
{
    int mat[3][3];
    int counter = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = x[counter];
            counter++;
        }
        
    }
    for (int p = 0; p < 3; p++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (p > x)
            {
                mat[p][x] += (p * x);
            }
            else
            {
                mat[p][x] += (-p * x);
            }
            
        }
        
    }
    
    
    printMatrix(mat);
}

int main()
{
    int x[9];
    double xBar;

    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &x[i]);
    }
    xBar = calMean(x);
    printf("%.4lf\n",xBar);

    createMatrix(x);

    return 0;
}