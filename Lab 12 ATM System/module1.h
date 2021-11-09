typedef struct
   {
   } ACCOUNT;

int loadAccount(ACCOUNT acct[]);
int authenticate(ACCOUNT acct[],int n,char id[],char pwd[],ACCOUNT *loginAcct);
