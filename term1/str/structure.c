#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 100

typedef struct
{
    int year;
    int term;
    char code[10];
    char courseName[50];
    float credit;
    float grade;
} course_info;

int readFile(char filename[], course_info course[])
{
    FILE* inFile = NULL;
    char buffer[256];
    char* token;
    int col,i=0;
    inFile = fopen("TRANSCRIPT.csv","r");

    if(inFile == NULL)
    {
        printf("Error opening file: file %s\n",filename);
        exit(1);
    }
    fgets(buffer,sizeof(buffer),inFile);
    while (fgets(buffer,sizeof(buffer),inFile) != NULL)
    {
        token = strtok(buffer,"," );
        col = 0;
        while (token) {
            switch(col){
                case 0: sscanf(token,"%d",&course[i].year);     break;
                case 1: sscanf(token,"%d",&course[i].term);     break;
                case 3: strcpy(course[i].courseName,token);     break;
                case 4: sscanf(token,"%f",&course[i].credit);   break;
                case 5: sscanf(token,"%f",&course[i].grade);    break;
            }
            token =strtok(NULL,",");
            col++;
        }
        i++;
    }
    fclose(inFile);
    printf("Number of records is %d.\n",i);
    return 1;
}

float calculateGPAX(int num, course_info course[])
{
    int i;
    float totalCredit = 0.0;
    float totalGrade = 0.0;

    for(i = 0; i < num; i++)
    {
        totalCredit += course[i].credit;
        totalGrade += course[i].credit*course[i].grade;
    }
    return totalGrade/totalCredit;
}

int main();
{
    char buffer[256];
    char filename[256];
    course_info course[100];
    int numCourse = 0;
    int i;
    float gpax,gpa;

    printf("What file do you want to read? ");
    fgets(buffer, sizeof(buffer),stdin);
    sscanf(buffer,"%s",filname);

    numCourse = readFile(filename,course);
    gpax = calculateGPAX(numCourse,course);
    printf("GPAX = %.2f\n",gpax);

    return 0;
}
