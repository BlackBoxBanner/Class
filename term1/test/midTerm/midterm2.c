#include<stdio.h>

char checkPalindrome(int studentId)
{
    char yes = 'y', no = 'n';
    int orig, left, reversed = 0;
    orig = studentId;

    while (studentId != 0) {
        left = studentId % 10;
        reversed = reversed * 10 + left;
        studentId /= 10;
    }
    if (orig == reversed)
    {
        return yes;
    }
    else
    {
        return no;
    }
    return 0;
}

int main()
{
    int studentId;
    char yes = 'y';
    scanf("%d" , &studentId);
    if (studentId < 0 || studentId >= 1000000)
    {
        return printf("ERROR");
    }

    if (checkPalindrome(studentId) == yes)
    {
        printf("Number %d is palindrome.", studentId);
    }
    else
    {
        printf("Number %d is NOT palindrome.", studentId);
    }

    return 0;
}
