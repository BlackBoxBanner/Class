/*
14-11-2021
PHITCHAYADA SONGRAK ID:64070503439
SIRIKARN AUEAMORNSUK ID:64070503453
Yanawut Pasacheewa ID: 64070503463
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "module1.h"
#include "module2.h"
#include "module3.h"

ACCOUNT loginAcct;

int main()
{
    ACCOUNT acct[5];
    int numAcc = 0;
    char id[256];
    char pwd[256];
    int valid = 0;
    int count = 0;
    numAcc = loadAccount(acct);
    while ((valid != 1) && (count != 3))
    {
        printf("Enter ID: ");
        scanf("%s", id);
        printf("Enter password: ");
        scanf("%s", pwd);
        valid = authenticate(acct, numAcc, id, pwd, &loginAcct);
        if (valid == 1)
        {
            count = 0;
        }
        if (valid == 0)
        {
            puts("Your id or password are incorrect");
        }

        count++;
    }

    if (count == 3)
    {
        puts("You enter wrong password for 3 times.");
        puts("Please try again later.");
        exit(1);
    }
    puts("Login successfully");
    selectTransaction(acct, &loginAcct, numAcc);
}
