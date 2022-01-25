void enquireBalance(ACCOUNT acct);
void selectTransaction(ACCOUNT acct[],ACCOUNT *loginAcct,int n);
void withdrawMoney(ACCOUNT acct[],ACCOUNT *loginAcct,int n);
void depositMoney(ACCOUNT acct[],ACCOUNT *loginAcct,int n);


void withdrawMoney(ACCOUNT acct[],ACCOUNT *loginAcct,int n)
{
    double withdraw_Money;
    printf("Enter withdrawal amount : ");
    scanf("%lf",&withdraw_Money);
    loginAcct -> balance = loginAcct -> balance - withdraw_Money;
    enquireBalance(*loginAcct);
    for (int i = 0; i < n; i++)
    {
        if( strcmp(acct[i].id,loginAcct -> id) == 0 )
        {
            acct[i].balance -=  withdraw_Money;
        }
    }
    updateAccount(acct,n);
}
void enquireBalance(ACCOUNT acct)
{
    printf("Account ID: %s\n",acct.id);
    printf("Account Name: %s\n",acct.name);
    printf("Balance: %.2lf\n",acct.balance);
}
void selectTransaction(ACCOUNT acct[],ACCOUNT *loginAcct,int n)
{
    int menu=0;
    while (1)
    {
        puts("[1] Withdraw");
        puts("[2] Deposit");
        puts("[3] Check balance");
        puts("[4] Quit");
        printf("Please enter : ");
        scanf("%d",&menu);
        if (menu == 1)
        {
            puts("=====WITHDRAW=====");
            puts("");
            withdrawMoney(acct,loginAcct,n);
            puts("");
            puts("==================");
        }

        else if (menu == 2)
        {
            puts("=====DEPOSIT=====");
            puts("");
            depositMoney(acct,loginAcct,n);
            puts("");
            puts("=================");
        }

        else if (menu == 3)
        {
            puts("=====BALANCE=====");
            puts("");
            enquireBalance(*loginAcct);
            puts("");
            puts("=================");
        }

        else if (menu == 4)
        {
            puts("");
            puts("=====THANK YOU=====");
            exit(1);
        }
    }
    
    
}