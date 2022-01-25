/*
    Write a C program to read an amount (integer value) and break the amount into smallest possible number of bank notes.

    Test Data :
    Input the amount: 375
    Expected Output:
    There are:
    3 Note(s) of 100.00
    1 Note(s) of 50.00
    1 Note(s) of 20.00
    0 Note(s) of 10.0
    1 Note(s) of 5.00
    0 Note(s) of 2.00
    0 Note(s) of 1.00
*/

#include <stdio.h>

int main()
{
    int amount, note100, note50, note20, note10, note5, note2, note1;
    
    printf("Input the amount: ");
    scanf("%d", &amount);
    note100 = amount / 100;
    amount = amount % 100;
    note50 = amount / 50;
    amount = amount % 50;
    note20 = amount / 20;
    amount = amount % 20;
    note10 = amount / 10;
    amount = amount % 10;
    note5 = amount / 5;
    amount = amount % 5;
    note2 = amount / 2;
    amount = amount % 2;
    note1 = amount / 1;
    amount = amount % 1;
    printf("There are:\n");
    printf("%d Note(s) of 100.00\n", note100);
    printf("%d Note(s) of 50.00\n", note50);
    printf("%d Note(s) of 20.00\n", note20);
    printf("%d Note(s) of 10.00\n", note10);
    printf("%d Note(s) of 5.00\n", note5);
    printf("%d Note(s) of 2.00\n", note2);
    printf("%d Note(s) of 1.00\n", note1);
    return 0;
}
