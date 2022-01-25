#include <stdio.h>

void fillMatrix(int *matrix, int row, int col);
int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    int matrix[row][col];
    if (row <= 10 && col <= 10 && row > 0 && col > 0)
    {
        fillMatrix(matrix, row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                printf("%d ", matrix[i][j]);
            printf("\n");
        }
    }

    else
    {
        printf("Error");
    }
}

void fillMatrix(int *matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
                *((matrix + i * col) + j) = i;
            else if (i < j)
                *((matrix + i * col) + j) = i + j;
            else
                *((matrix + i * col) + j) = row - i;
        }
    }
}
