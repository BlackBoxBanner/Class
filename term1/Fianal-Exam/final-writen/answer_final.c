#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCOUNT 100
#define filename "info.dat"
#define myName "Taweechai Nuntawisuttiwong"

typedef struct{
    unsigned long long int id;
    char name[50];
    int num1;
    int num2;
}studentInfo;

int getStudent(studentInfo students[])
{
    FILE* inFile = NULL;
    int numStd;

    inFile = fopen(filename, "rb");
    if(inFile == NULL)
    {
        printf("Error: cannot open file %s.\n",filename);
        exit(1);
    }
    numStd = fread(students,sizeof(studentInfo),MAXCOUNT,inFile);
    fclose(inFile);

    return numStd;
}

void displayStudent(studentInfo students[],int numStd)
{
    int i;
    for(i=0;i<numStd;i++)
    {
        printf("%-2d) %llu %-30s %-3d %-3d\n",i+1,students[i].id,students[i].name,students[i].num1,students[i].num2);
    }
}

int searchID(studentInfo students[], studentInfo *myInfo, int numStd)
{
    int i;
    unsigned long long id;

    for(i=0;i<numStd;i++)
    {
        if(myInfo->id == students[i].id)
        {
            strcpy(myInfo->name,students[i].name);
            myInfo->num1 = students[i].num1;
            myInfo->num2 = students[i].num2;
            break;
        }
    }
    return i+1;
}

void exportInfo(studentInfo myInfo,int line)
{
    FILE* outFile = NULL;
    char textFile[20];
    int num3;

    sprintf(textFile,"%llu.txt",myInfo.id);
    outFile = fopen(textFile,"w");
    if(outFile == NULL)
    {
        printf("Error opening file: %s\n",outFile);
        exit(1);
    }
    num3 = 0.3*myInfo.num1+0.7*myInfo.num2;
    fprintf(outFile,"ID: %llu\nName: %s\nOld Name: %s\nNum1: %d\nNum2: %d\nNum3: %d\nLine: %d",myInfo.id,myName,myInfo.name,myInfo.num1,myInfo.num2,num3,line);
    fclose(outFile);
}

int main()
{
    studentInfo students[100];
    studentInfo myInfo;
    int numStd;
    int line;

    numStd = getStudent(students);
    printf("%d\n",numStd);
    displayStudent(students,numStd);

    studentInfo test[] = {{64070503440,"PAPHAWIN UTAKARUDA",95,85},{64070503420,"ANUTTHACHA KANPHIROM",77,52}};

    printf("%s\n",test[0].name);

    printf("Enter your student id: ");
    scanf("%llu",&myInfo.id);
    //printf("%llu\n",myInfo.id);
    line = searchID(students,&myInfo,numStd);
    printf("%d\n",line);
    printf("ID: %llu\nName: %s\nNum1: %d\nNum2: %d\n",myInfo.id,myInfo.name,myInfo.num1,myInfo.num2);
    exportInfo(myInfo,line);

    return 0;
}
