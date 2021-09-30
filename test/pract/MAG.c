#include<stdio.h>

double calMean(int x[])
{
    double mean;
    
    for (int i = 0; i < 9; i++)
    {
        if (x[i] < 0)
        {
            return -1;
        }
        else
        {
            mean += x[i];
        }
        
    }
    return mean;
}

void printMatrix(int mat[3][3])
{
    for (int i = 0; i < 3; i++) //horizontal
    {
        for (int p = 0; p < 3; p++) //vertical
        {
            printf("%d\t", mat[i][p]);
            
        }
        printf("\n");
    }
    
}
void createMatrix(int x[])
{
    int mat[3][3];
    int counter = 0;
    for (int i = 0; i < 3; i++) //horizontal
    {
        for (int p = 0; p < 3; p++) //vertical
        {
            mat[i][p] = x[counter];
            counter++; // ? counter = counter + 1 // counter += 1
        }
    }
    for (int z = 0; z < 3; z++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (z > x)
            {
                mat[z][x] = mat[z][x] + (z * x);
                // ! mat[z][x] += (z * x);
            }
            else
            {
                mat[z][x] += -z * x;
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
    printf("%.4lf\n", xBar);

    createMatrix(x);
    return 0;
}
