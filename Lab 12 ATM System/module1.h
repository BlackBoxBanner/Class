typedef struct
   {
      char id[256];
      char name[256];
      char password[256];
      double balance;
   } ACCOUNT;

int loadAccount(ACCOUNT acct[])
{
   FILE* inFile = fopen("atmDB.txt","r");
   if(inFile == NULL)
   {
      printf("Error opening file: \n");
      exit(1);
   }
   
   char buffer[256];
   char *token;
   int c=0;
   int r=0;
   while(fgets(buffer,sizeof(buffer),inFile) != NULL)
   {
      token = strtok(buffer,",");
      c = 0;
      while (token != NULL)
      {
         if( c == 0)
         {
            strcpy(acct[r].id,token);
         }
         else if ( c == 1)
         {
            strcpy(acct[r].name,token);
         }
         else if ( c == 2)
         {
            strcpy(acct[r].password,token);
         }
         else if ( c == 3)
         {
            sscanf(token,"%lf",&acct[r].balance);
         }
         token = strtok(NULL,",");
         c++;
      }
      r++;
   }
   fclose(inFile);
   return r;
}
int authenticate(ACCOUNT acct[],int n,char id[],char pwd[],ACCOUNT *loginAcct)
{
   int check=0;
   for (check = 0 ; check < n ; check++)
   {
      if( strcmp(id,acct[check].id) == 0 && strcmp(pwd,acct[check].password) == 0)
      {
         *loginAcct=acct[check];
         return 1;
      }
   }
   return 0;
}
