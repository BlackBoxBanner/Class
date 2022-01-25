#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct data
{
    char Year[256];
    char Term[256];
    char Code[256];
    char Cours[256];
    double Credit;
    double Grade;
};

int checkLine()
{
    int line = 0;
    char buffer[256];
    FILE* inFile = NULL;
    inFile = fopen("transkip.csv","r");

    if(inFile == NULL)
    {
        printf("Error opening file: \n");
        exit(1);
    }

    while (fgets(buffer,sizeof(buffer),inFile) != NULL)
    {
        line++;
    }
    printf("Check line Success. Line = %d\n",line);
    return line;
}

double calculate_GPAX(int line, struct data *transkip)
{
    double gpax,sumGC,sumC;
    int i;
    for(i = 0; i < line; i++)
    {
        sumGC += (transkip[i].Grade *  transkip[i].Credit);
        sumC += transkip[i].Credit;
    }
    puts(" ");
    gpax = sumGC/sumC;
    return gpax;
}

double calculateSub(int line, struct data *transkip,int sub)
{
    double gpasub,sumGC,sumC;
    int i;

    if(sub == 0)
    {
        for(i = 0; i < line; i++)
        {
            if( !strcmp(transkip[i].Cours,"Mathematics") )
            {
                sumGC += (transkip[i].Grade *  transkip[i].Credit);
                sumC += transkip[i].Credit;
            }
        }
        puts("Math");
    }
    if(sub == 1)
    {
        for(i = 0; i < line; i++)
        {
            if( !strcmp(transkip[i].Cours,"Physics") || !strcmp(transkip[i].Cours,"Chemical") || !strcmp(transkip[i].Cours,"Biology"))
            {
                sumGC += (transkip[i].Grade *  transkip[i].Credit);
                sumC += transkip[i].Credit;
            }
        }
        puts("Sicne");
    }
    if(sub == 2)
    {
        if( !strcmp(transkip[i].Cours,"English") )
            {
                sumGC += (transkip[i].Grade *  transkip[i].Credit);
                sumC += transkip[i].Credit;
            }
        puts("English");
    }
    gpasub = sumGC/sumC;
    return gpasub;
}

double calculate_GPA(int line, struct data *transkip,int Trem)
{
    int valid=0;
    double gpa=0,sumGC=0,sumC=0;
    for(int i = 0; i<line ; i++)
    {
        if(!strcmp(transkip[i].Year,"2018") && !strcmp(transkip[i].Term,"1") && (Trem == 0))
        {
            valid=1;
        }
        else if (!strcmp(transkip[i].Year,"2018") && !strcmp(transkip[i].Term,"2") && (Trem == 1))
        {
            valid=1;
        }
        else if(!strcmp(transkip[i].Year,"2019") && !strcmp(transkip[i].Term,"1") && (Trem == 2))
        {
            valid=1;
        }
        else if (!strcmp(transkip[i].Year,"2019") && !strcmp(transkip[i].Term,"2") && (Trem == 3))
        {
            valid=1;
        }
        else if(!strcmp(transkip[i].Year,"2020") && !strcmp(transkip[i].Term,"1") && (Trem == 4))
        {
            valid=1;
        }
        else if ((!strcmp(transkip[i].Year,"2020") && !strcmp(transkip[i].Term,"2")) && (Trem == 5))
        {
            valid=1;
        }
        else
        {
            valid = 0;
        }
        
        if(valid==1)
        {
            sumGC += (transkip[i].Grade *  transkip[i].Credit);
            sumC += transkip[i].Credit;
        }
    }
    gpa = sumGC/sumC;
    return gpa;
}

int main()
{
    int line;
    line = checkLine();
    struct data transkip[line];
    FILE* inFile = NULL;
    char buffer[256];
    char *token;
    double gpa[6];
    double gpaMES[3];
    int j=0;
    int i=0;
    double GPAX;
    inFile = fopen("transkip.csv","r");
    if(inFile == NULL)
    {
        printf("Error opening file: \n");
        exit(1);
    }
    while (fgets(buffer,sizeof(buffer),inFile) != NULL)
    {
        token = strtok(buffer,",");
        i = 0;
        while (token != NULL) 
        {
            if(i == 0)
            {
                strcpy(transkip[j].Year,token);
            }
            
            if(i == 1)
            {
                strcpy(transkip[j].Term,token);
            }

            if(i == 2)
            {
                strcpy(transkip[j].Code,token);
            }

            if(i == 3)
            {
                strcpy(transkip[j].Cours,token);
            }

            if(i == 4)
            {
                sscanf(token,"%lf",&transkip[j].Credit);
            }

            if(i == 5)
            {
                sscanf(token,"%lf",&transkip[j].Grade);
            }
            token = strtok(NULL,",");
            i++;
        }
        j++;
    }
    GPAX = calculate_GPAX(line,transkip);
    for ( i = 0; i < 6; i++)
    {
        gpa[i] = calculate_GPA(line,transkip,i);
    }
    for ( i = 0; i < 3; i++)
    {
        gpaMES[i] = calculateSub(line,transkip,i);
    }
    
    printf("GPA M.4 TERM 1 = %.2f\n",gpa[0]);
    printf("GPA M.4 TERM 2 = %.2f\n",gpa[1]);
    printf("GPA M.5 TERM 1 = %.2f\n",gpa[2]);
    printf("GPA M.5 TERM 2 = %.2f\n",gpa[3]);
    printf("GPA M.6 TERM 1 = %.2f\n",gpa[4]);
    printf("GPA M.6 TERM 2 = %.2f\n",gpa[5]);
    printf("GPA Mathematics = %.2f\n",gpaMES[0]);
    printf("GPA Science = %.2f\n",gpaMES[1]);
    printf("GPA English = %.2f\n",gpaMES[2]);
    printf("GPAX = %.2f\n",GPAX); 
}