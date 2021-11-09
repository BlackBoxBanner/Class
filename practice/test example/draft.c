#include <stdio.h>

//The printMatrix function must be implemented for printing the matrix. The print output must have three columns and three rows and the spacing of each column must be the tab space. 3*3 matrix is printed as below.
void printMatrix(int matrix[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

//The multiplyMatrix function will take two parameters for Matrix multiplication. To show the result, this function will call printMatrix function
void multiplyMatrix(int matrix1[3][3], int matrix2[3][3])
{
    int i, j, k, result[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printMatrix(result);
}

//Write a main function to print the result of the multiplication of two given matrices.
int main()
{
    int matrix1[3][3] = {{1, 8, 7}, {20, 5, 14}, {20, 1, 9}};
    int matrix2[3][3] = {{1, 14, 4}, {16, 5, 14}, {15, 6, 9}};
    scanf("%d %d %d %d %d %d", &matrix1[0][0],&matrix1[1][1],&matrix1[2][2],&matrix2[0][0],&matrix2[1][1],&matrix2[2][2]);
    printMatrix(matrix1);
    printMatrix(matrix2);
    multiplyMatrix(matrix1, matrix2);
    return 0;
}
