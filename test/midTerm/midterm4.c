#include <stdio.h>

int calLogic(int A[i], int B[i], char logic)
{
    int C[4];
    if (logic == '|')
    {
        
            C[i] = 0;
            if (A[i] == 0 && B[i] == 1 || A[i] == 1 && B[i] == 1)
            {
                C[i] = 1;
            }
    }
    if (logic == '&')
    {
        
            if (A[i] == B[i])
            {
                C[i] = 1;
            }
            if (A[i] != B[i])
            {
                C[i] = 0;
            }
    }
    return C;
}

int main()

{

    int A[4] = {0, 0, 1, 1};

    int B[4] = {0, 1, 0, 1};

        int C[4];

        char logic;

    //Receive input
    scanf("%c", &logic);
    //Calculate logic bit by bit
    for (int i = 0; i < 4; i++)
    {
        C[i] = calLogic(A[i], B[i], logic);
    }

    printTable(A, B, logic, C);

    return 0;
}