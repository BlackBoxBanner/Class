void depositMoney(ACCOUNT acct[],ACCOUNT *loginAcct,int n);
void updateAccount(ACCOUNT acct[],int n);
void enquireBalance(ACCOUNT acct);

void depositMoney(ACCOUNT acct[],ACCOUNT *loginAcct,int n)
{
    double deposit_Money;
    printf("Enter deposit amount : ");
    scanf("%lf",&deposit_Money);
    loginAcct -> balance = loginAcct -> balance + deposit_Money;
    enquireBalance(*loginAcct);
    for (int i = 0; i < n; i++)
    {
        if( strcmp(acct[i].id,loginAcct -> id) == 0 )
        {
            acct[i].balance +=  deposit_Money;
        }
    }
    updateAccount(acct,n);
}

void updateAccount(ACCOUNT acct[],int n)
{
    FILE *outFile = fopen("atmDB.txt","w");
    for (int i = 0; i < n; i++)
    {
        fprintf(outFile,"%s,%s,%s,%.2f\n",acct[i].id,acct[i].name,acct[i].password,acct[i].balance);
    }
    fclose(outFile);
}
