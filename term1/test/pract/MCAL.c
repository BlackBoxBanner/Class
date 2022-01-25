#include<stdio.h>


double calMean(int x[]) //calMean function create
{
    double mean;
    for (int i = 0; i < 9; i++) //set up loop to check negative numbers in the array.
    {
        if (x[i] < 0) // check if in x[] is a negative number.
        {
            return -1; //return -1
        }
        else // if not then add all num of x[] into temp.
        {
            mean += x[i]; //sum from array x to temp.
        }
    }

    mean /= 9; //temp devided by the maxNum = 9
    return mean; //return tmean
}

void printMatrix(int mat[3][3])
{
    for (int i = 0; i < 3; i++) //loop for horizontal
    {
        for (int o = 0; o < 3; o++) //loop for vertical
        {
            printf("%d\t",mat[i][o]);
        }
        printf("\n");
    }
}

void createMatrix(int x[])
{
    int mat[3][3]; 
    
    //create matrix 3 * 3
    int temp = 0;
    for (int i = 0; i < 3; i++) // horizontal
    {
        for (int o = 0; o < 3; o++) // vertical
        {
            mat[i][o] = x[temp]; //put num in array x into mat[][]
            temp++; //temp = temp + 1;
        }
    }
    
    for (int p = 0; p < 3; p++) // horizontal
    {
        for (int x = 0; x < 3; x++) // vertical
        {
            if (p > x) // check if p is more than x
            {
                mat[p][x] = mat[p][x] + (p * x); // if yes then using p * x
            }
            else
            {
                mat[p][x] = mat[p][x] + (-p * x); // others then using -p * x
            }
            
        }
        
    }
    
    
    printMatrix(mat);
}

int main()
{
    int x[9];
    double xBar;

    for (int i = 0; i < 9; i++) // scan for Input
    {
        scanf("%d", &x[i]);
    }
    

    xBar = calMean(x);
    printf("%0.4lf\n",xBar); //print mean value

    createMatrix(x);

    return 0;
}